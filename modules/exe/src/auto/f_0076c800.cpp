// src: GUESS (confidence: high) [0x0076c800]
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State* L, int idx);

#define V4(n) virtual void v##n##_0(); virtual void v##n##_1(); virtual void v##n##_2(); virtual void v##n##_3();
#define V16(n) V4(n##_0) V4(n##_1) V4(n##_2) V4(n##_3)
#define V64(n) V16(n##_0) V16(n##_1) V16(n##_2) V16(n##_3)

struct Sub76c800 {
    V64(0)
    virtual void v64(); virtual void v65(); virtual void v66();
    virtual void __thiscall m_10c(int a, int b) = 0;
};

struct Global76c800 {
    unsigned char pad[0x1460];
    Sub76c800* sub;
};

extern Global76c800* g_global_76c800;

int __cdecl f_0076c800(lua_State* L) {
    int a = lua_tointeger(L, 1);
    int b = lua_tointeger(L, 2);
    g_global_76c800->sub->m_10c(a, b);
    return 0;
}
