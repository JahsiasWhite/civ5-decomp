// src: GUESS (confidence: low)
struct lua_State;

// src: GUESS (confidence: low)
extern "C" int __cdecl lua_tointeger_0088954c(lua_State* L, int idx);

// src: GUESS (confidence: low)
struct Rect_006dc040 {
    int f0;
    int f4;
    int f8;
    int fc;
};

// src: GUESS (confidence: low)
void fn_006dc040(lua_State* L, Rect_006dc040* r) {
    r->f0 = lua_tointeger_0088954c(L, 1);
    r->fc = lua_tointeger_0088954c(L, 2);
    r->f4 = lua_tointeger_0088954c(L, 3);
    r->f8 = lua_tointeger_0088954c(L, 4);
}
