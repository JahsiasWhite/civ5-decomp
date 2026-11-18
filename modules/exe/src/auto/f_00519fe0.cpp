#include "LuaApi.h"

// src: EXE [0x00727d10]
int l_PreGame_GetCivilization(lua_State* L);
// src: EXE [0x005b8420]
int l_PreGame_SetCivilization(lua_State* L);
// src: EXE [0x0076e8f0]
int l_PreGame_GetMultiplayerAIEnabled(lua_State* L);
// src: EXE [0x0077ce80]
int l_PreGame_SetMultiplayerAIEnabled(lua_State* L);
// src: EXE [0x00570320]
int l_PreGame_GetMapScript(lua_State* L);
// src: EXE [0x0054e340]
int l_PreGame_SetMapScript(lua_State* L);
// src: EXE [0x00688a00]
int l_PreGame_RandomizeMapSeed(lua_State* L);
// src: EXE [0x006228d0]
int l_PreGame_GetLoadWBScenario(lua_State* L);
// src: EXE [0x006f1ae0]
int l_PreGame_SetLoadWBScenario(lua_State* L);
// src: EXE [0x005a4a10]
int l_PreGame_GetOverrideScenarioHandicap(lua_State* L);
// src: EXE [0x00602fb0]
int l_PreGame_SetOverrideScenarioHandicap(lua_State* L);
// src: EXE [0x00664310]
int l_PreGame_IsRandomMapScript(lua_State* L);
// src: EXE [0x0063cbd0]
int l_PreGame_SetRandomMapScript(lua_State* L);
// src: EXE [0x006b2c30]
int l_PreGame_GetGameSpeed(lua_State* L);
// src: EXE [0x0059c120]
int l_PreGame_SetGameSpeed(lua_State* L);
// src: EXE [0x006c7e50]
int l_PreGame_GetWorldSize(lua_State* L);
// src: EXE [0x0071de70]
int l_PreGame_SetWorldSize(lua_State* L);
// src: EXE [0x00777300]
int l_PreGame_IsEarthMap(lua_State* L);
// src: EXE [0x007793a0]
int l_PreGame_SetEarthMap(lua_State* L);
// src: EXE [0x0069a6a0]
int l_PreGame_IsRandomWorldSize(lua_State* L);
// src: EXE [0x0049a920]
int l_PreGame_SetRandomWorldSize(lua_State* L);
// src: EXE [0x00447ba0]
int l_PreGame_GetHandicap(lua_State* L);
// src: EXE [0x0064abc0]
int l_PreGame_SetHandicap(lua_State* L);
// src: EXE [0x00634ff0]
int l_PreGame_GetTeam(lua_State* L);
// src: EXE [0x00583750]
int l_PreGame_SetTeam(lua_State* L);
// src: EXE [0x0060f1e0]
int l_PreGame_GetLeaderName(lua_State* L);
// src: EXE [0x0051cd40]
int l_PreGame_SetLeaderName(lua_State* L);
// src: EXE [0x00571920]
int l_PreGame_GetLeaderType(lua_State* L);
// src: EXE [0x0046b750]
int l_PreGame_SetLeaderType(lua_State* L);
// src: EXE [0x007a05b0]
int l_PreGame_SetPlayerColor(lua_State* L);
// src: EXE [0x00441f80]
int l_PreGame_GetLeaderKey(lua_State* L);
// src: EXE [0x006cf5b0]
int l_PreGame_SetLeaderKey(lua_State* L);
// src: EXE [0x00497e80]
int l_PreGame_IsLeaderKeyAvailable(lua_State* L);
// src: EXE [0x006d85f0]
int l_PreGame_GetLeaderPackageID(lua_State* L);
// src: EXE [0x0042a9f0]
int l_PreGame_SetLeaderPackageID(lua_State* L);
// src: EXE [0x005c6540]
int l_PreGame_GetLeaderPackageTextKey(lua_State* L);
// src: EXE [0x00500e70]
int l_PreGame_GetCivilizationDescription(lua_State* L);
// src: EXE [0x005aeba0]
int l_PreGame_SetCivilizationDescription(lua_State* L);
// src: EXE [0x00534880]
int l_PreGame_GetCivilizationShortDescription(lua_State* L);
// src: EXE [0x0060c6a0]
int l_PreGame_SetCivilizationShortDescription(lua_State* L);
// src: EXE [0x004064f0]
int l_PreGame_GetCivilizationAdjective(lua_State* L);
// src: EXE [0x00751110]
int l_PreGame_SetCivilizationAdjective(lua_State* L);
// src: EXE [0x0067ba40]
int l_PreGame_GetCivilizationColor(lua_State* L);
// src: EXE [0x004ce4a0]
int l_PreGame_GetCivilizationKey(lua_State* L);
// src: EXE [0x0058a670]
int l_PreGame_SetCivilizationKey(lua_State* L);
// src: EXE [0x0040b3b0]
int l_PreGame_IsCivilizationKeyAvailable(lua_State* L);
// src: EXE [0x004d6740]
int l_PreGame_GetCivilizationPackageID(lua_State* L);
// src: EXE [0x00434470]
int l_PreGame_SetCivilizationPackageID(lua_State* L);
// src: EXE [0x00490120]
int l_PreGame_GetCivilizationPackageTextKey(lua_State* L);
// src: EXE [0x005c36e0]
int l_PreGame_GetPassword(lua_State* L);
// src: EXE [0x0048ed10]
int l_PreGame_SetPassword(lua_State* L);
// src: EXE [0x006554b0]
int l_PreGame_HasPassword(lua_State* L);
// src: EXE [0x00564580]
int l_PreGame_TestPassword(lua_State* L);
// src: EXE [0x005ae9c0]
int l_PreGame_GetLoadFileName(lua_State* L);
// src: EXE [0x007721d0]
int l_PreGame_SetLoadFileName(lua_State* L);
// src: EXE [0x004b71d0]
int l_PreGame_GetNickName(lua_State* L);
// src: EXE [0x0074fd80]
int l_PreGame_SetNickName(lua_State* L);
// src: EXE [0x007a6f60]
int l_PreGame_GetSlotStatus(lua_State* L);
// src: EXE [0x004e5240]
int l_PreGame_SetSlotStatus(lua_State* L);
// src: EXE [0x0053fed0]
int l_PreGame_GetSlotClaim(lua_State* L);
// src: EXE [0x0077be20]
int l_PreGame_SetSlotClaim(lua_State* L);
// src: EXE [0x00616f00]
int l_PreGame_GetMaxTurns(lua_State* L);
// src: EXE [0x005cd0c0]
int l_PreGame_SetMaxTurns(lua_State* L);
// src: EXE [0x0040f630]
int l_PreGame_GetPitbossTurnTime(lua_State* L);
// src: EXE [0x0040c600]
int l_PreGame_SetPitbossTurnTime(lua_State* L);
// src: EXE [0x004501b0]
int l_PreGame_GetEra(lua_State* L);
// src: EXE [0x00483fd0]
int l_PreGame_SetEra(lua_State* L);
// src: EXE [0x00534bf0]
int l_PreGame_GetNumMinorCivs(lua_State* L);
// src: EXE [0x00738480]
int l_PreGame_SetNumMinorCivs(lua_State* L);
// src: EXE [0x0073eeb0]
int l_PreGame_SetPrivateGame(lua_State* L);
// src: EXE [0x007a9bc0]
int l_PreGame_IsPrivateGame(lua_State* L);
// src: EXE [0x0045de50]
int l_PreGame_GetPersistSettings(lua_State* L);
// src: EXE [0x0061f960]
int l_PreGame_SetPersistSettings(lua_State* L);
// src: EXE [0x004f9b80]
int l_PreGame_LoadPreGameSettings(lua_State* L);
// src: EXE [0x00676590]
int l_PreGame_SetReady(lua_State* L);
// src: EXE [0x004baed0]
int l_PreGame_IsReady(lua_State* L);
// src: EXE [0x00544980]
int l_PreGame_CanReadyLocalPlayer(lua_State* L);
// src: EXE [0x006c9a40]
int l_PreGame_SetInternetGame(lua_State* L);
// src: EXE [0x004d0880]
int l_PreGame_IsInternetGame(lua_State* L);
// src: EXE [0x00553ed0]
int l_PreGame_SetMultiplayerGame(lua_State* L);
// src: EXE [0x0076c310]
int l_PreGame_IsMultiplayerGame(lua_State* L);
// src: EXE [0x006113c0]
int l_PreGame_IsHotSeatGame(lua_State* L);
// src: EXE [0x00414dc0]
int l_PreGame_SetGameType(lua_State* L);
// src: EXE [0x005b2a10]
int l_PreGame_GetGameType(lua_State* L);
// src: EXE [0x0053d180]
int l_PreGame_GetGameOption(lua_State* L);
// src: EXE [0x004906f0]
int l_PreGame_SetGameOption(lua_State* L);
// src: EXE [0x00710fd0]
int l_PreGame_ResetGameOptions(lua_State* L);
// src: EXE [0x005dc340]
int l_PreGame_GetMapOption(lua_State* L);
// src: EXE [0x00494bb0]
int l_PreGame_SetMapOption(lua_State* L);
// src: EXE [0x0045d000]
int l_PreGame_ResetMapOptions(lua_State* L);
// src: EXE [0x0076fad0]
int l_PreGame_ResetSlots(lua_State* L);
// src: EXE [0x0040fbd0]
int l_PreGame_Reset(lua_State* L);
// src: EXE [0x005ee240]
int l_PreGame_GetFileHeader(lua_State* L);
// src: EXE [0x006eba90]
int l_PreGame_IsVictory(lua_State* L);
// src: EXE [0x00577170]
int l_PreGame_SetVictory(lua_State* L);
// src: EXE [0x00559e30]
int l_PreGame_SetQuickCombat(lua_State* L);
// src: EXE [0x0054e470]
int l_PreGame_GetQuickCombat(lua_State* L);
// src: EXE [0x0066d940]
int l_PreGame_SetQuickMovement(lua_State* L);
// src: EXE [0x00797b10]
int l_PreGame_GetQuickMovement(lua_State* L);
// src: EXE [0x0053d8d0]
int l_PreGame_ReadActiveSlotCountFromSaveGame(lua_State* L);
// src: EXE [0x0049e5b0]
int l_PreGame_IsDLCAllowed(lua_State* L);
// src: EXE [0x00508db0]
int l_PreGame_SetDLCAllowed(lua_State* L);
// src: EXE [0x00743b40]
int l_PreGame_ClearDLCAllowed(lua_State* L);
// src: EXE [0x004fcc70]
int l_PreGame_GameStarted(lua_State* L);

