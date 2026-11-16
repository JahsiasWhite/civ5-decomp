// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) lua float extraction
struct lua_State;
extern "C" double __cdecl lua_tonumber(lua_State*, int);

// src: GUESS (confidence: high) [0x0046d5e0]
__declspec(naked) void __cdecl GetLuaFloat_0046d5e0(lua_State* L, float* out) {
    __asm {
        mov eax, dword ptr [esp + 4]
        push 1
        push eax
        call lua_tonumber
        mov ecx, dword ptr [esp + 0x10]
        fstp dword ptr [ecx]
        add esp, 8
        ret
    }
}
