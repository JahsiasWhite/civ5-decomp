// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) lua integer extraction into struct offset 4
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State*, int);

struct Target_005d5680 {
    int pad;
    int val;
};

// src: GUESS (confidence: high) [0x005d5680]
__declspec(naked) void __cdecl GetLuaInt2_005d5680(lua_State* L, Target_005d5680* out) {
    __asm {
        mov eax, dword ptr [esp + 4]
        push 1
        push eax
        call lua_tointeger
        mov ecx, dword ptr [esp + 0x10]
        add esp, 8
        mov dword ptr [ecx + 4], eax
        ret
    }
}
