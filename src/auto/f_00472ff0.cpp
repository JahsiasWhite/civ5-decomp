// c5d-model: claude-opus-5-5
// Pushes four fixed-width 32-character string fields onto the Lua stack.

struct lua_State;
extern "C" void lua_pushlstring(lua_State* L, const char* s, unsigned int len);

struct FourNameBlock
{
    char names[4][32];
};

void PushFourNameStringsToLua(lua_State* L, const FourNameBlock* block)
{
    lua_pushlstring(L, block->names[0], 32);
    lua_pushlstring(L, block->names[1], 32);
    lua_pushlstring(L, block->names[2], 32);
    lua_pushlstring(L, block->names[3], 32);
}
