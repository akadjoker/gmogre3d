#include "Precompiled.hpp"
#include "InstanceArray.hpp"
#include "Instance.hpp"
#include "Functions/dll.hpp"
namespace gm
{
    GMAPI_DLL InstanceArray *instanceArray;
    Instance* InstanceArray::getIndex(int index)
    {
        assert(index >= 0 && index <= len);
        return instances[index];
    }
    Instance *InstanceArray::get(int id)
    {
        for(int index=0; index < len; ++index)
        {
            Instance *ins = getIndex(index);
            if(ins->id == id)
                return ins;
        }
        return 0;
    }
    int InstanceArray::getCount()
    {
        return len;
    }
    bool initInstanceArray()
    {
        //use the instance_exists assembly (since its a known "entry point"
        //to locate GM's instance array.
        char *p = (char*)(unsigned)gm::get_function_address("instance_exists").real;
        p += (0x00608480 - 0x006083DC) + 1;
        //Validation, to see if any of the assembly has changed that would
        //make the read value meaningless
        static const unsigned char BEFORE[] =
        {
            0x89, 0x45, 0xF8,
            0x83, 0x7D, 0xF8, 0xFD,
            0x75, 0x47,
            0xA1
        };
        static const unsigned char AFTER[] =
        {
            0x8B, 0x00,
            0x8B, 0x58, 0x68,
            0x4B,
            0x85, 0xDB
        };
        if(memcmp(BEFORE, p - sizeof(BEFORE), sizeof(BEFORE)) != 0)
            return false;
        if(memcmp(AFTER, p + 4, sizeof(AFTER)) != 0)
            return false;
        //Locate the instance array
        InstanceArray ****iapppp = (InstanceArray****)p;
        instanceArray = ***iapppp;
        
        return true;
    }
    /*
    00608477 89 45 F8             mov         dword ptr [ebp-8],eax  
    0060847A 83 7D F8 FD          cmp         dword ptr [ebp-8],0FFFFFFFDh  
    0060847E 75 47                jne         006084C7  
    00608480 A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    00608485 8B 00                mov         eax,dword ptr [eax]  
    00608487 8B 58 68             mov         ebx,dword ptr [eax+68h]  
    0060848A 4B                   dec         ebx  
    0060848B 85 DB                test        ebx,ebx  
    */
    /*
    006083DC 55                   push        ebp  
    006083DD 8B EC                mov         ebp,esp  
    006083DF 83 C4 F4             add         esp,0FFFFFFF4h  
    006083E2 53                   push        ebx  
    006083E3 56                   push        esi  
    006083E4 57                   push        edi  
    006083E5 89 55 FC             mov         dword ptr [ebp-4],edx  
    006083E8 8B F8                mov         edi,eax  
    006083EA 8B 75 08             mov         esi,dword ptr [ebp+8]  
    006083ED 8B 5D 10             mov         ebx,dword ptr [ebp+10h]  
    006083F0 33 C0                xor         eax,eax  
    006083F2 89 06                mov         dword ptr [esi],eax  
    006083F4 DD 43 08             fld         qword ptr [ebx+8]  
    006083F7 E8 BC C4 DF FF       call        004048B8  
    006083FC 83 FA FF             cmp         edx,0FFFFFFFFh  
    006083FF 75 2A                jne         0060842B  
    00608401 83 F8 FF             cmp         eax,0FFFFFFFFh  
    00608404 75 25                jne         0060842B  
    00608406 85 FF                test        edi,edi  
    00608408 74 09                je          00608413  
    0060840A 80 BF 08 01 00 00 00 cmp         byte ptr [edi+108h],0  
    00608411 74 04                je          00608417  
    00608413 33 C0                xor         eax,eax  
    00608415 EB 02                jmp         00608419  
    00608417 B0 01                mov         al,1  
    00608419 0F BE C0             movsx       eax,al  
    0060841C 89 45 F4             mov         dword ptr [ebp-0Ch],eax  
    0060841F DB 45 F4             fild        dword ptr [ebp-0Ch]  
    00608422 DD 5E 08             fstp        qword ptr [esi+8]  
    00608425 9B                   wait  
    00608426 E9 41 01 00 00       jmp         0060856C  
    0060842B DD 43 08             fld         qword ptr [ebx+8]  
    0060842E E8 85 C4 DF FF       call        004048B8  
    00608433 83 FA FF             cmp         edx,0FFFFFFFFh  
    00608436 75 2F                jne         00608467  
    00608438 83 F8 FE             cmp         eax,0FFFFFFFEh  
    0060843B 75 2A                jne         00608467  
    0060843D 83 7D FC 00          cmp         dword ptr [ebp-4],0  
    00608441 74 0C                je          0060844F  
    00608443 8B 45 FC             mov         eax,dword ptr [ebp-4]  
    00608446 80 B8 08 01 00 00 00 cmp         byte ptr [eax+108h],0  
    0060844D 74 04                je          00608453  
    0060844F 33 C0                xor         eax,eax  
    00608451 EB 02                jmp         00608455  
    00608453 B0 01                mov         al,1  
    00608455 0F BE C0             movsx       eax,al  
    00608458 89 45 F4             mov         dword ptr [ebp-0Ch],eax  
    0060845B DB 45 F4             fild        dword ptr [ebp-0Ch]  
    0060845E DD 5E 08             fstp        qword ptr [esi+8]  
    00608461 9B                   wait  
    00608462 E9 05 01 00 00       jmp         0060856C  
    00608467 33 C0                xor         eax,eax  
    00608469 89 46 08             mov         dword ptr [esi+8],eax  
    0060846C 89 46 0C             mov         dword ptr [esi+0Ch],eax  
    0060846F DD 43 08             fld         qword ptr [ebx+8]  
    00608472 E8 41 C4 DF FF       call        004048B8  
    00608477 89 45 F8             mov         dword ptr [ebp-8],eax  
    0060847A 83 7D F8 FD          cmp         dword ptr [ebp-8],0FFFFFFFDh  
    0060847E 75 47                jne         006084C7  
    00608480 A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    00608485 8B 00                mov         eax,dword ptr [eax]  
    00608487 8B 58 68             mov         ebx,dword ptr [eax+68h]  
    0060848A 4B                   dec         ebx  
    0060848B 85 DB                test        ebx,ebx  
    0060848D 0F 8C D9 00 00 00    jl          0060856C  
    00608493 43                   inc         ebx  
    00608494 33 FF                xor         edi,edi  
    00608496 A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    0060849B 8B 00                mov         eax,dword ptr [eax]  
    0060849D 8B D7                mov         edx,edi  
    0060849F E8 B0 FE FC FF       call        005D8354  
    006084A4 80 B8 08 01 00 00 00 cmp         byte ptr [eax+108h],0  
    006084AB 75 11                jne         006084BE  
    006084AD 33 C0                xor         eax,eax  
    006084AF 89 46 08             mov         dword ptr [esi+8],eax  
    006084B2 C7 46 0C 00 00 F0 3F mov         dword ptr [esi+0Ch],3FF00000h  
    006084B9 E9 AE 00 00 00       jmp         0060856C  
    006084BE 47                   inc         edi  
    006084BF 4B                   dec         ebx  
    006084C0 75 D4                jne         00608496  
    006084C2 E9 A5 00 00 00       jmp         0060856C  
    006084C7 81 7D F8 A0 86 01 00 cmp         dword ptr [ebp-8],186A0h  
    006084CE 7D 4B                jge         0060851B  
    006084D0 A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    006084D5 8B 00                mov         eax,dword ptr [eax]  
    006084D7 8B 55 F8             mov         edx,dword ptr [ebp-8]  
    006084DA E8 95 17 FD FF       call        005D9C74  
    006084DF 8B D8                mov         ebx,eax  
    006084E1 4B                   dec         ebx  
    006084E2 85 DB                test        ebx,ebx  
    006084E4 0F 8C 82 00 00 00    jl          0060856C  
    006084EA 43                   inc         ebx  
    006084EB 33 FF                xor         edi,edi  
    006084ED A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    006084F2 8B 00                mov         eax,dword ptr [eax]  
    006084F4 8B CF                mov         ecx,edi  
    006084F6 8B 55 F8             mov         edx,dword ptr [ebp-8]  
    006084F9 E8 A2 17 FD FF       call        005D9CA0  
    006084FE 80 B8 08 01 00 00 00 cmp         byte ptr [eax+108h],0  
    00608505 75 0E                jne         00608515  
    00608507 33 C0                xor         eax,eax  
    00608509 89 46 08             mov         dword ptr [esi+8],eax  
    0060850C C7 46 0C 00 00 F0 3F mov         dword ptr [esi+0Ch],3FF00000h  
    00608513 EB 57                jmp         0060856C  
    00608515 47                   inc         edi  
    00608516 4B                   dec         ebx  
    00608517 75 D4                jne         006084ED  
    00608519 EB 51                jmp         0060856C  
    0060851B A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    00608520 8B 00                mov         eax,dword ptr [eax]  
    00608522 8B 58 68             mov         ebx,dword ptr [eax+68h]  
    00608525 4B                   dec         ebx  
    00608526 85 DB                test        ebx,ebx  
    00608528 7C 42                jl          0060856C  
    0060852A 43                   inc         ebx  
    0060852B 33 FF                xor         edi,edi  
    0060852D A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    00608532 8B 00                mov         eax,dword ptr [eax]  
    00608534 8B D7                mov         edx,edi  
    00608536 E8 19 FE FC FF       call        005D8354  
    0060853B 80 B8 08 01 00 00 00 cmp         byte ptr [eax+108h],0  
    00608542 75 24                jne         00608568  
    00608544 A1 84 53 68 00       mov         eax,dword ptr ds:[00685384h]  
    00608549 8B 00                mov         eax,dword ptr [eax]  
    0060854B 8B D7                mov         edx,edi  
    0060854D E8 02 FE FC FF       call        005D8354  
    00608552 8B 40 04             mov         eax,dword ptr [eax+4]  
    00608555 3B 45 F8             cmp         eax,dword ptr [ebp-8]  
    00608558 75 0E                jne         00608568  
    0060855A 33 C0                xor         eax,eax  
    0060855C 89 46 08             mov         dword ptr [esi+8],eax  
    0060855F C7 46 0C 00 00 F0 3F mov         dword ptr [esi+0Ch],3FF00000h  
    00608566 EB 04                jmp         0060856C  
    00608568 47                   inc         edi  
    00608569 4B                   dec         ebx  
    0060856A 75 C1                jne         0060852D  
    0060856C 5F                   pop         edi  
    0060856D 5E                   pop         esi  
    0060856E 5B                   pop         ebx  
    0060856F 8B E5                mov         esp,ebp  
    00608571 5D                   pop         ebp  
    00608572 C2 0C 00             ret         0Ch  
    */
}
