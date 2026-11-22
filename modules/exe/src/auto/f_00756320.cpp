#include "LuaApi.h"

// src: LIB [0x0088951c]
extern "C" void lua_pushstring(lua_State* L, const char* s);
// src: LIB [0x0088956a]
extern "C" void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
// src: LIB [0x0088955e]
extern "C" void lua_rawset(lua_State* L, int idx);

// src: GUESS (confidence: high) [0x00747850]
int Lua_SerialEventHexSelected_00747850(lua_State* L);
// src: GUESS (confidence: high) [0x00747890]
int Lua_SerialEventHexDeSelected_00747890(lua_State* L);
// src: GUESS (confidence: high) [0x007478d0]
int Lua_SerialEventMouseOverHex_007478d0(lua_State* L);
// src: GUESS (confidence: high) [0x00753e10]
int Lua_SerialEventTest_00753e10(lua_State* L);
// src: GUESS (confidence: high) [0x00753e50]
int Lua_SerialEventTestAnimations_00753e50(lua_State* L);
// src: GUESS (confidence: high) [0x00753e90]
int Lua_SerialEventStartGame_00753e90(lua_State* L);
// src: GUESS (confidence: high) [0x00753ed0]
int Lua_SerialEventCameraBack_00753ed0(lua_State* L);
// src: GUESS (confidence: high) [0x00753f10]
int Lua_SerialEventCameraStartMovingBack_00753f10(lua_State* L);
// src: GUESS (confidence: high) [0x00753f50]
int Lua_SerialEventCameraStopMovingBack_00753f50(lua_State* L);
// src: GUESS (confidence: high) [0x00753f90]
int Lua_SerialEventCameraForward_00753f90(lua_State* L);
// src: GUESS (confidence: high) [0x00753fd0]
int Lua_SerialEventCameraStartMovingForward_00753fd0(lua_State* L);
// src: GUESS (confidence: high) [0x00754010]
int Lua_SerialEventCameraStopMovingForward_00754010(lua_State* L);
// src: GUESS (confidence: high) [0x00754050]
int Lua_SerialEventCameraLeft_00754050(lua_State* L);
// src: GUESS (confidence: high) [0x00754090]
int Lua_SerialEventCameraStartMovingLeft_00754090(lua_State* L);
// src: GUESS (confidence: high) [0x007540d0]
int Lua_SerialEventCameraStopMovingLeft_007540d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754110]
int Lua_SerialEventCameraRight_00754110(lua_State* L);
// src: GUESS (confidence: high) [0x00754150]
int Lua_SerialEventCameraStartMovingRight_00754150(lua_State* L);
// src: GUESS (confidence: high) [0x00754190]
int Lua_SerialEventCameraStopMovingRight_00754190(lua_State* L);
// src: GUESS (confidence: high) [0x007541d0]
int Lua_CameraStartRotatingCW_007541d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754210]
int Lua_CameraStopRotatingCW_00754210(lua_State* L);
// src: GUESS (confidence: high) [0x00754250]
int Lua_CameraStartRotatingCCW_00754250(lua_State* L);
// src: GUESS (confidence: high) [0x00754290]
int Lua_CameraStopRotatingCCW_00754290(lua_State* L);
// src: GUESS (confidence: high) [0x007542d0]
int Lua_CameraStartPitchingUp_007542d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754310]
int Lua_CameraStopPitchingUp_00754310(lua_State* L);
// src: GUESS (confidence: high) [0x00754350]
int Lua_CameraStartPitchingDown_00754350(lua_State* L);
// src: GUESS (confidence: high) [0x00754390]
int Lua_CameraStopPitchingDown_00754390(lua_State* L);
// src: GUESS (confidence: high) [0x007543d0]
int Lua_SerialEventCameraIn_007543d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754410]
int Lua_SerialEventCameraOut_00754410(lua_State* L);
// src: GUESS (confidence: high) [0x00754450]
int Lua_SerialEventCameraSetCenterAndZoom_00754450(lua_State* L);
// src: GUESS (confidence: high) [0x00754490]
int Lua_SerialEventScreenShot_00754490(lua_State* L);
// src: GUESS (confidence: high) [0x00747910]
int Lua_SerialEventHexGridOn_00747910(lua_State* L);
// src: GUESS (confidence: high) [0x00747950]
int Lua_SerialEventHexGridOff_00747950(lua_State* L);
// src: GUESS (confidence: high) [0x00747990]
int Lua_SerialEventHexHighlight_00747990(lua_State* L);
// src: GUESS (confidence: high) [0x007544d0]
int Lua_SerialEventHexCultureChanged_007544d0(lua_State* L);
// src: GUESS (confidence: high) [0x007479d0]
int Lua_ClearHexHighlights_007479d0(lua_State* L);
// src: GUESS (confidence: high) [0x00747a10]
int Lua_ClearHexHighlightStyle_00747a10(lua_State* L);
// src: GUESS (confidence: high) [0x00754510]
int Lua_SerialEventTerrainOverlayMod_00754510(lua_State* L);
// src: GUESS (confidence: high) [0x00754550]
int Lua_SerialEventTerrainDecalCreated_00754550(lua_State* L);
// src: GUESS (confidence: high) [0x00754590]
int Lua_SerialEventEraChanged_00754590(lua_State* L);
// src: GUESS (confidence: high) [0x007545d0]
int Lua_SerialEventCityCreated_007545d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754610]
int Lua_CityRuinsCreated_00754610(lua_State* L);
// src: GUESS (confidence: high) [0x00754650]
int Lua_SerialEventCityCaptured_00754650(lua_State* L);
// src: GUESS (confidence: high) [0x00754690]
int Lua_SerialEventCityDestroyed_00754690(lua_State* L);
// src: GUESS (confidence: high) [0x007546d0]
int Lua_SerialEventCityCultureChanged_007546d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754710]
int Lua_SerialEventCityPopulationChanged_00754710(lua_State* L);
// src: GUESS (confidence: high) [0x00754750]
int Lua_SerialEventCitySetDamage_00754750(lua_State* L);
// src: GUESS (confidence: high) [0x00747a50]
int Lua_SerialEventEnterCityScreen_00747a50(lua_State* L);
// src: GUESS (confidence: high) [0x00747a90]
int Lua_SerialEventExitCityScreen_00747a90(lua_State* L);
// src: GUESS (confidence: high) [0x00747ad0]
int Lua_SerialEventBuildingSizeChanged_00747ad0(lua_State* L);
// src: GUESS (confidence: high) [0x00747b10]
int Lua_EventOpenOptionsScreen_00747b10(lua_State* L);
// src: GUESS (confidence: high) [0x00747b50]
int Lua_SerialEventCityContinentChanged_00747b50(lua_State* L);
// src: GUESS (confidence: high) [0x00754790]
int Lua_SerialEventRoadCreated_00754790(lua_State* L);
// src: GUESS (confidence: high) [0x007547d0]
int Lua_SerialEventRoadDestroyed_007547d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754810]
int Lua_SerialEventFeatureCreated_00754810(lua_State* L);
// src: GUESS (confidence: high) [0x00754850]
int Lua_SerialEventFeatureDestroyed_00754850(lua_State* L);
// src: GUESS (confidence: high) [0x00754890]
int Lua_SerialEventRawResourceCreated_00754890(lua_State* L);
// src: GUESS (confidence: high) [0x007548d0]
int Lua_SerialEventRawResourceDestroyed_007548d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754910]
int Lua_SerialEventRawResourceIconCreated_00754910(lua_State* L);
// src: GUESS (confidence: high) [0x00754950]
int Lua_SerialEventRawResourceIconDestroyed_00754950(lua_State* L);
// src: GUESS (confidence: high) [0x00754990]
int Lua_SerialEventImprovementCreated_00754990(lua_State* L);
// src: GUESS (confidence: high) [0x007549d0]
int Lua_SerialEventImprovementDestroyed_007549d0(lua_State* L);
// src: GUESS (confidence: high) [0x00754a10]
int Lua_SerialEventImprovementIconCreated_00754a10(lua_State* L);
// src: GUESS (confidence: high) [0x00754a50]
int Lua_SerialEventImprovementIconDestroyed_00754a50(lua_State* L);
// src: GUESS (confidence: high) [0x00754a90]
int Lua_SerialEventForestCreated_00754a90(lua_State* L);
// src: GUESS (confidence: high) [0x00754ad0]
int Lua_SerialEventForestRemoved_00754ad0(lua_State* L);
// src: GUESS (confidence: high) [0x00754b10]
int Lua_SerialEventJungleCreated_00754b10(lua_State* L);
// src: GUESS (confidence: high) [0x00754b50]
int Lua_SerialEventJungleRemoved_00754b50(lua_State* L);
// src: GUESS (confidence: high) [0x00754b90]
int Lua_SerialEventUnitCreated_00754b90(lua_State* L);
// src: GUESS (confidence: high) [0x00754bd0]
int Lua_SerialEventUnitDestroyed_00754bd0(lua_State* L);
// src: GUESS (confidence: high) [0x00754c10]
int Lua_UnitVisibilityChanged_00754c10(lua_State* L);
// src: GUESS (confidence: high) [0x00747b90]
int Lua_UnitHexHighlight_00747b90(lua_State* L);
// src: GUESS (confidence: high) [0x00754c50]
int Lua_SerialEventUnitSetDamage_00754c50(lua_State* L);
// src: GUESS (confidence: high) [0x00754c90]
int Lua_UnitActionChanged_00754c90(lua_State* L);
// src: GUESS (confidence: high) [0x00754cd0]
int Lua_UnitEmbark_00754cd0(lua_State* L);
// src: GUESS (confidence: high) [0x00754d10]
int Lua_UnitGarrison_00754d10(lua_State* L);
// src: GUESS (confidence: high) [0x00754d50]
int Lua_UnitShouldDimFlag_00754d50(lua_State* L);
// src: GUESS (confidence: high) [0x00754d90]
int Lua_UnitMarkThreatening_00754d90(lua_State* L);
// src: GUESS (confidence: high) [0x00754dd0]
int Lua_SerialEventUnitMoveToHexes_00754dd0(lua_State* L);
// src: GUESS (confidence: high) [0x00754e10]
int Lua_SerialEventUnitMove_00754e10(lua_State* L);
// src: GUESS (confidence: high) [0x00754e50]
int Lua_SerialEventUnitTeleportedToHex_00754e50(lua_State* L);
// src: GUESS (confidence: high) [0x00754e90]
int Lua_SerialEventUnitFacingChanged_00754e90(lua_State* L);
// src: GUESS (confidence: high) [0x00754ed0]
int Lua_UnitNameChanged_00754ed0(lua_State* L);
// src: GUESS (confidence: high) [0x00754f10]
int Lua_UnitSelectionChanged_00754f10(lua_State* L);
// src: GUESS (confidence: high) [0x00754f50]
int Lua_UnitSelectionCleared_00754f50(lua_State* L);
// src: GUESS (confidence: high) [0x00754f90]
int Lua_GoldenAgeStarted_00754f90(lua_State* L);
// src: GUESS (confidence: high) [0x00754fd0]
int Lua_GoldenAgeEnded_00754fd0(lua_State* L);
// src: GUESS (confidence: high) [0x00755010]
int Lua_UnitFlagUpdated_00755010(lua_State* L);
// src: GUESS (confidence: high) [0x00755050]
int Lua_UnitDataEdited_00755050(lua_State* L);
// src: GUESS (confidence: high) [0x00755090]
int Lua_UnitDataRequested_00755090(lua_State* L);
// src: GUESS (confidence: high) [0x007550d0]
int Lua_UnitDebugFSM_007550d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755110]
int Lua_GameOptionsChanged_00755110(lua_State* L);
// src: GUESS (confidence: high) [0x00755150]
int Lua_GraphicsOptionsChanged_00755150(lua_State* L);
// src: GUESS (confidence: high) [0x00747bd0]
int Lua_SerialEventLeaderToggleDebugCam_00747bd0(lua_State* L);
// src: GUESS (confidence: high) [0x00747c10]
int Lua_SerialEventUnitFlagSelected_00747c10(lua_State* L);
// src: GUESS (confidence: high) [0x00755190]
int Lua_SerialEventGameMessagePopup_00755190(lua_State* L);
// src: GUESS (confidence: high) [0x007551d0]
int Lua_SerialEventGameMessagePopupShown_007551d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755210]
int Lua_SerialEventGameMessagePopupProcessed_00755210(lua_State* L);
// src: GUESS (confidence: high) [0x00747c50]
int Lua_SerialEventDawnOfManShow_00747c50(lua_State* L);
// src: GUESS (confidence: high) [0x00747c90]
int Lua_SerialEventDawnOfManHide_00747c90(lua_State* L);
// src: GUESS (confidence: high) [0x00755250]
int Lua_HexFOWStateChanged_00755250(lua_State* L);
// src: GUESS (confidence: high) [0x00755290]
int Lua_GameplayAlertMessage_00755290(lua_State* L);
// src: GUESS (confidence: high) [0x00747cd0]
int Lua_InterfaceModeChanged_00747cd0(lua_State* L);
// src: GUESS (confidence: high) [0x007552d0]
int Lua_HexYieldMightHaveChanged_007552d0(lua_State* L);
// src: GUESS (confidence: high) [0x00747d10]
int Lua_ExitToMainMenu_00747d10(lua_State* L);
// src: GUESS (confidence: high) [0x00755310]
int Lua_NotificationAdded_00755310(lua_State* L);
// src: GUESS (confidence: high) [0x00755350]
int Lua_NotificationRemoved_00755350(lua_State* L);
// src: GUESS (confidence: high) [0x00755390]
int Lua_NotificationActivated_00755390(lua_State* L);
// src: GUESS (confidence: high) [0x007553d0]
int Lua_ActivePlayerTurnStart_007553d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755410]
int Lua_ActivePlayerTurnEnd_00755410(lua_State* L);
// src: GUESS (confidence: high) [0x00755450]
int Lua_RemotePlayerTurnStart_00755450(lua_State* L);
// src: GUESS (confidence: high) [0x00755490]
int Lua_RemotePlayerTurnEnd_00755490(lua_State* L);
// src: GUESS (confidence: high) [0x007554d0]
int Lua_TechAcquired_007554d0(lua_State* L);
// src: GUESS (confidence: high) [0x00747d50]
int Lua_PlayerChoseToLoadGame_00747d50(lua_State* L);
// src: GUESS (confidence: high) [0x00747d90]
int Lua_PlayerChoseToLoadMap_00747d90(lua_State* L);
// src: GUESS (confidence: high) [0x00747dd0]
int Lua_UIPathFinderUpdate_00747dd0(lua_State* L);
// src: GUESS (confidence: high) [0x00747e10]
int Lua_DisplayMovementIndicator_00747e10(lua_State* L);
// src: GUESS (confidence: high) [0x00755510]
int Lua_NotifyAILeaderInGame_00755510(lua_State* L);
// src: GUESS (confidence: high) [0x00755550]
int Lua_AILeaderMessage_00755550(lua_State* L);
// src: GUESS (confidence: high) [0x00755590]
int Lua_TeamMet_00755590(lua_State* L);
// src: GUESS (confidence: high) [0x007555d0]
int Lua_WarStateChanged_007555d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755610]
int Lua_SerialEventCityScreenDirty_00755610(lua_State* L);
// src: GUESS (confidence: high) [0x00755650]
int Lua_SerialEventCityInfoDirty_00755650(lua_State* L);
// src: GUESS (confidence: high) [0x00755690]
int Lua_SerialEventCityHexHighlightDirty_00755690(lua_State* L);
// src: GUESS (confidence: high) [0x007556d0]
int Lua_EventPoliciesDirty_007556d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755710]
int Lua_SerialEventInfoPaneDirty_00755710(lua_State* L);
// src: GUESS (confidence: high) [0x00755750]
int Lua_SerialEventUnitInfoDirty_00755750(lua_State* L);
// src: GUESS (confidence: high) [0x00755790]
int Lua_SerialEventGameDataDirty_00755790(lua_State* L);
// src: GUESS (confidence: high) [0x007557d0]
int Lua_SerialEventTurnTimerDirty_007557d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755810]
int Lua_SerialEventResearchDirty_00755810(lua_State* L);
// src: GUESS (confidence: high) [0x00755850]
int Lua_SerialEventEndTurnDirty_00755850(lua_State* L);
// src: GUESS (confidence: high) [0x00755890]
int Lua_SerialEventScoreDirty_00755890(lua_State* L);
// src: GUESS (confidence: high) [0x007558d0]
int Lua_SerialEventEspionageScreenDirty_007558d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755910]
int Lua_SerialEventLeagueScreenDirty_00755910(lua_State* L);
// src: GUESS (confidence: high) [0x00755950]
int Lua_SerialEventGreatWorksScreenDirty_00755950(lua_State* L);
// src: GUESS (confidence: high) [0x00755990]
int Lua_EndTurnBlockingChanged_00755990(lua_State* L);
// src: GUESS (confidence: high) [0x007559d0]
int Lua_SpecificCityInfoDirty_007559d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755a10]
int Lua_ClearDiplomacyTradeTable_00755a10(lua_State* L);
// src: GUESS (confidence: high) [0x00755a50]
int Lua_ShowMovementRange_00755a50(lua_State* L);
// src: GUESS (confidence: high) [0x00755a90]
int Lua_ShowAttackTargets_00755a90(lua_State* L);
// src: GUESS (confidence: high) [0x00747e50]
int Lua_SpawnArrowEvent_00747e50(lua_State* L);
// src: GUESS (confidence: high) [0x00747e90]
int Lua_RemoveAllArrowsEvent_00747e90(lua_State* L);
// src: GUESS (confidence: high) [0x00755ad0]
int Lua_AdvisorDisplayShow_00755ad0(lua_State* L);
// src: GUESS (confidence: high) [0x00755b10]
int Lua_AdvisorDisplayHide_00755b10(lua_State* L);
// src: GUESS (confidence: high) [0x00755b50]
int Lua_EndGameShow_00755b50(lua_State* L);
// src: GUESS (confidence: high) [0x00755b90]
int Lua_TaskListUpdate_00755b90(lua_State* L);
// src: GUESS (confidence: high) [0x00747ed0]
int Lua_EndTurnTimerUpdate_00747ed0(lua_State* L);
// src: GUESS (confidence: high) [0x00755bd0]
int Lua_AddPopupTextEvent_00755bd0(lua_State* L);
// src: GUESS (confidence: high) [0x00747f10]
int Lua_MultiplayerConnectionComplete_00747f10(lua_State* L);
// src: GUESS (confidence: high) [0x00747f50]
int Lua_MultiplayerConnectionFailed_00747f50(lua_State* L);
// src: GUESS (confidence: high) [0x00747f90]
int Lua_MultiplayerJoinRoomAttempt_00747f90(lua_State* L);
// src: GUESS (confidence: high) [0x00747fd0]
int Lua_MultiplayerJoinRoomComplete_00747fd0(lua_State* L);
// src: GUESS (confidence: high) [0x00748010]
int Lua_MultiplayerJoinRoomFailed_00748010(lua_State* L);
// src: GUESS (confidence: high) [0x00748050]
int Lua_MultiplayerGameLobbyInvite_00748050(lua_State* L);
// src: GUESS (confidence: high) [0x00748090]
int Lua_MultiplayerGameServerInvite_00748090(lua_State* L);
// src: GUESS (confidence: high) [0x007480d0]
int Lua_MultiplayerGameLaunched_007480d0(lua_State* L);
// src: GUESS (confidence: high) [0x00748110]
int Lua_MultiplayerProfileDisconnected_00748110(lua_State* L);
// src: GUESS (confidence: high) [0x00748150]
int Lua_MultiplayerProfileFailed_00748150(lua_State* L);
// src: GUESS (confidence: high) [0x00748190]
int Lua_MultiplayerGameListClear_00748190(lua_State* L);
// src: GUESS (confidence: high) [0x007481d0]
int Lua_MultiplayerGameListUpdated_007481d0(lua_State* L);
// src: GUESS (confidence: high) [0x00748210]
int Lua_MultiplayerGameListComplete_00748210(lua_State* L);
// src: GUESS (confidence: high) [0x00748250]
int Lua_MultiplayerNetRegistered_00748250(lua_State* L);
// src: GUESS (confidence: high) [0x00748290]
int Lua_MultiplayerGamePlayerUpdated_00748290(lua_State* L);
// src: GUESS (confidence: high) [0x007482d0]
int Lua_MultiplayerGameAbandoned_007482d0(lua_State* L);
// src: GUESS (confidence: high) [0x00748310]
int Lua_MultiplayerGameLastPlayer_00748310(lua_State* L);
// src: GUESS (confidence: high) [0x00748350]
int Lua_ConnectedToNetworkHost_00748350(lua_State* L);
// src: GUESS (confidence: high) [0x00755c10]
int Lua_PreGameDirty_00755c10(lua_State* L);
// src: GUESS (confidence: high) [0x00748390]
int Lua_MultiplayerGamePlayerDisconnected_00748390(lua_State* L);
// src: GUESS (confidence: high) [0x007483d0]
int Lua_MultiplayerGameHostMigration_007483d0(lua_State* L);
// src: GUESS (confidence: high) [0x00748410]
int Lua_MultiplayerPingTimesChanged_00748410(lua_State* L);
// src: GUESS (confidence: high) [0x00748450]
int Lua_MultiplayerHotJoinStarted_00748450(lua_State* L);
// src: GUESS (confidence: high) [0x00748490]
int Lua_MultiplayerHotJoinCompleted_00748490(lua_State* L);
// src: GUESS (confidence: high) [0x00755c50]
int Lua_SearchForPediaEntry_00755c50(lua_State* L);
// src: GUESS (confidence: high) [0x00755c90]
int Lua_GoToPediaHomePage_00755c90(lua_State* L);
// src: GUESS (confidence: high) [0x00755cd0]
int Lua_GameplaySetActivePlayer_00755cd0(lua_State* L);
// src: GUESS (confidence: high) [0x007484d0]
int Lua_GameMessageChat_007484d0(lua_State* L);
// src: GUESS (confidence: high) [0x00755d10]
int Lua_OpenPlayerDealScreenEvent_00755d10(lua_State* L);
// src: GUESS (confidence: high) [0x00755d50]
int Lua_OpenInfoCorner_00755d50(lua_State* L);
// src: GUESS (confidence: high) [0x00755d90]
int Lua_NaturalWonderRevealed_00755d90(lua_State* L);
// src: GUESS (confidence: high) [0x00755dd0]
int Lua_GameplayFX_00755dd0(lua_State* L);
// src: GUESS (confidence: high) [0x00755e10]
int Lua_UnitMoveQueueChanged_00755e10(lua_State* L);
// src: GUESS (confidence: high) [0x00748510]
int Lua_FrontEndPopup_00748510(lua_State* L);
// src: GUESS (confidence: high) [0x00755e50]
int Lua_GenericWorldAnchor_00755e50(lua_State* L);
// src: GUESS (confidence: high) [0x00748550]
int Lua_LoadScreenClose_00748550(lua_State* L);
// src: GUESS (confidence: high) [0x00755e90]
int Lua_InitCityRangeStrike_00755e90(lua_State* L);
// src: GUESS (confidence: high) [0x00755ed0]
int Lua_ShowPlayerChangeUI_00755ed0(lua_State* L);
// src: GUESS (confidence: high) [0x00755f10]
int Lua_NewGameTurn_00755f10(lua_State* L);

