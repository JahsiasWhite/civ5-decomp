// src: GUESS (confidence: high) [0x0076c120]
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State* L, int idx);

#define V4(n) virtual void v##n##_0(); virtual void v##n##_1(); virtual void v##n##_2(); virtual void v##n##_3();
#define V16(n) V4(n##_0) V4(n##_1) V4(n##_2) V4(n##_3)
#define V64(n) V16(n##_0) V16(n##_1) V16(n##_2) V16(n##_3)

struct Sub76c120 {
    V64(0) V64(1) V64(2) V64(3)
    V4(4)
    virtual void v260();
    virtual void __thiscall m_414(int a, int b) = 0;
};

struct Global76c120 {
    unsigned char pad[0x1460];
    Sub76c120* sub;
};

extern Global76c120* g_global_76c120;

int __cdecl f_0076c120(lua_State* L) {
    int a = lua_tointeger(L, 1);
    int b = lua_tointeger(L, 2);
    g_global_76c120->sub->m_414(a, b);
    return 0;
}
