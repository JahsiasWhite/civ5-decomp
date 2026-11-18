// The engine's Lua script system as the game core sees it. Slot order follows the SDK.
#pragma once

struct lua_State;
typedef int (*lua_CFunction)(lua_State*);

// src: SDK
class ICvEngineScriptSystemArgs1;

// src: SDK
class ICvEngineScriptSystem1
{
public:
    // src: SDK
    virtual lua_State* CreateLuaThread(const char* szName) = 0;
    // src: SDK
    virtual void FreeLuaThread(lua_State* L) = 0;
    // src: SDK
    virtual bool LoadFile(lua_State* L, const char* szFilename) = 0;
    // src: SDK
    virtual ICvEngineScriptSystemArgs1* CreateArgs() = 0;
    // src: SDK
    virtual ICvEngineScriptSystemArgs1* CreateArgs(unsigned int uiReserve) = 0;
    // src: SDK
    virtual void DestroyArgs(ICvEngineScriptSystemArgs1* pkArgs) = 0;
    // src: SDK
    virtual bool CallCFunction(lua_State* L, lua_CFunction func, void* args) = 0;
    // src: SDK
    virtual bool CallFunction(lua_State* L, unsigned int nArgs, unsigned int nRet) = 0;
    // src: SDK
    virtual bool CallHook(const char* szName, ICvEngineScriptSystemArgs1* args, bool& value) = 0;
};