// src: GUESS (confidence: high) [0x00756320]
int RegisterLuaEvents_00756320(lua_State* L)
{
    lua_pushstring(L, "SerialEventHexSelected");
    lua_pushcclosure(L, Lua_SerialEventHexSelected_00747850, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventHexDeSelected");
    lua_pushcclosure(L, Lua_SerialEventHexDeSelected_00747890, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventMouseOverHex");
    lua_pushcclosure(L, Lua_SerialEventMouseOverHex_007478d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventTest");
    lua_pushcclosure(L, Lua_SerialEventTest_00753e10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventTestAnimations");
    lua_pushcclosure(L, Lua_SerialEventTestAnimations_00753e50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventStartGame");
    lua_pushcclosure(L, Lua_SerialEventStartGame_00753e90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraBack");
    lua_pushcclosure(L, Lua_SerialEventCameraBack_00753ed0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStartMovingBack");
    lua_pushcclosure(L, Lua_SerialEventCameraStartMovingBack_00753f10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStopMovingBack");
    lua_pushcclosure(L, Lua_SerialEventCameraStopMovingBack_00753f50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraForward");
    lua_pushcclosure(L, Lua_SerialEventCameraForward_00753f90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStartMovingForward");
    lua_pushcclosure(L, Lua_SerialEventCameraStartMovingForward_00753fd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStopMovingForward");
    lua_pushcclosure(L, Lua_SerialEventCameraStopMovingForward_00754010, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraLeft");
    lua_pushcclosure(L, Lua_SerialEventCameraLeft_00754050, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStartMovingLeft");
    lua_pushcclosure(L, Lua_SerialEventCameraStartMovingLeft_00754090, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStopMovingLeft");
    lua_pushcclosure(L, Lua_SerialEventCameraStopMovingLeft_007540d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraRight");
    lua_pushcclosure(L, Lua_SerialEventCameraRight_00754110, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStartMovingRight");
    lua_pushcclosure(L, Lua_SerialEventCameraStartMovingRight_00754150, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraStopMovingRight");
    lua_pushcclosure(L, Lua_SerialEventCameraStopMovingRight_00754190, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStartRotatingCW");
    lua_pushcclosure(L, Lua_CameraStartRotatingCW_007541d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStopRotatingCW");
    lua_pushcclosure(L, Lua_CameraStopRotatingCW_00754210, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStartRotatingCCW");
    lua_pushcclosure(L, Lua_CameraStartRotatingCCW_00754250, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStopRotatingCCW");
    lua_pushcclosure(L, Lua_CameraStopRotatingCCW_00754290, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStartPitchingUp");
    lua_pushcclosure(L, Lua_CameraStartPitchingUp_007542d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStopPitchingUp");
    lua_pushcclosure(L, Lua_CameraStopPitchingUp_00754310, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStartPitchingDown");
    lua_pushcclosure(L, Lua_CameraStartPitchingDown_00754350, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CameraStopPitchingDown");
    lua_pushcclosure(L, Lua_CameraStopPitchingDown_00754390, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraIn");
    lua_pushcclosure(L, Lua_SerialEventCameraIn_007543d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraOut");
    lua_pushcclosure(L, Lua_SerialEventCameraOut_00754410, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCameraSetCenterAndZoom");
    lua_pushcclosure(L, Lua_SerialEventCameraSetCenterAndZoom_00754450, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventScreenShot");
    lua_pushcclosure(L, Lua_SerialEventScreenShot_00754490, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventHexGridOn");
    lua_pushcclosure(L, Lua_SerialEventHexGridOn_00747910, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventHexGridOff");
    lua_pushcclosure(L, Lua_SerialEventHexGridOff_00747950, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventHexHighlight");
    lua_pushcclosure(L, Lua_SerialEventHexHighlight_00747990, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventHexCultureChanged");
    lua_pushcclosure(L, Lua_SerialEventHexCultureChanged_007544d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ClearHexHighlights");
    lua_pushcclosure(L, Lua_ClearHexHighlights_007479d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ClearHexHighlightStyle");
    lua_pushcclosure(L, Lua_ClearHexHighlightStyle_00747a10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventTerrainOverlayMod");
    lua_pushcclosure(L, Lua_SerialEventTerrainOverlayMod_00754510, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventTerrainDecalCreated");
    lua_pushcclosure(L, Lua_SerialEventTerrainDecalCreated_00754550, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventEraChanged");
    lua_pushcclosure(L, Lua_SerialEventEraChanged_00754590, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityCreated");
    lua_pushcclosure(L, Lua_SerialEventCityCreated_007545d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "CityRuinsCreated");
    lua_pushcclosure(L, Lua_CityRuinsCreated_00754610, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityCaptured");
    lua_pushcclosure(L, Lua_SerialEventCityCaptured_00754650, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityDestroyed");
    lua_pushcclosure(L, Lua_SerialEventCityDestroyed_00754690, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityCultureChanged");
    lua_pushcclosure(L, Lua_SerialEventCityCultureChanged_007546d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityPopulationChanged");
    lua_pushcclosure(L, Lua_SerialEventCityPopulationChanged_00754710, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCitySetDamage");
    lua_pushcclosure(L, Lua_SerialEventCitySetDamage_00754750, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventEnterCityScreen");
    lua_pushcclosure(L, Lua_SerialEventEnterCityScreen_00747a50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventExitCityScreen");
    lua_pushcclosure(L, Lua_SerialEventExitCityScreen_00747a90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventBuildingSizeChanged");
    lua_pushcclosure(L, Lua_SerialEventBuildingSizeChanged_00747ad0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "EventOpenOptionsScreen");
    lua_pushcclosure(L, Lua_EventOpenOptionsScreen_00747b10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityContinentChanged");
    lua_pushcclosure(L, Lua_SerialEventCityContinentChanged_00747b50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventRoadCreated");
    lua_pushcclosure(L, Lua_SerialEventRoadCreated_00754790, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventRoadDestroyed");
    lua_pushcclosure(L, Lua_SerialEventRoadDestroyed_007547d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventFeatureCreated");
    lua_pushcclosure(L, Lua_SerialEventFeatureCreated_00754810, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventFeatureDestroyed");
    lua_pushcclosure(L, Lua_SerialEventFeatureDestroyed_00754850, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventRawResourceCreated");
    lua_pushcclosure(L, Lua_SerialEventRawResourceCreated_00754890, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventRawResourceDestroyed");
    lua_pushcclosure(L, Lua_SerialEventRawResourceDestroyed_007548d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventRawResourceIconCreated");
    lua_pushcclosure(L, Lua_SerialEventRawResourceIconCreated_00754910, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventRawResourceIconDestroyed");
    lua_pushcclosure(L, Lua_SerialEventRawResourceIconDestroyed_00754950, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventImprovementCreated");
    lua_pushcclosure(L, Lua_SerialEventImprovementCreated_00754990, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventImprovementDestroyed");
    lua_pushcclosure(L, Lua_SerialEventImprovementDestroyed_007549d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventImprovementIconCreated");
    lua_pushcclosure(L, Lua_SerialEventImprovementIconCreated_00754a10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventImprovementIconDestroyed");
    lua_pushcclosure(L, Lua_SerialEventImprovementIconDestroyed_00754a50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventForestCreated");
    lua_pushcclosure(L, Lua_SerialEventForestCreated_00754a90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventForestRemoved");
    lua_pushcclosure(L, Lua_SerialEventForestRemoved_00754ad0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventJungleCreated");
    lua_pushcclosure(L, Lua_SerialEventJungleCreated_00754b10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventJungleRemoved");
    lua_pushcclosure(L, Lua_SerialEventJungleRemoved_00754b50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitCreated");
    lua_pushcclosure(L, Lua_SerialEventUnitCreated_00754b90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitDestroyed");
    lua_pushcclosure(L, Lua_SerialEventUnitDestroyed_00754bd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitVisibilityChanged");
    lua_pushcclosure(L, Lua_UnitVisibilityChanged_00754c10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitHexHighlight");
    lua_pushcclosure(L, Lua_UnitHexHighlight_00747b90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitSetDamage");
    lua_pushcclosure(L, Lua_SerialEventUnitSetDamage_00754c50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitActionChanged");
    lua_pushcclosure(L, Lua_UnitActionChanged_00754c90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitEmbark");
    lua_pushcclosure(L, Lua_UnitEmbark_00754cd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitGarrison");
    lua_pushcclosure(L, Lua_UnitGarrison_00754d10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitShouldDimFlag");
    lua_pushcclosure(L, Lua_UnitShouldDimFlag_00754d50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitMarkThreatening");
    lua_pushcclosure(L, Lua_UnitMarkThreatening_00754d90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitMoveToHexes");
    lua_pushcclosure(L, Lua_SerialEventUnitMoveToHexes_00754dd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitMove");
    lua_pushcclosure(L, Lua_SerialEventUnitMove_00754e10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitTeleportedToHex");
    lua_pushcclosure(L, Lua_SerialEventUnitTeleportedToHex_00754e50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitFacingChanged");
    lua_pushcclosure(L, Lua_SerialEventUnitFacingChanged_00754e90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitNameChanged");
    lua_pushcclosure(L, Lua_UnitNameChanged_00754ed0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitSelectionChanged");
    lua_pushcclosure(L, Lua_UnitSelectionChanged_00754f10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitSelectionCleared");
    lua_pushcclosure(L, Lua_UnitSelectionCleared_00754f50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GoldenAgeStarted");
    lua_pushcclosure(L, Lua_GoldenAgeStarted_00754f90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GoldenAgeEnded");
    lua_pushcclosure(L, Lua_GoldenAgeEnded_00754fd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitFlagUpdated");
    lua_pushcclosure(L, Lua_UnitFlagUpdated_00755010, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitDataEdited");
    lua_pushcclosure(L, Lua_UnitDataEdited_00755050, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitDataRequested");
    lua_pushcclosure(L, Lua_UnitDataRequested_00755090, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitDebugFSM");
    lua_pushcclosure(L, Lua_UnitDebugFSM_007550d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GameOptionsChanged");
    lua_pushcclosure(L, Lua_GameOptionsChanged_00755110, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GraphicsOptionsChanged");
    lua_pushcclosure(L, Lua_GraphicsOptionsChanged_00755150, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventLeaderToggleDebugCam");
    lua_pushcclosure(L, Lua_SerialEventLeaderToggleDebugCam_00747bd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitFlagSelected");
    lua_pushcclosure(L, Lua_SerialEventUnitFlagSelected_00747c10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventGameMessagePopup");
    lua_pushcclosure(L, Lua_SerialEventGameMessagePopup_00755190, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventGameMessagePopupShown");
    lua_pushcclosure(L, Lua_SerialEventGameMessagePopupShown_007551d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventGameMessagePopupProcessed");
    lua_pushcclosure(L, Lua_SerialEventGameMessagePopupProcessed_00755210, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventDawnOfManShow");
    lua_pushcclosure(L, Lua_SerialEventDawnOfManShow_00747c50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventDawnOfManHide");
    lua_pushcclosure(L, Lua_SerialEventDawnOfManHide_00747c90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "HexFOWStateChanged");
    lua_pushcclosure(L, Lua_HexFOWStateChanged_00755250, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GameplayAlertMessage");
    lua_pushcclosure(L, Lua_GameplayAlertMessage_00755290, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "InterfaceModeChanged");
    lua_pushcclosure(L, Lua_InterfaceModeChanged_00747cd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "HexYieldMightHaveChanged");
    lua_pushcclosure(L, Lua_HexYieldMightHaveChanged_007552d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ExitToMainMenu");
    lua_pushcclosure(L, Lua_ExitToMainMenu_00747d10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "NotificationAdded");
    lua_pushcclosure(L, Lua_NotificationAdded_00755310, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "NotificationRemoved");
    lua_pushcclosure(L, Lua_NotificationRemoved_00755350, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "NotificationActivated");
    lua_pushcclosure(L, Lua_NotificationActivated_00755390, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ActivePlayerTurnStart");
    lua_pushcclosure(L, Lua_ActivePlayerTurnStart_007553d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ActivePlayerTurnEnd");
    lua_pushcclosure(L, Lua_ActivePlayerTurnEnd_00755410, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "RemotePlayerTurnStart");
    lua_pushcclosure(L, Lua_RemotePlayerTurnStart_00755450, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "RemotePlayerTurnEnd");
    lua_pushcclosure(L, Lua_RemotePlayerTurnEnd_00755490, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "TechAcquired");
    lua_pushcclosure(L, Lua_TechAcquired_007554d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "PlayerChoseToLoadGame");
    lua_pushcclosure(L, Lua_PlayerChoseToLoadGame_00747d50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "PlayerChoseToLoadMap");
    lua_pushcclosure(L, Lua_PlayerChoseToLoadMap_00747d90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UIPathFinderUpdate");
    lua_pushcclosure(L, Lua_UIPathFinderUpdate_00747dd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "DisplayMovementIndicator");
    lua_pushcclosure(L, Lua_DisplayMovementIndicator_00747e10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "NotifyAILeaderInGame");
    lua_pushcclosure(L, Lua_NotifyAILeaderInGame_00755510, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "AILeaderMessage");
    lua_pushcclosure(L, Lua_AILeaderMessage_00755550, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "TeamMet");
    lua_pushcclosure(L, Lua_TeamMet_00755590, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "WarStateChanged");
    lua_pushcclosure(L, Lua_WarStateChanged_007555d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityScreenDirty");
    lua_pushcclosure(L, Lua_SerialEventCityScreenDirty_00755610, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityInfoDirty");
    lua_pushcclosure(L, Lua_SerialEventCityInfoDirty_00755650, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventCityHexHighlightDirty");
    lua_pushcclosure(L, Lua_SerialEventCityHexHighlightDirty_00755690, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "EventPoliciesDirty");
    lua_pushcclosure(L, Lua_EventPoliciesDirty_007556d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventInfoPaneDirty");
    lua_pushcclosure(L, Lua_SerialEventInfoPaneDirty_00755710, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventUnitInfoDirty");
    lua_pushcclosure(L, Lua_SerialEventUnitInfoDirty_00755750, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventGameDataDirty");
    lua_pushcclosure(L, Lua_SerialEventGameDataDirty_00755790, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventTurnTimerDirty");
    lua_pushcclosure(L, Lua_SerialEventTurnTimerDirty_007557d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventResearchDirty");
    lua_pushcclosure(L, Lua_SerialEventResearchDirty_00755810, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventEndTurnDirty");
    lua_pushcclosure(L, Lua_SerialEventEndTurnDirty_00755850, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventScoreDirty");
    lua_pushcclosure(L, Lua_SerialEventScoreDirty_00755890, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventEspionageScreenDirty");
    lua_pushcclosure(L, Lua_SerialEventEspionageScreenDirty_007558d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventLeagueScreenDirty");
    lua_pushcclosure(L, Lua_SerialEventLeagueScreenDirty_00755910, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SerialEventGreatWorksScreenDirty");
    lua_pushcclosure(L, Lua_SerialEventGreatWorksScreenDirty_00755950, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "EndTurnBlockingChanged");
    lua_pushcclosure(L, Lua_EndTurnBlockingChanged_00755990, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SpecificCityInfoDirty");
    lua_pushcclosure(L, Lua_SpecificCityInfoDirty_007559d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ClearDiplomacyTradeTable");
    lua_pushcclosure(L, Lua_ClearDiplomacyTradeTable_00755a10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ShowMovementRange");
    lua_pushcclosure(L, Lua_ShowMovementRange_00755a50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ShowAttackTargets");
    lua_pushcclosure(L, Lua_ShowAttackTargets_00755a90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SpawnArrowEvent");
    lua_pushcclosure(L, Lua_SpawnArrowEvent_00747e50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "RemoveAllArrowsEvent");
    lua_pushcclosure(L, Lua_RemoveAllArrowsEvent_00747e90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "AdvisorDisplayShow");
    lua_pushcclosure(L, Lua_AdvisorDisplayShow_00755ad0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "AdvisorDisplayHide");
    lua_pushcclosure(L, Lua_AdvisorDisplayHide_00755b10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "EndGameShow");
    lua_pushcclosure(L, Lua_EndGameShow_00755b50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "TaskListUpdate");
    lua_pushcclosure(L, Lua_TaskListUpdate_00755b90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "EndTurnTimerUpdate");
    lua_pushcclosure(L, Lua_EndTurnTimerUpdate_00747ed0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "AddPopupTextEvent");
    lua_pushcclosure(L, Lua_AddPopupTextEvent_00755bd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerConnectionComplete");
    lua_pushcclosure(L, Lua_MultiplayerConnectionComplete_00747f10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerConnectionFailed");
    lua_pushcclosure(L, Lua_MultiplayerConnectionFailed_00747f50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerJoinRoomAttempt");
    lua_pushcclosure(L, Lua_MultiplayerJoinRoomAttempt_00747f90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerJoinRoomComplete");
    lua_pushcclosure(L, Lua_MultiplayerJoinRoomComplete_00747fd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerJoinRoomFailed");
    lua_pushcclosure(L, Lua_MultiplayerJoinRoomFailed_00748010, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameLobbyInvite");
    lua_pushcclosure(L, Lua_MultiplayerGameLobbyInvite_00748050, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameServerInvite");
    lua_pushcclosure(L, Lua_MultiplayerGameServerInvite_00748090, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameLaunched");
    lua_pushcclosure(L, Lua_MultiplayerGameLaunched_007480d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerProfileDisconnected");
    lua_pushcclosure(L, Lua_MultiplayerProfileDisconnected_00748110, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerProfileFailed");
    lua_pushcclosure(L, Lua_MultiplayerProfileFailed_00748150, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameListClear");
    lua_pushcclosure(L, Lua_MultiplayerGameListClear_00748190, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameListUpdated");
    lua_pushcclosure(L, Lua_MultiplayerGameListUpdated_007481d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameListComplete");
    lua_pushcclosure(L, Lua_MultiplayerGameListComplete_00748210, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerNetRegistered");
    lua_pushcclosure(L, Lua_MultiplayerNetRegistered_00748250, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGamePlayerUpdated");
    lua_pushcclosure(L, Lua_MultiplayerGamePlayerUpdated_00748290, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameAbandoned");
    lua_pushcclosure(L, Lua_MultiplayerGameAbandoned_007482d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameLastPlayer");
    lua_pushcclosure(L, Lua_MultiplayerGameLastPlayer_00748310, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ConnectedToNetworkHost");
    lua_pushcclosure(L, Lua_ConnectedToNetworkHost_00748350, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "PreGameDirty");
    lua_pushcclosure(L, Lua_PreGameDirty_00755c10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGamePlayerDisconnected");
    lua_pushcclosure(L, Lua_MultiplayerGamePlayerDisconnected_00748390, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerGameHostMigration");
    lua_pushcclosure(L, Lua_MultiplayerGameHostMigration_007483d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerPingTimesChanged");
    lua_pushcclosure(L, Lua_MultiplayerPingTimesChanged_00748410, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerHotJoinStarted");
    lua_pushcclosure(L, Lua_MultiplayerHotJoinStarted_00748450, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "MultiplayerHotJoinCompleted");
    lua_pushcclosure(L, Lua_MultiplayerHotJoinCompleted_00748490, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "SearchForPediaEntry");
    lua_pushcclosure(L, Lua_SearchForPediaEntry_00755c50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GoToPediaHomePage");
    lua_pushcclosure(L, Lua_GoToPediaHomePage_00755c90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GameplaySetActivePlayer");
    lua_pushcclosure(L, Lua_GameplaySetActivePlayer_00755cd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GameMessageChat");
    lua_pushcclosure(L, Lua_GameMessageChat_007484d0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "OpenPlayerDealScreenEvent");
    lua_pushcclosure(L, Lua_OpenPlayerDealScreenEvent_00755d10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "OpenInfoCorner");
    lua_pushcclosure(L, Lua_OpenInfoCorner_00755d50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "NaturalWonderRevealed");
    lua_pushcclosure(L, Lua_NaturalWonderRevealed_00755d90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GameplayFX");
    lua_pushcclosure(L, Lua_GameplayFX_00755dd0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "UnitMoveQueueChanged");
    lua_pushcclosure(L, Lua_UnitMoveQueueChanged_00755e10, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "FrontEndPopup");
    lua_pushcclosure(L, Lua_FrontEndPopup_00748510, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "GenericWorldAnchor");
    lua_pushcclosure(L, Lua_GenericWorldAnchor_00755e50, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "LoadScreenClose");
    lua_pushcclosure(L, Lua_LoadScreenClose_00748550, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "InitCityRangeStrike");
    lua_pushcclosure(L, Lua_InitCityRangeStrike_00755e90, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "ShowPlayerChangeUI");
    lua_pushcclosure(L, Lua_ShowPlayerChangeUI_00755ed0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "NewGameTurn");
    lua_pushcclosure(L, Lua_NewGameTurn_00755f10, 0);
    lua_rawset(L, -3);
    return 0;
}
