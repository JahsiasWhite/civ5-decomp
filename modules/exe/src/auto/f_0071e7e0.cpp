// Pushes an integer id followed by a fixed-width 128-character name onto the Lua stack.

struct lua_State;
extern "C" void lua_pushinteger(lua_State* L, int n);
extern "C" void lua_pushlstring(lua_State* L, const char* s, unsigned int len);

struct IdNameRecord
{
    int id;
    char name[128];
};

void PushIdNameRecordToLua(lua_State* L, const IdNameRecord* rec)
{
    lua_pushinteger(L, rec->id);
    lua_pushlstring(L, rec->name, 128);
}
