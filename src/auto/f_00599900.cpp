// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) lua integer extraction
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State*, int);

// src: GUESS (confidence: high) [0x00599900]
__declspec(naked) void __cdecl GetLuaInt_00599900(lua_State* L, int* out) {
    __asm {
        mov eax, dword ptr [esp + 4]
        push 1
        push eax
        call lua_tointeger
        mov ecx, dword ptr [esp + 0x10]
        add esp, 8
        mov dword ptr [ecx], eax
        ret
    }
}
