;************************************************************************** 
;  LICENSE:
;
;    GMAPI is free software; you can redistribute it and/or
;    modify it under the terms of the GNU Lesser General Public
;    License as published by the Free Software Foundation; either
;    version 2.1 of the License, or (at your option) any later version.
;
;    GMAPI is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;    Lesser General Public License for more details.
;
;    You should have received a copy of the GNU Lesser General Public
;    License along with GMAPI; if not, write to the Free Software
;    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
;    02110-1301 USA
;***************************************************************************
; main.asm
;
; Copyright 2009 (C) Snake (http://sgames.ovh.org/)
;***************************************************************************

.386

.model flat, stdcall

option casemap:none

include kernel32.inc
includelib kernel32.lib

GMAPI_DATA struct ; GMAPI_HOOK_DATA_BASE points to that structure, it is embedded
                  ; in PE header (in process memory)
                  
  referenceCount DWORD ?
  thisInstance   DWORD ?
  withInstance   DWORD ?
  returnAddress  DWORD ?
GMAPI_DATA ends

GM61_RUNNER_STRING_CLASS      equ 00401098h
GM61_RUNNER_RVALUE_CLASS      equ 004F6BF8h
GM61_RUNNER_ALLOCATE          equ 00405E7Ch
GM61_RUNNER_SET_STRING        equ 00405150h
GM61_RUNNER_CLEAR_STRING      equ 00404F58h
GM61_RUNNER_DEALLOCATE        equ 00405E90h
GM61_RUNNER_DEALLOCATE_RESULT equ 00405A08h
GM61_RUNNER_DEALLOCATE_BITMAP equ 0040274Ch
GM61_RUNNER_EXTERNAL_CALL     equ 0051C3A0h
GM61_RUNNER_EXTERNAL_CALL_RET equ 0051C3A9h
GM61_RUNNER_FIND_SYMBOL_ID    equ 004D4E88h

GMAPI_HOOK_DATA_BASE          equ 00400800h
GMAPI_HOOK_DATA_CODE          equ 00400900h
GMAPI_HOOK_DATA_PREVCODE      equ 00400A00h

GM_SIGNATURE                  equ 00401041h
GM70_ID                       equ 08h
GM61_ID                       equ 07h

.data

RUNNER_STRING_CLASS      dd 004010D0h
RUNNER_RVALUE_CLASS      dd 005457F8h

RUNNER_ALLOCATE_STRING   dd 00405ECCh
RUNNER_SET_STRING        dd 004051A0h
RUNNER_CLEAR_STRING      dd 00404FA8h
RUNNER_DEALLOCATE_STRING dd 00405EE0h
RUNNER_DEALLOCATE_RESULT dd 00405A58h
RUNNER_DEALLOCATE_BITMAP dd 00402794h
RUNNER_EXTERNAL_CALL     dd 00569328h
RUNNER_EXTERNAL_CALL_RET dd 00569331h
RUNNER_FIND_SYMBOL_ID    dd 0052A310h

.code

GMAPIInitialize proc

  xor    eax, eax
  mov    dl, byte ptr ds:[GM_SIGNATURE]
  
  ; Check GM7 sig
  cmp    dl, GM70_ID
  jne    CheckGM61
  
  ; All contants are already initialized to GM7 so set return value only
  
  mov    eax, 70
  jmp    ProcExit

CheckGM61:

  cmp    dl, GM61_ID
  jne    ProcExit
  
  ; Modify addresses
  mov    eax, offset RUNNER_STRING_CLASS
  mov    dword ptr ds:[eax],     GM61_RUNNER_STRING_CLASS
  mov    dword ptr ds:[eax+4h],  GM61_RUNNER_RVALUE_CLASS
  mov    dword ptr ds:[eax+8h],  GM61_RUNNER_ALLOCATE
  mov    dword ptr ds:[eax+0Ch], GM61_RUNNER_SET_STRING
  mov    dword ptr ds:[eax+10h], GM61_RUNNER_CLEAR_STRING
  mov    dword ptr ds:[eax+14h], GM61_RUNNER_DEALLOCATE
  mov    dword ptr ds:[eax+18h], GM61_RUNNER_DEALLOCATE_RESULT
  mov    dword ptr ds:[eax+1Ch], GM61_RUNNER_DEALLOCATE_BITMAP  
  mov    dword ptr ds:[eax+20h], GM61_RUNNER_EXTERNAL_CALL
  mov    dword ptr ds:[eax+24h], GM61_RUNNER_EXTERNAL_CALL_RET
  mov    dword ptr ds:[eax+28h], GM61_RUNNER_FIND_SYMBOL_ID

  mov    eax, 61

ProcExit:

  ret
GMAPIInitialize endp

;******************************************
; GMAllocateString
; - Allocates delphi string from GM runner
;******************************************

GMAllocateString proc uses edx ebx
  mov     edx, RUNNER_STRING_CLASS
  mov     eax, 4h
  call    RUNNER_ALLOCATE_STRING

  ret
GMAllocateString endp

;******************************************
; GMDeallocateString
; - Frees delphi string
;******************************************

GMDeallocateString proc uses edx aPtrString:DWORD 
  mov     edx, RUNNER_STRING_CLASS
  mov     eax, aPtrString
  call    RUNNER_DEALLOCATE_STRING

  ret
GMDeallocateString endp

;******************************************
; GMDeallocateResult
; - Frees GM result structure
;******************************************

GMDeallocateResult proc uses edx aPtrResultStruct:DWORD 
  mov     eax, aPtrResultStruct
  mov     edx, RUNNER_RVALUE_CLASS
  call    RUNNER_DEALLOCATE_RESULT

  ret
GMDeallocateResult endp

;******************************************
; GMDeallocateBitmap
; - Releases GM bitmap from memory
;******************************************

GMDeallocateBitmap proc uses ecx edx aPtrBitmap:DWORD
  mov     eax, aPtrBitmap
  call    RUNNER_DEALLOCATE_BITMAP
  ret
GMDeallocateBitmap EndP

;******************************************
; GMSetString
; - Sets delphi string
;******************************************

GMSetString proc uses edx ebx aString:DWORD, aPtrString:DWORD
  mov     eax, aPtrString
  mov     ebx, eax
  mov     edx, aString
  call    RUNNER_SET_STRING

  ret
GMSetString endp

;******************************************
; GMClearString
; - Clears delphi string
;******************************************

GMClearString proc aPtrString:DWORD
  mov     eax, aPtrString
  call    RUNNER_CLEAR_STRING

  ret
GMClearString endp

;******************************************
; GMCallFunction
; - Calls GM function from runner
;******************************************

GMCallFunction proc uses ecx aFunctionPtr:DWORD, aArgArr:DWORD, aArgCount:DWORD, aPtrResult:DWORD 
  assume  eax: ptr GMAPI_DATA

  mov     eax, GMAPI_HOOK_DATA_BASE
  mov     edx, [eax].thisInstance    ; Get instance from which dll function was called
  mov     eax, [eax].withInstance    ; Get instance with which the code will be executed
  mov     ecx, aArgCount             ; Number of arguments passed to function
  push    aArgArr                    ; Pointer to array which stores parameters for called function
  push    0Fh                        ; Max number of arguments - always set to 15, cause' there's no need for any checks
  push    aPtrResult                 ; Pointer to structure that'll receive function result 
  call    aFunctionPtr               ; Call GM function

  ret
GMCallFunction endp

;******************************************
; GMFindSymbolID
; - Finds symbol identifier by which the variables are identified
;******************************************

GMFindSymbolID proc uses ecx edx aVariableName:DWORD
  mov     eax, aVariableName
  call    RUNNER_FIND_SYMBOL_ID

  ret
GMFindSymbolID EndP

;******************************************
; FlushCache
; - Flushes instruction cache after modifying runner's code
;******************************************

FlushCache proc
  push   09h
  push   RUNNER_EXTERNAL_CALL
  call   [GetCurrentProcess]
  push   eax
  call   [FlushInstructionCache]

  push   100h
  push   GMAPI_HOOK_DATA_CODE
  call   [GetCurrentProcess]
  push   eax
  call   [FlushInstructionCache]

  ret
FlushCache endp

;******************************************
; GMAPIHookInstall
; - extends external_call function, by adding code that retrieves current instance pointers
;******************************************

GMAPIHookInstall proc uses ecx esi edi
  cmp    dword ptr ds:[GMAPI_HOOK_DATA_BASE], 0 ; Check reference count
  jne    ProcExit ; if it's equal to zero then install the hook

  ; Gain write access to external_call code
  push   0                      ; For oldProtect
  push   esp                    ; Arg4 - oldProtect; (push address of oldProtect variable)
  push   40h                    ; Arg3 - newProtect; (PAGE_EXECUTE_READWRITE)
  push   09h                    ; Arg2 - memory block size
  push   RUNNER_EXTERNAL_CALL   ; Arg4 - address; (external_call address)
  call   [VirtualProtect]
  
  ; to cave in PE header
  push   esp                    ; Arg4 - oldProtect; (push address of oldProtect variable)
  push   40h                    ; Arg3 - newProtect; (PAGE_EXECUTE_READWRITE)
  push   200h                   ; Arg2 - memory block size
  push   GMAPI_HOOK_DATA_BASE   ; Arg4 - address
  call   [VirtualProtect]

  pop    eax

  ; Save original external_call code
  cld
  mov    esi, RUNNER_EXTERNAL_CALL
  mov    edi, GMAPI_HOOK_DATA_PREVCODE
  mov    ecx, 09h
  rep movsb
  
  ; Modify external_call function prologue - jump to GMAPIHook
  add    ecx, 09h
  lea    edi, dword ptr ds:[esi-09h]
  mov    esi, HookDetour
  rep movsb
  
  ; Inject hook code into codecave
  mov    ecx, 100h
  mov    esi, HookCode
  mov    edi, GMAPI_HOOK_DATA_CODE
  rep movsb
  
  ; Set return address
  push   RUNNER_EXTERNAL_CALL_RET
  pop    dword ptr ds:[GMAPI_HOOK_DATA_BASE+0Ch]
  
  call   FlushCache
  
ProcExit:
  inc    dword ptr ds:[GMAPI_HOOK_DATA_BASE]
  
  ret
  
  ;******************************************
  ; Hook codes, detour and injection
  ; those couldn't be in seperate subroutines - code compiled
  ; in "DEBUG" mode modifies references to proc. addresses
  
  HookDetour:
    push  GMAPI_HOOK_DATA_CODE
    jmp   dword ptr ds:[esp]   ; jump to absolute address :F
    nop
    nop
    nop
  
  HookCode:
    add    esp, 4
  
    ; Create stack frame
    push   ebp
    mov    ebp, esp
    add    esp, -1A0h ; GM7 local data storage

    ; Check if it's GM6
    cmp    byte ptr ds:[GM_SIGNATURE], GM61_ID
    jne    Skip
  
    add    esp, 60    ; GM6.1 local variable space == 140h
    ; ---------------------------------------------------
  
  Skip:
  
    ; Save current instance pointers
    mov    dword ptr ds:[GMAPI_HOOK_DATA_BASE+08h], eax ; Instance set by "with" statement or sth
    mov    dword ptr ds:[GMAPI_HOOK_DATA_BASE+04h], edx ; "This" instance
    jmp    dword ptr ds:[GMAPI_HOOK_DATA_BASE+0Ch]      ; jmp to returnAddress
    
  ;******************************************

GMAPIHookInstall endp

;******************************************
; GMAPIHookUninstall
; - undo changes made with GMAPIHookInstall function
;******************************************

GMAPIHookUninstall proc uses ecx
  dec    dword ptr ds:[GMAPI_HOOK_DATA_BASE]
  jnz    ProcExit ; if there's still references then exit. Otherwise, restore modified data in runner.

  push   esi
  push   edi

  ; Restore external_call code
  cld
  mov    esi, GMAPI_HOOK_DATA_PREVCODE
  mov    edi, RUNNER_EXTERNAL_CALL
  mov    ecx, 09h
  rep movsb
  
  pop    edi
  pop    esi

  call   FlushCache
  
ProcExit:
  jns    Return   ; if ref count is negative
  
  inc    dword ptr ds:[GMAPI_HOOK_DATA_BASE]
  
Return:  

  ret
GMAPIHookUninstall endp

end
