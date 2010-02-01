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
; Copyright 2009-2010 (C) Snake (http://sgames.ovh.org/)
;***************************************************************************

.386
.model flat, stdcall

option casemap:none

include kernel32.inc
includelib kernel32.lib

GMAPI_DATA struct ; GMAPI_HOOK_DATA_BASE constant points to that structure, it is embedded
                  ; in PE header (in process memory)

  referenceCount DWORD ?
  selfInstance   DWORD ?
  otherInstance  DWORD ?
  returnAddress  DWORD ?
GMAPI_DATA ends

GMAPI_HOOK_DATA_BASE                 equ 00400800h
GMAPI_HOOK_DATA_CODE                 equ 00400900h
GMAPI_HOOK_DATA_PREVCODE             equ 00400A00h

GM_SIGNATURE                         equ 00500000h

GM80_ID                              equ 0E982754Fh
GM70_ID                              equ 00589A24h
GM61_ID                              equ 0E8005386h

GM61_RUNNER_CLASS_STRING             equ 00401098h
GM61_RUNNER_CLASS_RVALUE             equ 004F6BF8h
GM61_RUNNER_STRING_ALLOCATE          equ 00405E7Ch
GM61_RUNNER_STRING_SET               equ 00404FACh
GM61_RUNNER_STRING_SETFROMPCHAR      equ 00405150h
GM61_RUNNER_STRING_CLEAR             equ 00404F58h
GM61_RUNNER_STRING_DEALLOCATE        equ 00405E90h
GM61_RUNNER_RESULT_DEALLOCATE        equ 00405A08h
GM61_RUNNER_ADDR_EXTERNALCALL        equ 0051C3A0h
GM61_RUNNER_ADDR_EXTERNALCALL_RETURN equ 0051C3ACh
GM61_RUNNER_UTILITY_FINDSYMBOLID     equ 004D4E88h
GM61_RUNNER_UTILITY_GMFUNCTIONADDER  equ 004D7CACh

GM70_RUNNER_CLASS_STRING             equ 004010D0h
GM70_RUNNER_CLASS_RVALUE             equ 005457F8h
GM70_RUNNER_STRING_ALLOCATE          equ 00405ECCh
GM70_RUNNER_STRING_SET               equ 00404FFCh
GM70_RUNNER_STRING_SETFROMPCHAR      equ 004051A0h
GM70_RUNNER_STRING_CLEAR             equ 00404FA8h
GM70_RUNNER_STRING_DEALLOCATE        equ 00405EE0h
GM70_RUNNER_RESULT_DEALLOCATE        equ 00405A58h
GM70_RUNNER_ADDR_EXTERNALCALL        equ 00569328h
GM70_RUNNER_ADDR_EXTERNALCALL_RETURN equ 00569334h
GM70_RUNNER_UTILITY_FINDSYMBOLID     equ 0052A310h
GM70_RUNNER_UTILITY_GMFUNCTIONADDER  equ 0052D204h

.data
; Initialized to GM8
RUNNER_CLASS_STRING             dd 004010D0h
RUNNER_CLASS_RVALUE             dd 005436F4h
RUNNER_STRING_ALLOCATE          dd 0040695Ch
RUNNER_STRING_SET               dd 00405988h
RUNNER_STRING_SETFROMPCHAR      dd 00405B2Ch
RUNNER_STRING_CLEAR             dd 00405934h
RUNNER_STRING_DEALLOCATE        dd 00406970h
RUNNER_RESULT_DEALLOCATE        dd 004064E8h
RUNNER_ADDR_EXTERNALCALL        dd 00568AF0h
RUNNER_ADDR_EXTERNALCALL_RETURN dd 00568AFCh
RUNNER_UTILITY_FINDSYMBOLID     dd 005263D8h
RUNNER_UTILITY_GMFUNCTIONADDER  dd 0052939Ch

EXTERNAL_CALL_LOCALSPACE        dd 19Ch

.code

;**********************************************************************
; GMAPIInitialize
; - Initializes pointers and determines runner version
;**********************************************************************

GMAPIInitialize proc
  xor    eax, eax
  mov    edx, dword ptr ds:[GM_SIGNATURE]
  
  ; Check GM8 signature
  cmp    edx, GM80_ID
  jne    CheckGM70
    ; All contants are already initialized to GM8 so set return value only
    mov    eax, 80
    
  jmp    ProcExit
 
CheckGM70:
  ; Check GM7 signature
  cmp    edx, GM70_ID
  jne    CheckGM61
    ; Modify addresses
    mov    eax, offset RUNNER_CLASS_STRING
    mov    dword ptr ds:[eax],       GM70_RUNNER_CLASS_STRING
    mov    dword ptr ds:[eax + 04h], GM70_RUNNER_CLASS_RVALUE
    mov    dword ptr ds:[eax + 08h], GM70_RUNNER_STRING_ALLOCATE
    mov    dword ptr ds:[eax + 0Ch], GM70_RUNNER_STRING_SET
    mov    dword ptr ds:[eax + 10h], GM70_RUNNER_STRING_SETFROMPCHAR
    mov    dword ptr ds:[eax + 14h], GM70_RUNNER_STRING_CLEAR
    mov    dword ptr ds:[eax + 18h], GM70_RUNNER_STRING_DEALLOCATE
    mov    dword ptr ds:[eax + 1Ch], GM70_RUNNER_RESULT_DEALLOCATE
    mov    dword ptr ds:[eax + 20h], GM70_RUNNER_ADDR_EXTERNALCALL
    mov    dword ptr ds:[eax + 24h], GM70_RUNNER_ADDR_EXTERNALCALL_RETURN
    mov    dword ptr ds:[eax + 28h], GM70_RUNNER_UTILITY_FINDSYMBOLID
    mov    dword ptr ds:[eax + 2Ch], GM70_RUNNER_UTILITY_GMFUNCTIONADDER
  
    mov    EXTERNAL_CALL_LOCALSPACE, 1A0h
    mov    eax, 70
    jmp    ProcExit

CheckGM61:

  cmp    edx, GM61_ID
  jne    ProcExit
    ; Modify addresses
    mov    eax, offset RUNNER_CLASS_STRING
    mov    dword ptr ds:[eax],       GM61_RUNNER_CLASS_STRING
    mov    dword ptr ds:[eax + 04h], GM61_RUNNER_CLASS_RVALUE
    mov    dword ptr ds:[eax + 08h], GM61_RUNNER_STRING_ALLOCATE
    mov    dword ptr ds:[eax + 0Ch], GM61_RUNNER_STRING_SET
    mov    dword ptr ds:[eax + 10h], GM61_RUNNER_STRING_SETFROMPCHAR
    mov    dword ptr ds:[eax + 14h], GM61_RUNNER_STRING_CLEAR
    mov    dword ptr ds:[eax + 18h], GM61_RUNNER_STRING_DEALLOCATE
    mov    dword ptr ds:[eax + 1Ch], GM61_RUNNER_RESULT_DEALLOCATE
    mov    dword ptr ds:[eax + 20h], GM61_RUNNER_ADDR_EXTERNALCALL
    mov    dword ptr ds:[eax + 24h], GM61_RUNNER_ADDR_EXTERNALCALL_RETURN
    mov    dword ptr ds:[eax + 28h], GM61_RUNNER_UTILITY_FINDSYMBOLID
    mov    dword ptr ds:[eax + 2Ch], GM61_RUNNER_UTILITY_GMFUNCTIONADDER
  
    mov    EXTERNAL_CALL_LOCALSPACE, 140h
    mov    eax, 61

ProcExit:

  ret
GMAPIInitialize endp

;**********************************************************************
; DelphiStringAllocate
; - Allocates delphi string using GM runner
;**********************************************************************

DelphiStringAllocate proc uses edx ebx
  mov     edx, RUNNER_CLASS_STRING
  mov     eax, 04h
  call    [RUNNER_STRING_ALLOCATE]

  ret
DelphiStringAllocate endp

;**********************************************************************
; DelphiStringDeallocate
; - Frees specifed delphi string
;**********************************************************************

DelphiStringDeallocate proc uses edx aPtrString:DWORD 
  mov     edx, RUNNER_CLASS_STRING
  mov     eax, aPtrString
  call    [RUNNER_STRING_DEALLOCATE]

  ret
DelphiStringDeallocate endp

;**********************************************************************
; DelphiStringSetFromPChar
; - Sets contents of specifed delphi string using c-string
;**********************************************************************

DelphiStringSetFromPChar proc uses edx ebx aString:DWORD, aPtrString:DWORD
  mov     eax, aPtrString
  mov     ebx, eax
  mov     edx, aString
  call    [RUNNER_STRING_SETFROMPCHAR]

  ret
DelphiStringSetFromPChar endp

;**********************************************************************
; DelphiStringSet
; - Sets contents of specifed delphi string using delphi string
;**********************************************************************

DelphiStringSet proc uses edx ebx aSrcString:DWORD, aDestString:DWORD
  mov     eax, aDestString
  mov     ebx, eax
  mov     edx, aSrcString
  call    [RUNNER_STRING_SET]

  ret
DelphiStringSet endp

;**********************************************************************
; DelphiStringClear
; - Clears specified delphi string
;**********************************************************************

DelphiStringClear proc aPtrString:DWORD
  mov     eax, aPtrString
  call    RUNNER_STRING_CLEAR

  ret
DelphiStringClear endp

;**********************************************************************
; RunnerDeallocateResult
; - Frees GM result value
;**********************************************************************

RunnerDeallocateResult proc uses edx aPtrResultStruct:DWORD 
  mov     eax, aPtrResultStruct
  mov     edx, RUNNER_CLASS_RVALUE
  call    [RUNNER_RESULT_DEALLOCATE]

  ret
RunnerDeallocateResult endp

;**********************************************************************
; GMCallFunction
; - Calls GM function from GM runner
;**********************************************************************

RunnerCallFunction proc uses ecx aFunctionPtr:DWORD, aArgArr:DWORD, aArgCount:DWORD, aPtrResult:DWORD 
  assume  eax: ptr GMAPI_DATA

  mov     eax, GMAPI_HOOK_DATA_BASE
  mov     edx, [eax].selfInstance    ; Get "self" instance
  mov     eax, [eax].otherInstance   ; Get "other" instance
  mov     ecx, aArgCount             ; Number of arguments passed to the function
  push    aArgArr                    ; Pointer to array which stores parameters for called function
  push    0Fh                        ; Maximal allowed number of arguments for a function - always set to 15
  push    aPtrResult                 ; Pointer to structure that'll receive function result
  call    [aFunctionPtr]             ; Call GM function

  ret
RunnerCallFunction endp

;**********************************************************************
; GMFindSymbolID
; - Finds symbol identifier by which the variables are identified
;**********************************************************************

RunnerFindSymbolID proc uses ecx edx aVariableName:DWORD
  mov     eax, aVariableName
  call    [RUNNER_UTILITY_FINDSYMBOLID]

  ret
RunnerFindSymbolID endp

;**********************************************************************
; RunnerGMFunctionAdd
; - Finds symbol identifier by which the variables are identified
;**********************************************************************

RunnerGMFunctionAdd proc uses ecx edx aFunctionName:DWORD, aNumberOfArguments:DWORD, aFunctionAddress:DWORD
  push   1
  mov    eax, aFunctionName
  mov    edx, aFunctionAddress
  mov    ecx, aNumberOfArguments
  call   [RUNNER_UTILITY_GMFUNCTIONADDER]

  ret
RunnerGMFunctionAdd endp

;**********************************************************************
; FlushCache
; - Flushes instruction cache after modifying runner's code
;**********************************************************************

FlushCache proc
  push   09h
  push   RUNNER_ADDR_EXTERNALCALL
  call   [GetCurrentProcess]
  push   eax
  call   [FlushInstructionCache]

  push   20h
  push   GMAPI_HOOK_DATA_CODE
  call   [GetCurrentProcess]
  push   eax
  call   [FlushInstructionCache]

  ret
FlushCache endp

;**********************************************************************
; GMAPIHookInstall
; - extends external_call function by adding code that retrieves
;   self & other instance pointers
;**********************************************************************

GMAPIHookInstall proc uses ecx esi edi
  cmp    dword ptr ds:[GMAPI_HOOK_DATA_BASE], 0 ; Check reference count
  jne    ProcExit ; if it's equal to zero then install the hook

  ; Gain write access to external_call code
  sub    esp, 4                   ; For oldProtect
  push   esp                      ; Arg4 - oldProtect; (push address of oldProtect variable)
  push   40h                      ; Arg3 - newProtect; (PAGE_EXECUTE_READWRITE)
  push   09h                      ; Arg2 - memory block size
  push   RUNNER_ADDR_EXTERNALCALL ; Arg1 - address; (external_call address)
  call   [VirtualProtect]
  
  ; to cave in PE header
  push   esp                    ; Arg4 - oldProtect; (push address of oldProtect variable)
  push   40h                    ; Arg3 - newProtect; (PAGE_EXECUTE_READWRITE)
  push   200h                   ; Arg2 - memory block size
  push   GMAPI_HOOK_DATA_BASE   ; Arg1 - address
  call   [VirtualProtect]

  pop    eax

  ; Save original external_call code
  cld
  mov    esi, RUNNER_ADDR_EXTERNALCALL
  mov    edi, GMAPI_HOOK_DATA_PREVCODE
  mov    ecx, 09h
  rep movsb
  
  ; Modify external_call function prologue - jump to GMAPIHook
  mov    ecx, 09h
  mov    edi, RUNNER_ADDR_EXTERNALCALL
  mov    esi, HookDetour
  rep movsb
  
  ; Inject hook code into codecave
  mov    ecx, 20h
  mov    esi, HookCode
  mov    edi, GMAPI_HOOK_DATA_CODE
  rep movsb
  
  ; Modify "sub esp, BAADC0DE" opcode
  push   EXTERNAL_CALL_LOCALSPACE
  pop    dword ptr ds:[GMAPI_HOOK_DATA_CODE + 08h]
  
  ; Set return address
  push   RUNNER_ADDR_EXTERNALCALL_RETURN
  pop    dword ptr ds:[GMAPI_HOOK_DATA_BASE + 0Ch]
  
  call   FlushCache
  
ProcExit:
  inc    dword ptr ds:[GMAPI_HOOK_DATA_BASE]
  
  ret
  
  ;**********************************************************************
  ; Hook codes, detour and injection
  ;  - those couldn't be defined in seperate subroutines - code compiled
  ;    in "DEBUG" mode modifies references to proc. addresses
  ; *********************************************************************
  
  HookDetour:
    push  GMAPI_HOOK_DATA_CODE
    jmp   dword ptr ds:[esp]   ; jump to absolute address :F

  HookCode:
    add    esp, 4
  
    ; Stack frame
    push   ebp
    mov    ebp, esp
    sub    esp, 0BAADC0DEh
    
    push   ebx
    push   esi
    push   edi
    
    ; Save current instance pointers
    mov    dword ptr ds:[GMAPI_HOOK_DATA_BASE + 04h], edx ; "Self" instance
    mov    dword ptr ds:[GMAPI_HOOK_DATA_BASE + 08h], eax ; "Other" instance
    jmp    dword ptr ds:[GMAPI_HOOK_DATA_BASE + 0Ch]      ; jmp to returnAddress
    
  ;******************************************

GMAPIHookInstall endp

;**********************************************************************
; GMAPIHookUninstall
; - undo changes made with GMAPIHookInstall function
;**********************************************************************

GMAPIHookUninstall proc uses ecx
  dec    dword ptr ds:[GMAPI_HOOK_DATA_BASE]
  jnz    ProcExit ; if there are still references then exit. Otherwise, restore modified data in the runner.
    push   esi
    push   edi

    ; Restore external_call code
    cld
    mov    esi, GMAPI_HOOK_DATA_PREVCODE
    mov    edi, RUNNER_ADDR_EXTERNALCALL
    mov    ecx, 09h
    rep movsb
  
    pop    edi
    pop    esi

    call   FlushCache

ProcExit:
  jns    Return   ; if reference count is negative
    inc    dword ptr ds:[GMAPI_HOOK_DATA_BASE]
  
Return:
  ret
GMAPIHookUninstall endp

end
