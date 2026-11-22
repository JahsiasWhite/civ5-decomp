typedef unsigned char uint8_t;

struct lua_State;

// src: EXE [0x00889684]
extern "C" int __cdecl lua_toboolean_opt(lua_State* L, int idx, int def);

// src: GUESS (confidence: low) [0x0075ad70]
struct Sub75AD70 {
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0c() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1c() = 0;
    virtual void vf20() = 0;
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2c() = 0;
    virtual void vf30() = 0;
    virtual void vf34() = 0;
    virtual void vf38() = 0;
    virtual void vf3c() = 0;
    virtual void vf40() = 0;
    virtual void vf44() = 0;
    virtual void vf48() = 0;
    virtual void vf4c() = 0;
    virtual void vf50() = 0;
    virtual void vf54() = 0;
    virtual void vf58() = 0;
    virtual void vf5c() = 0;
    virtual void vf60() = 0;
    virtual void vf64() = 0;
    virtual void vf68() = 0;
    virtual void vf6c() = 0;
    virtual void vf70(bool b) = 0;
};

// src: GUESS (confidence: low) [0x0075ad70]
struct Obj75AD70 {
    uint8_t    m_pad00[0xd0];
    Sub75AD70* m_sub;
};

// src: GUESS (confidence: low) [0x0075ad70]
extern Obj75AD70* g_obj75AD70;

// src: GUESS (confidence: low) [0x0075ad70]
int __cdecl luaFunc75AD70(lua_State* L) {
    Sub75AD70* sub = g_obj75AD70->m_sub;
    bool b = lua_toboolean_opt(L, 1, 0) != 0;
    sub->vf70(b);
    return 0;
}
