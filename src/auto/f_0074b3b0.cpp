// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) matches exact Lua and database query instruction stream
struct lua_State;

extern "C" {
    void __cdecl _lua_pushstring(lua_State*, const char*);
    int  __cdecl lua_gettop(lua_State*);
    void __cdecl _lua_createtable(lua_State*, int, int);
    void __cdecl _lua_rawset(lua_State*, int);
    void __cdecl _lua_pushvalue(lua_State*, int);
    void __cdecl lua_rawseti(lua_State*, int, int);

    extern const char aDisplayName[];
    extern const char aType[];
    extern const char aPath[];
    extern const char aSelectTypeDisplayNamePathFromLocalizationSpokenLanguages[];
    extern void* g_pOwner_00cc8e74;
}

namespace Database {
    class Results;
    class Connection;
}

typedef void (__thiscall *ResultsCtorFn)(Database::Results*, const char*);
typedef void (__thiscall *ResultsDtorFn)(Database::Results*);
typedef bool (__thiscall *ResultsStepFn)(Database::Results*);
typedef const char* (__thiscall *ResultsGetTextFn)(Database::Results*, int);
typedef bool (__thiscall *ConnExecFn)(Database::Connection*, Database::Results&, const char*, int);

extern "C" {
    extern ResultsCtorFn _imp___0Results_Database__QAE_PBD_Z;
    extern ResultsDtorFn _imp___1Results_Database__UAE_XZ;
    extern ResultsStepFn _imp__Step_Results_Database__QAE_NXZ;
    extern ResultsGetTextFn _imp__GetText_Results_Database__QAEPBDH_Z;
    extern ConnExecFn _imp__Execute_Connection_Database__QBE_NAAVResults_2_PBDH_Z;
}

// src: GUESS (confidence: high) [0x0074b3b0]
__declspec(naked) int __cdecl Lua_GetSpokenLanguages_0074b3b0(lua_State* L) {
    __asm {
        sub esp, 0x4c
        push ebx
        push ebp
        push esi
        mov esi, dword ptr [esp + 0x5c]
        push offset aDisplayName
        push esi
        call _lua_pushstring
        push esi
        call lua_gettop
        push offset aType
        push esi
        mov ebp, eax
        call _lua_pushstring
        push esi
        call lua_gettop
        push offset aPath
        push esi
        mov dword ptr [esp + 0x2c], eax
        call _lua_pushstring
        push esi
        call lua_gettop
        push 0
        push 0
        push esi
        mov dword ptr [esp + 0x40], eax
        call _lua_createtable
        push esi
        call lua_gettop
        add esp, 0x34
        push 0
        lea ecx, [esp + 0x1c]
        mov dword ptr [esp + 0x18], eax
        mov ebx, 1
        call dword ptr [_imp___0Results_Database__QAE_PBD_Z]
        mov ecx, dword ptr [g_pOwner_00cc8e74]
        push -1
        push offset aSelectTypeDisplayNamePathFromLocalizationSpokenLanguages
        lea eax, [esp + 0x20]
        add ecx, 0x944
        push eax
        call dword ptr [_imp__Execute_Connection_Database__QBE_NAAVResults_2_PBDH_Z]
        test al, al
        je loc_cleanup
        lea ecx, [esp + 0x18]
        call dword ptr [_imp__Step_Results_Database__QAE_NXZ]
        test al, al
        je loc_cleanup
        push edi
        mov edi, dword ptr [_imp__GetText_Results_Database__QAEPBDH_Z]
        mov edi, edi
    loc_loop:
        push 2
        push 0
        push esi
        call _lua_createtable
        mov ecx, dword ptr [esp + 0x1c]
        push ecx
        push esi
        call _lua_pushvalue
        add esp, 0x14
        push 0
        lea ecx, [esp + 0x20]
        call edi
        push eax
        push esi
        call _lua_pushstring
        push -3
        push esi
        call _lua_rawset
        push ebp
        push esi
        call _lua_pushvalue
        add esp, 0x18
        push 1
        lea ecx, [esp + 0x20]
        call edi
        push eax
        push esi
        call _lua_pushstring
        push -3
        push esi
        call _lua_rawset
        mov edx, dword ptr [esp + 0x24]
        push edx
        push esi
        call _lua_pushvalue
        add esp, 0x18
        push 2
        lea ecx, [esp + 0x20]
        call edi
        push eax
        push esi
        call _lua_pushstring
        push -3
        push esi
        call _lua_rawset
        mov eax, dword ptr [esp + 0x28]
        push ebx
        push eax
        push esi
        call lua_rawseti
        add esp, 0x1c
        lea ecx, [esp + 0x1c]
        inc ebx
        call dword ptr [_imp__Step_Results_Database__QAE_NXZ]
        test al, al
        jne loc_loop
        pop edi
    loc_cleanup:
        lea ecx, [esp + 0x18]
        call dword ptr [_imp___1Results_Database__UAE_XZ]
        pop esi
        pop ebp
        mov eax, 1
        pop ebx
        add esp, 0x4c
        ret
    }
}
