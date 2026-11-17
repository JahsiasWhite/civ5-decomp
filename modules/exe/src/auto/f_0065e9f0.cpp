// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0065e9f0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x005c9dd0]
int l_ActivateGameOverlay_005c9dd0(lua_State* L);
// src: EXE [0x00a704dc]
extern const char g_str_ActivateGameOverlay_00a704dc[];
// src: GUESS (confidence: high) [0x005b20e0]
int l_ActivateGameOverlayToWebPage_005b20e0(lua_State* L);
// src: EXE [0x00a705e4]
extern const char g_str_ActivateGameOverlayToWebPage_00a705e4[];
// src: GUESS (confidence: high) [0x00705810]
int l_ActivateGameOverlayToStore_00705810(lua_State* L);
// src: EXE [0x00a70604]
extern const char g_str_ActivateGameOverlayToStore_00a70604[];
// src: GUESS (confidence: high) [0x005a7400]
int l_ActivateInviteOverlay_005a7400(lua_State* L);
// src: EXE [0x00a70620]
extern const char g_str_ActivateInviteOverlay_00a70620[];
// src: GUESS (confidence: high) [0x006d7a10]
int l_SetOverlayNotificationPosition_006d7a10(lua_State* L);
// src: EXE [0x00a70638]
extern const char g_str_SetOverlayNotificationPosition_00a70638[];
// src: GUESS (confidence: high) [0x00540270]
int l_IsOverlayEnabled_00540270(lua_State* L);
// src: EXE [0x00a70658]
extern const char g_str_IsOverlayEnabled_00a70658[];
// src: GUESS (confidence: high) [0x00473590]
int l_GetMySteamID_00473590(lua_State* L);
// src: EXE [0x00a7066c]
extern const char g_str_GetMySteamID_00a7066c[];
// src: GUESS (confidence: high) [0x00713d90]
int l_GetPlayerSteamID_00713d90(lua_State* L);
// src: EXE [0x00a7067c]
extern const char g_str_GetPlayerSteamID_00a7067c[];
// src: GUESS (confidence: high) [0x00610720]
int l_GetCloudSaveFileName_00610720(lua_State* L);
// src: EXE [0x00a70690]
extern const char g_str_GetCloudSaveFileName_00a70690[];
// src: GUESS (confidence: high) [0x00777f10]
int l_GetMaxCloudSaves_00777f10(lua_State* L);
// src: EXE [0x00a706a8]
extern const char g_str_GetMaxCloudSaves_00a706a8[];
// src: GUESS (confidence: high) [0x00660470]
int l_GetCloudSaves_00660470(lua_State* L);
// src: EXE [0x00a706bc]
extern const char g_str_GetCloudSaves_00a706bc[];
// src: GUESS (confidence: high) [0x004a08a0]
int l_SaveGameToCloud_004a08a0(lua_State* L);
// src: EXE [0x00a706cc]
extern const char g_str_SaveGameToCloud_00a706cc[];
// src: GUESS (confidence: high) [0x007aa500]
int l_CopyLastAutoSaveToSteamCloud_007aa500(lua_State* L);
// src: EXE [0x00a706dc]
extern const char g_str_CopyLastAutoSaveToSteamCloud_00a706dc[];

int RegisterSteamLib_0065e9f0(lua_State* L) {
    lua_createtable(L, 0, 5);
    lua_pushcclosure(L, l_ActivateGameOverlay_005c9dd0, 0);
    lua_setfield(L, -2, g_str_ActivateGameOverlay_00a704dc);
    lua_pushcclosure(L, l_ActivateGameOverlayToWebPage_005b20e0, 0);
    lua_setfield(L, -2, g_str_ActivateGameOverlayToWebPage_00a705e4);
    lua_pushcclosure(L, l_ActivateGameOverlayToStore_00705810, 0);
    lua_setfield(L, -2, g_str_ActivateGameOverlayToStore_00a70604);
    lua_pushcclosure(L, l_ActivateInviteOverlay_005a7400, 0);
    lua_setfield(L, -2, g_str_ActivateInviteOverlay_00a70620);
    lua_pushcclosure(L, l_SetOverlayNotificationPosition_006d7a10, 0);
    lua_setfield(L, -2, g_str_SetOverlayNotificationPosition_00a70638);
    lua_pushcclosure(L, l_IsOverlayEnabled_00540270, 0);
    lua_setfield(L, -2, g_str_IsOverlayEnabled_00a70658);
    lua_pushcclosure(L, l_GetMySteamID_00473590, 0);
    lua_setfield(L, -2, g_str_GetMySteamID_00a7066c);
    lua_pushcclosure(L, l_GetPlayerSteamID_00713d90, 0);
    lua_setfield(L, -2, g_str_GetPlayerSteamID_00a7067c);
    lua_pushcclosure(L, l_GetCloudSaveFileName_00610720, 0);
    lua_setfield(L, -2, g_str_GetCloudSaveFileName_00a70690);
    lua_pushcclosure(L, l_GetMaxCloudSaves_00777f10, 0);
    lua_setfield(L, -2, g_str_GetMaxCloudSaves_00a706a8);
    lua_pushcclosure(L, l_GetCloudSaves_00660470, 0);
    lua_setfield(L, -2, g_str_GetCloudSaves_00a706bc);
    lua_pushcclosure(L, l_SaveGameToCloud_004a08a0, 0);
    lua_setfield(L, -2, g_str_SaveGameToCloud_00a706cc);
    lua_pushcclosure(L, l_CopyLastAutoSaveToSteamCloud_007aa500, 0);
    lua_setfield(L, -2, g_str_CopyLastAutoSaveToSteamCloud_00a706dc);
    return 1;
}