// src: GUESS (confidence: high) [0x00519fe0]
int RegisterPreGameLua(lua_State* L)
{
    lua_createtable(L, 0, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_GLOBALSINDEX, "PreGame");
    lua_pushcclosure(L, l_PreGame_GetCivilization, 0);
    lua_setfield(L, -2, "GetCivilization");
    lua_pushcclosure(L, l_PreGame_SetCivilization, 0);
    lua_setfield(L, -2, "SetCivilization");
    lua_pushcclosure(L, l_PreGame_GetMultiplayerAIEnabled, 0);
    lua_setfield(L, -2, "GetMultiplayerAIEnabled");
    lua_pushcclosure(L, l_PreGame_SetMultiplayerAIEnabled, 0);
    lua_setfield(L, -2, "SetMultiplayerAIEnabled");
    lua_pushcclosure(L, l_PreGame_GetMapScript, 0);
    lua_setfield(L, -2, "GetMapScript");
    lua_pushcclosure(L, l_PreGame_SetMapScript, 0);
    lua_setfield(L, -2, "SetMapScript");
    lua_pushcclosure(L, l_PreGame_RandomizeMapSeed, 0);
    lua_setfield(L, -2, "RandomizeMapSeed");
    lua_pushcclosure(L, l_PreGame_GetLoadWBScenario, 0);
    lua_setfield(L, -2, "GetLoadWBScenario");
    lua_pushcclosure(L, l_PreGame_SetLoadWBScenario, 0);
    lua_setfield(L, -2, "SetLoadWBScenario");
    lua_pushcclosure(L, l_PreGame_GetOverrideScenarioHandicap, 0);
    lua_setfield(L, -2, "GetOverrideScenarioHandicap");
    lua_pushcclosure(L, l_PreGame_SetOverrideScenarioHandicap, 0);
    lua_setfield(L, -2, "SetOverrideScenarioHandicap");
    lua_pushcclosure(L, l_PreGame_IsRandomMapScript, 0);
    lua_setfield(L, -2, "IsRandomMapScript");
    lua_pushcclosure(L, l_PreGame_SetRandomMapScript, 0);
    lua_setfield(L, -2, "SetRandomMapScript");
    lua_pushcclosure(L, l_PreGame_GetGameSpeed, 0);
    lua_setfield(L, -2, "GetGameSpeed");
    lua_pushcclosure(L, l_PreGame_SetGameSpeed, 0);
    lua_setfield(L, -2, "SetGameSpeed");
    lua_pushcclosure(L, l_PreGame_GetWorldSize, 0);
    lua_setfield(L, -2, "GetWorldSize");
    lua_pushcclosure(L, l_PreGame_SetWorldSize, 0);
    lua_setfield(L, -2, "SetWorldSize");
    lua_pushcclosure(L, l_PreGame_IsEarthMap, 0);
    lua_setfield(L, -2, "IsEarthMap");
    lua_pushcclosure(L, l_PreGame_SetEarthMap, 0);
    lua_setfield(L, -2, "SetEarthMap");
    lua_pushcclosure(L, l_PreGame_IsRandomWorldSize, 0);
    lua_setfield(L, -2, "IsRandomWorldSize");
    lua_pushcclosure(L, l_PreGame_SetRandomWorldSize, 0);
    lua_setfield(L, -2, "SetRandomWorldSize");
    lua_pushcclosure(L, l_PreGame_GetHandicap, 0);
    lua_setfield(L, -2, "GetHandicap");
    lua_pushcclosure(L, l_PreGame_SetHandicap, 0);
    lua_setfield(L, -2, "SetHandicap");
    lua_pushcclosure(L, l_PreGame_GetTeam, 0);
    lua_setfield(L, -2, "GetTeam");
    lua_pushcclosure(L, l_PreGame_SetTeam, 0);
    lua_setfield(L, -2, "SetTeam");
    lua_pushcclosure(L, l_PreGame_GetLeaderName, 0);
    lua_setfield(L, -2, "GetLeaderName");
    lua_pushcclosure(L, l_PreGame_SetLeaderName, 0);
    lua_setfield(L, -2, "SetLeaderName");
    lua_pushcclosure(L, l_PreGame_GetLeaderType, 0);
    lua_setfield(L, -2, "GetLeaderType");
    lua_pushcclosure(L, l_PreGame_SetLeaderType, 0);
    lua_setfield(L, -2, "SetLeaderType");
    lua_pushcclosure(L, l_PreGame_SetPlayerColor, 0);
    lua_setfield(L, -2, "SetPlayerColor");
    lua_pushcclosure(L, l_PreGame_GetLeaderKey, 0);
    lua_setfield(L, -2, "GetLeaderKey");
    lua_pushcclosure(L, l_PreGame_SetLeaderKey, 0);
    lua_setfield(L, -2, "SetLeaderKey");
    lua_pushcclosure(L, l_PreGame_IsLeaderKeyAvailable, 0);
    lua_setfield(L, -2, "IsLeaderKeyAvailable");
    lua_pushcclosure(L, l_PreGame_GetLeaderPackageID, 0);
    lua_setfield(L, -2, "GetLeaderPackageID");
    lua_pushcclosure(L, l_PreGame_SetLeaderPackageID, 0);
    lua_setfield(L, -2, "SetLeaderPackageID");
    lua_pushcclosure(L, l_PreGame_GetLeaderPackageTextKey, 0);
    lua_setfield(L, -2, "GetLeaderPackageTextKey");
    lua_pushcclosure(L, l_PreGame_GetCivilizationDescription, 0);
    lua_setfield(L, -2, "GetCivilizationDescription");
    lua_pushcclosure(L, l_PreGame_SetCivilizationDescription, 0);
    lua_setfield(L, -2, "SetCivilizationDescription");
    lua_pushcclosure(L, l_PreGame_GetCivilizationShortDescription, 0);
    lua_setfield(L, -2, "GetCivilizationShortDescription");
    lua_pushcclosure(L, l_PreGame_SetCivilizationShortDescription, 0);
    lua_setfield(L, -2, "SetCivilizationShortDescription");
    lua_pushcclosure(L, l_PreGame_GetCivilizationAdjective, 0);
    lua_setfield(L, -2, "GetCivilizationAdjective");
    lua_pushcclosure(L, l_PreGame_SetCivilizationAdjective, 0);
    lua_setfield(L, -2, "SetCivilizationAdjective");
    lua_pushcclosure(L, l_PreGame_GetCivilizationColor, 0);
    lua_setfield(L, -2, "GetCivilizationColor");
    lua_pushcclosure(L, l_PreGame_GetCivilizationKey, 0);
    lua_setfield(L, -2, "GetCivilizationKey");
    lua_pushcclosure(L, l_PreGame_SetCivilizationKey, 0);
    lua_setfield(L, -2, "SetCivilizationKey");
    lua_pushcclosure(L, l_PreGame_IsCivilizationKeyAvailable, 0);
    lua_setfield(L, -2, "IsCivilizationKeyAvailable");
    lua_pushcclosure(L, l_PreGame_GetCivilizationPackageID, 0);
    lua_setfield(L, -2, "GetCivilizationPackageID");
    lua_pushcclosure(L, l_PreGame_SetCivilizationPackageID, 0);
    lua_setfield(L, -2, "SetCivilizationPackageID");
    lua_pushcclosure(L, l_PreGame_GetCivilizationPackageTextKey, 0);
    lua_setfield(L, -2, "GetCivilizationPackageTextKey");
    lua_pushcclosure(L, l_PreGame_GetPassword, 0);
    lua_setfield(L, -2, "GetPassword");
    lua_pushcclosure(L, l_PreGame_SetPassword, 0);
    lua_setfield(L, -2, "SetPassword");
    lua_pushcclosure(L, l_PreGame_HasPassword, 0);
    lua_setfield(L, -2, "HasPassword");
    lua_pushcclosure(L, l_PreGame_TestPassword, 0);
    lua_setfield(L, -2, "TestPassword");
    lua_pushcclosure(L, l_PreGame_GetLoadFileName, 0);
    lua_setfield(L, -2, "GetLoadFileName");
    lua_pushcclosure(L, l_PreGame_SetLoadFileName, 0);
    lua_setfield(L, -2, "SetLoadFileName");
    lua_pushcclosure(L, l_PreGame_GetNickName, 0);
    lua_setfield(L, -2, "GetNickName");
    lua_pushcclosure(L, l_PreGame_SetNickName, 0);
    lua_setfield(L, -2, "SetNickName");
    lua_pushcclosure(L, l_PreGame_GetSlotStatus, 0);
    lua_setfield(L, -2, "GetSlotStatus");
    lua_pushcclosure(L, l_PreGame_SetSlotStatus, 0);
    lua_setfield(L, -2, "SetSlotStatus");
    lua_pushcclosure(L, l_PreGame_GetSlotClaim, 0);
    lua_setfield(L, -2, "GetSlotClaim");
    lua_pushcclosure(L, l_PreGame_SetSlotClaim, 0);
    lua_setfield(L, -2, "SetSlotClaim");
    lua_pushcclosure(L, l_PreGame_GetMaxTurns, 0);
    lua_setfield(L, -2, "GetMaxTurns");
    lua_pushcclosure(L, l_PreGame_SetMaxTurns, 0);
    lua_setfield(L, -2, "SetMaxTurns");
    lua_pushcclosure(L, l_PreGame_GetPitbossTurnTime, 0);
    lua_setfield(L, -2, "GetPitbossTurnTime");
    lua_pushcclosure(L, l_PreGame_SetPitbossTurnTime, 0);
    lua_setfield(L, -2, "SetPitbossTurnTime");
    lua_pushcclosure(L, l_PreGame_GetEra, 0);
    lua_setfield(L, -2, "GetEra");
    lua_pushcclosure(L, l_PreGame_SetEra, 0);
    lua_setfield(L, -2, "SetEra");
    lua_pushcclosure(L, l_PreGame_GetNumMinorCivs, 0);
    lua_setfield(L, -2, "GetNumMinorCivs");
    lua_pushcclosure(L, l_PreGame_SetNumMinorCivs, 0);
    lua_setfield(L, -2, "SetNumMinorCivs");
    lua_pushcclosure(L, l_PreGame_SetPrivateGame, 0);
    lua_setfield(L, -2, "SetPrivateGame");
    lua_pushcclosure(L, l_PreGame_IsPrivateGame, 0);
    lua_setfield(L, -2, "IsPrivateGame");
    lua_pushcclosure(L, l_PreGame_GetPersistSettings, 0);
    lua_setfield(L, -2, "GetPersistSettings");
    lua_pushcclosure(L, l_PreGame_SetPersistSettings, 0);
    lua_setfield(L, -2, "SetPersistSettings");
    lua_pushcclosure(L, l_PreGame_LoadPreGameSettings, 0);
    lua_setfield(L, -2, "LoadPreGameSettings");
    lua_pushcclosure(L, l_PreGame_SetReady, 0);
    lua_setfield(L, -2, "SetReady");
    lua_pushcclosure(L, l_PreGame_IsReady, 0);
    lua_setfield(L, -2, "IsReady");
    lua_pushcclosure(L, l_PreGame_CanReadyLocalPlayer, 0);
    lua_setfield(L, -2, "CanReadyLocalPlayer");
    lua_pushcclosure(L, l_PreGame_SetInternetGame, 0);
    lua_setfield(L, -2, "SetInternetGame");
    lua_pushcclosure(L, l_PreGame_IsInternetGame, 0);
    lua_setfield(L, -2, "IsInternetGame");
    lua_pushcclosure(L, l_PreGame_SetMultiplayerGame, 0);
    lua_setfield(L, -2, "SetMultiplayerGame");
    lua_pushcclosure(L, l_PreGame_IsMultiplayerGame, 0);
    lua_setfield(L, -2, "IsMultiplayerGame");
    lua_pushcclosure(L, l_PreGame_IsHotSeatGame, 0);
    lua_setfield(L, -2, "IsHotSeatGame");
    lua_pushcclosure(L, l_PreGame_SetGameType, 0);
    lua_setfield(L, -2, "SetGameType");
    lua_pushcclosure(L, l_PreGame_GetGameType, 0);
    lua_setfield(L, -2, "GetGameType");
    lua_pushcclosure(L, l_PreGame_GetGameOption, 0);
    lua_setfield(L, -2, "GetGameOption");
    lua_pushcclosure(L, l_PreGame_SetGameOption, 0);
    lua_setfield(L, -2, "SetGameOption");
    lua_pushcclosure(L, l_PreGame_ResetGameOptions, 0);
    lua_setfield(L, -2, "ResetGameOptions");
    lua_pushcclosure(L, l_PreGame_GetMapOption, 0);
    lua_setfield(L, -2, "GetMapOption");
    lua_pushcclosure(L, l_PreGame_SetMapOption, 0);
    lua_setfield(L, -2, "SetMapOption");
    lua_pushcclosure(L, l_PreGame_ResetMapOptions, 0);
    lua_setfield(L, -2, "ResetMapOptions");
    lua_pushcclosure(L, l_PreGame_ResetSlots, 0);
    lua_setfield(L, -2, "ResetSlots");
    lua_pushcclosure(L, l_PreGame_Reset, 0);
    lua_setfield(L, -2, "Reset");
    lua_pushcclosure(L, l_PreGame_GetFileHeader, 0);
    lua_setfield(L, -2, "GetFileHeader");
    lua_pushcclosure(L, l_PreGame_IsVictory, 0);
    lua_setfield(L, -2, "IsVictory");
    lua_pushcclosure(L, l_PreGame_SetVictory, 0);
    lua_setfield(L, -2, "SetVictory");
    lua_pushcclosure(L, l_PreGame_SetQuickCombat, 0);
    lua_setfield(L, -2, "SetQuickCombat");
    lua_pushcclosure(L, l_PreGame_GetQuickCombat, 0);
    lua_setfield(L, -2, "GetQuickCombat");
    lua_pushcclosure(L, l_PreGame_SetQuickMovement, 0);
    lua_setfield(L, -2, "SetQuickMovement");
    lua_pushcclosure(L, l_PreGame_GetQuickMovement, 0);
    lua_setfield(L, -2, "GetQuickMovement");
    lua_pushcclosure(L, l_PreGame_ReadActiveSlotCountFromSaveGame, 0);
    lua_setfield(L, -2, "ReadActiveSlotCountFromSaveGame");
    lua_pushcclosure(L, l_PreGame_IsDLCAllowed, 0);
    lua_setfield(L, -2, "IsDLCAllowed");
    lua_pushcclosure(L, l_PreGame_SetDLCAllowed, 0);
    lua_setfield(L, -2, "SetDLCAllowed");
    lua_pushcclosure(L, l_PreGame_ClearDLCAllowed, 0);
    lua_setfield(L, -2, "ClearDLCAllowed");
    lua_pushcclosure(L, l_PreGame_GameStarted, 0);
    lua_setfield(L, -2, "GameStarted");
    return 0;
}
