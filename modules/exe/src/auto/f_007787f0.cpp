typedef unsigned char uint8_t;

struct lua_State;

// src: EXE [0x0088962a]
extern "C" void __cdecl lua_reg7787F0(void* ctx, void (*fn)(), lua_State* L);
// src: EXE [0x00778000]
extern "C" void __cdecl fn778000();
// src: EXE [0x007781b0]
extern "C" void __cdecl fn7781B0();

// src: GUESS (confidence: low) [0x007787f0]
struct Obj7787F0 {
    uint8_t m_pad00[0x81900];
    void*   m_ctx;
};

// src: GUESS (confidence: low) [0x007787f0]
extern Obj7787F0* g_obj7787F0;

// src: GUESS (confidence: low) [0x007787f0]
void __cdecl registerLua7787F0(lua_State* L, int mode) {
    switch (mode) {
    case 1:
        lua_reg7787F0(g_obj7787F0->m_ctx, fn7781B0, L);
        break;
    case 2:
        lua_reg7787F0(g_obj7787F0->m_ctx, fn778000, L);
        break;
    }
}
