// Pushes an unsigned 32-bit value (stored at offset 4 of an object) onto the Lua stack.

struct lua_State;
extern "C" void lua_pushnumber(lua_State* L, double n);

struct UIntHolder
{
    int pad0;
    unsigned int value;
};

void PushUIntValueToLua(lua_State* L, const UIntHolder* holder)
{
    lua_pushnumber(L, (double)holder->value);
}
