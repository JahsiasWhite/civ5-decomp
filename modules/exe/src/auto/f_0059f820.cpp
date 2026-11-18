// src: EXE [0x0059f820]
#include "LuaApi.h"
#include "Localization/Language.h"

// src: EXE [0x00a69a70]
extern const char g_str_CompareError_00a69a70[];

// src: EXE [0x0059f820]
int l_Compare_0059f820(lua_State* L) {
    unsigned int uiLen1 = 0;
    const char* szStr1 = luaL_checklstring(L, 1, &uiLen1);
    unsigned int uiLen2 = 0;
    const char* szStr2 = luaL_checklstring(L, 2, &uiLen2);
    const Localization::Language& kLang = Localization::GetCurrentLanguage();
    int iResult = 0;
    if (kLang.Compare(szStr1, uiLen1, szStr2, uiLen2, iResult)) {
        lua_pushinteger(L, iResult);
        return 1;
    }
    luaL_error(L, g_str_CompareError_00a69a70);
    return 0;
}
