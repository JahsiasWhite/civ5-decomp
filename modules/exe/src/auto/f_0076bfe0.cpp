// src: GUESS (confidence: high) [0x0076bfe0]
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State* L, int idx);

#define V4(n) virtual void v##n##_0(); virtual void v##n##_1(); virtual void v##n##_2(); virtual void v##n##_3();
#define V16(n) V4(n##_0) V4(n##_1) V4(n##_2) V4(n##_3)

struct Sub76bfe0 {
    V16(0) V16(1) V16(2) V16(3)
    V16(4)
    virtual void __thiscall m_140(int a, int b) = 0;
};

struct Global76bfe0 {
    unsigned char pad[0x1460];
    Sub76bfe0* sub;
};

extern Global76bfe0* g_global_76bfe0;

int __cdecl f_0076bfe0(lua_State* L) {
    int a = lua_tointeger(L, 1);
    int b = lua_tointeger(L, 2);
    g_global_76bfe0->sub->m_140(a, b);
    return 0;
}
