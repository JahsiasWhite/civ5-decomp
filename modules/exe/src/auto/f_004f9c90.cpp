// c5d-cflags: -/arch:SSE2 -/fp:fast   (this file was built with x87 floating point)
// Pushes a record (two ints, a float and a flag) onto the Lua stack.

struct lua_State;
extern "C" void lua_pushinteger(lua_State* L, int n);
extern "C" void lua_pushnumber(lua_State* L, double n);
extern "C" void lua_pushboolean(lua_State* L, int b);

struct FloatIntIntFlagRecord
{
    float value;
    int first;
    int second;
    bool flag;
};

void PushFloatIntIntFlagRecordToLua(lua_State* L, const FloatIntIntFlagRecord* rec)
{
    lua_pushinteger(L, rec->first);
    lua_pushinteger(L, rec->second);
    lua_pushnumber(L, (double)rec->value);
    lua_pushboolean(L, rec->flag);
}
