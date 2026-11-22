#include "LuaApi.h"

// src: LIB [0x0088956a]
extern "C" void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
// src: LIB [0x00889528]
extern "C" void lua_setfield(lua_State* L, int idx, const char* k);

// src: GUESS (confidence: high) [0x0075ab50]
int Lua_LookAtSelectionPlot_0075ab50(lua_State* L);
// src: GUESS (confidence: high) [0x0075ab90]
int Lua_CanDoInterfaceMode_0075ab90(lua_State* L);
// src: GUESS (confidence: high) [0x0075c2e0]
int Lua_GetSelectionPlot_0075c2e0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c350]
int Lua_GetHeadSelectedUnit_0075c350(lua_State* L);
// src: GUESS (confidence: high) [0x0075c3f0]
int Lua_GetSelectedUnitID_0075c3f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c450]
int Lua_SelectUnit_0075c450(lua_State* L);
// src: GUESS (confidence: high) [0x0075c520]
int Lua_SelectGroup_0075c520(lua_State* L);
// src: GUESS (confidence: high) [0x0075c5e0]
int Lua_SelectAll_0075c5e0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c660]
int Lua_RemoveFromSelectionList_0075c660(lua_State* L);
// src: GUESS (confidence: high) [0x0075b8b0]
int Lua_MakeSelectionListDirty_0075b8b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b8d0]
int Lua_CanSelectionListFound_0075b8d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b900]
int Lua_CanSelectionListWork_0075b900(lua_State* L);
// src: GUESS (confidence: high) [0x0075b930]
int Lua_IsPopupUp_0075b930(lua_State* L);
// src: GUESS (confidence: high) [0x0075b960]
int Lua_IsPopupQueued_0075b960(lua_State* L);
// src: GUESS (confidence: high) [0x0075b990]
int Lua_IsDiploOrPopupWaiting_0075b990(lua_State* L);
// src: GUESS (confidence: high) [0x0075abd0]
int Lua_IsPopupTypeOpen_0075abd0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ac10]
int Lua_GetPopupType_0075ac10(lua_State* L);
// src: GUESS (confidence: high) [0x0075ac70]
int Lua_GetPopupTypeName_0075ac70(lua_State* L);
// src: GUESS (confidence: high) [0x0075ad00]
int Lua_GetPopupTypeByIndex_0075ad00(lua_State* L);
// src: GUESS (confidence: high) [0x0075ad40]
int Lua_GetPopupTypeCount_0075ad40(lua_State* L);
// src: GUESS (confidence: high) [0x0075c6f0]
int Lua_RegisterPopupType_0075c6f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b9c0]
int Lua_IsCityScreenViewingMode_0075b9c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c7c0]
int Lua_SetCityScreenViewingMode_0075c7c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c7f0]
int Lua_GetMultiplayerLobbyMode_0075c7f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c820]
int Lua_SetMultiplayerLobbyMode_0075c820(lua_State* L);
// src: GUESS (confidence: high) [0x0075c850]
int Lua_GetLastSelectedUnit_0075c850(lua_State* L);
// src: GUESS (confidence: high) [0x0075c8c0]
int Lua_SetLastSelectedUnit_0075c8c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c940]
int Lua_ChangePlotListColumn_0075c940(lua_State* L);
// src: GUESS (confidence: high) [0x0075c970]
int Lua_GetOriginalPlot_0075c970(lua_State* L);
// src: GUESS (confidence: high) [0x0075b9f0]
int Lua_ClearSelectionList_0075b9f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ca10]
int Lua_InsertIntoSelectionList_0075ca10(lua_State* L);
// src: GUESS (confidence: high) [0x0075cb10]
int Lua_SelectCity_0075cb10(lua_State* L);
// src: GUESS (confidence: high) [0x0075ad70]
int Lua_SelectLookAtCity_0075ad70(lua_State* L);
// src: GUESS (confidence: high) [0x0075cbb0]
int Lua_AddSelectedCity_0075cbb0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ba10]
int Lua_ClearSelectedCities_0075ba10(lua_State* L);
// src: GUESS (confidence: high) [0x0075cc50]
int Lua_IsCitySelected_0075cc50(lua_State* L);
// src: GUESS (confidence: high) [0x0075cce0]
int Lua_GetHeadSelectedCity_0075cce0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ba30]
int Lua_IsCitySelection_0075ba30(lua_State* L);
// src: GUESS (confidence: high) [0x0075cd60]
int Lua_UpdateCityScreen_0075cd60(lua_State* L);
// src: GUESS (confidence: high) [0x0075cde0]
int Lua_SetPlaceUnit_0075cde0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ce60]
int Lua_GetPlaceUnit_0075ce60(lua_State* L);
// src: GUESS (confidence: high) [0x0075adb0]
int Lua_ClearPlaceUnit_0075adb0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ced0]
int Lua_CanPlaceUnitAt_0075ced0(lua_State* L);
// src: GUESS (confidence: high) [0x0075cf80]
int Lua_HighlightCanPlacePlots_0075cf80(lua_State* L);
// src: GUESS (confidence: high) [0x006652a0]
int Lua_ClearEventMessages_006652a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075ba60]
int Lua_GetCycleSelectionCounter_0075ba60(lua_State* L);
// src: GUESS (confidence: high) [0x0075d010]
int Lua_SetCycleSelectionCounter_0075d010(lua_State* L);
// src: GUESS (confidence: high) [0x0075d040]
int Lua_ChangeCycleSelectionCounter_0075d040(lua_State* L);
// src: GUESS (confidence: high) [0x0075ba90]
int Lua_GetEndTurnCounter_0075ba90(lua_State* L);
// src: GUESS (confidence: high) [0x0075d070]
int Lua_SetEndTurnCounter_0075d070(lua_State* L);
// src: GUESS (confidence: high) [0x0075d0a0]
int Lua_ChangeEndTurnCounter_0075d0a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c1c0]
int Lua_CheckForCommandLineInvitation_0075c1c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bac0]
int Lua_IsCombatFocus_0075bac0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d0d0]
int Lua_SetCombatFocus_0075d0d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d100]
int Lua_IsDirty_0075d100(lua_State* L);
// src: GUESS (confidence: high) [0x0075d140]
int Lua_SetDirty_0075d140(lua_State* L);
// src: GUESS (confidence: high) [0x0075baf0]
int Lua_MakeInterfaceDirty_0075baf0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bb10]
int Lua_UpdateCursorType_0075bb10(lua_State* L);
// src: GUESS (confidence: high) [0x0075d190]
int Lua_LookAt_0075d190(lua_State* L);
// src: GUESS (confidence: high) [0x0075d220]
int Lua_CenterCamera_0075d220(lua_State* L);
// src: GUESS (confidence: high) [0x0075bb40]
int Lua_ReleaseLockedCamera_0075bb40(lua_State* L);
// src: GUESS (confidence: high) [0x0075bb60]
int Lua_IsCameraMoving_0075bb60(lua_State* L);
// src: GUESS (confidence: high) [0x0075bb90]
int Lua_IsFocused_0075bb90(lua_State* L);
// src: GUESS (confidence: high) [0x0075bbc0]
int Lua_RefreshYieldVisibleMode_0075bbc0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bbe0]
int Lua_ToggleYieldVisibleMode_0075bbe0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d2a0]
int Lua_SetYieldVisibleMode_0075d2a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bc00]
int Lua_ToggleResourceVisibleMode_0075bc00(lua_State* L);
// src: GUESS (confidence: high) [0x0075d2d0]
int Lua_SetResourceVisibleMode_0075d2d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bc20]
int Lua_ToggleGridVisibleMode_0075bc20(lua_State* L);
// src: GUESS (confidence: high) [0x0075d300]
int Lua_SetGridVisibleMode_0075d300(lua_State* L);
// src: GUESS (confidence: high) [0x0075bc40]
int Lua_GetOriginalPlotCount_0075bc40(lua_State* L);
// src: GUESS (confidence: high) [0x0075bc70]
int Lua_IsCityScreenUp_0075bc70(lua_State* L);
// src: GUESS (confidence: high) [0x0075d330]
int Lua_SetCityScreenUp_0075d330(lua_State* L);
// src: GUESS (confidence: high) [0x0075bca0]
int Lua_CanEndTurn_0075bca0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bcd0]
int Lua_WaitingForRemotePlayers_0075bcd0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d360]
int Lua_SetInterfaceMode_0075d360(lua_State* L);
// src: GUESS (confidence: high) [0x0075d390]
int Lua_GetInterfaceMode_0075d390(lua_State* L);
// src: GUESS (confidence: high) [0x0075add0]
int Lua_SetInterfaceModeValue_0075add0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bd00]
int Lua_GetInterfaceModeValue_0075bd00(lua_State* L);
// src: GUESS (confidence: high) [0x0075bd30]
int Lua_GetInterfaceModeDebugItemID1_0075bd30(lua_State* L);
// src: GUESS (confidence: high) [0x0075d3c0]
int Lua_SetInterfaceModeDebugItemID1_0075d3c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bd60]
int Lua_GetInterfaceModeDebugItemID2_0075bd60(lua_State* L);
// src: GUESS (confidence: high) [0x0075d3f0]
int Lua_SetInterfaceModeDebugItemID2_0075d3f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d420]
int Lua_SetFlashing_0075d420(lua_State* L);
// src: GUESS (confidence: high) [0x0075d470]
int Lua_IsFlashing_0075d470(lua_State* L);
// src: GUESS (confidence: high) [0x0075d4b0]
int Lua_SetDiplomacyLocked_0075d4b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bd90]
int Lua_IsDiplomacyLocked_0075bd90(lua_State* L);
// src: GUESS (confidence: high) [0x0075d4e0]
int Lua_SetCanEndTurn_0075d4e0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bdc0]
int Lua_IsHasMovedUnit_0075bdc0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d510]
int Lua_SetHasMovedUnit_0075d510(lua_State* L);
// src: GUESS (confidence: high) [0x0075bdf0]
int Lua_IsForcePopup_0075bdf0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d540]
int Lua_SetForcePopup_0075d540(lua_State* L);
// src: GUESS (confidence: high) [0x0075d570]
int Lua_LookAtCityOffset_0075d570(lua_State* L);
// src: GUESS (confidence: high) [0x0075be20]
int Lua_GetPlotListColumn_0075be20(lua_State* L);
// src: GUESS (confidence: high) [0x0075be50]
int Lua_VerifyPlotListColumn_0075be50(lua_State* L);
// src: GUESS (confidence: high) [0x0075be70]
int Lua_GetPlotListOffset_0075be70(lua_State* L);
// src: GUESS (confidence: high) [0x0075ae00]
int Lua_ExitingToMainMenu_0075ae00(lua_State* L);
// src: GUESS (confidence: high) [0x0075bea0]
int Lua_IsInAdvancedStart_0075bea0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d5a0]
int Lua_SetInAdvancedStart_0075d5a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d5d0]
int Lua_SetBusy_0075d5d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bed0]
int Lua_IsNoSelectionListCycle_0075bed0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d600]
int Lua_SetNoSelectionListCycle_0075d600(lua_State* L);
// src: GUESS (confidence: high) [0x0075d630]
int Lua_LocationSelect_0075d630(lua_State* L);
// src: GUESS (confidence: high) [0x0075d700]
int Lua_DoSelectCityAtPlot_0075d700(lua_State* L);
// src: GUESS (confidence: high) [0x0075ae30]
int Lua_AltKeyDown_0075ae30(lua_State* L);
// src: GUESS (confidence: high) [0x0075ae60]
int Lua_ShiftKeyDown_0075ae60(lua_State* L);
// src: GUESS (confidence: high) [0x0075ae90]
int Lua_CtrlKeyDown_0075ae90(lua_State* L);
// src: GUESS (confidence: high) [0x0075aec0]
int Lua_GetMouseOverHex_0075aec0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d790]
int Lua_GetScratchDeal_0075d790(lua_State* L);
// src: GUESS (confidence: high) [0x0075af00]
int Lua_ActivateNotification_0075af00(lua_State* L);
// src: GUESS (confidence: high) [0x0075af30]
int Lua_RemoveNotification_0075af30(lua_State* L);
// src: GUESS (confidence: high) [0x0075af60]
int Lua_RebroadcastNotifications_0075af60(lua_State* L);
// src: GUESS (confidence: high) [0x0075ea80]
int Lua_GetVersionInfo_0075ea80(lua_State* L);
// src: GUESS (confidence: high) [0x006e2900]
int Lua_ExitGame_006e2900(lua_State* L);
// src: GUESS (confidence: high) [0x00760510]
int Lua_SaveFileList_00760510(lua_State* L);
// src: GUESS (confidence: high) [0x0075eac0]
int Lua_LoadSaveFile_0075eac0(lua_State* L);
// src: GUESS (confidence: high) [0x0075af80]
int Lua_QuickSave_0075af80(lua_State* L);
// src: GUESS (confidence: high) [0x0075eb10]
int Lua_SaveGame_0075eb10(lua_State* L);
// src: GUESS (confidence: high) [0x0075eec0]
int Lua_DeleteSavedGame_0075eec0(lua_State* L);
// src: GUESS (confidence: high) [0x0075f000]
int Lua_GetSavedGameModificationTime_0075f000(lua_State* L);
// src: GUESS (confidence: high) [0x0075f180]
int Lua_GetSavedGameModificationTimeRaw_0075f180(lua_State* L);
// src: GUESS (confidence: high) [0x0075ec90]
int Lua_CopyLastAutoSave_0075ec90(lua_State* L);
// src: GUESS (confidence: high) [0x0075f2b0]
int Lua_SaveMap_0075f2b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d800]
int Lua_GetMapPreview_0075d800(lua_State* L);
// src: GUESS (confidence: high) [0x0075d8b0]
int Lua_GetMapPlayers_0075d8b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075f3f0]
int Lua_IsMapScenario_0075f3f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075d900]
int Lua_ResetScenarioPlayerSlots_0075d900(lua_State* L);
// src: GUESS (confidence: high) [0x0075d940]
int Lua_MoveScenarioPlayerToSlot_0075d940(lua_State* L);
// src: GUESS (confidence: high) [0x0075d9b0]
int Lua_SetNextGameState_0075d9b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075afa0]
int Lua_GetCurrentGameState_0075afa0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bf00]
int Lua_incTurnTimerSemaphore_0075bf00(lua_State* L);
// src: GUESS (confidence: high) [0x0075bf20]
int Lua_decTurnTimerSemaphore_0075bf20(lua_State* L);
// src: GUESS (confidence: high) [0x0075bf40]
int Lua_interruptTurnTimer_0075bf40(lua_State* L);
// src: GUESS (confidence: high) [0x0075d9f0]
int Lua_OnHumanOpenedTradeScreen_0075d9f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075da20]
int Lua_OnHumanDemand_0075da20(lua_State* L);
// src: GUESS (confidence: high) [0x0075bf60]
int Lua_DoProposeDeal_0075bf60(lua_State* L);
// src: GUESS (confidence: high) [0x0075bf80]
int Lua_DoDemand_0075bf80(lua_State* L);
// src: GUESS (confidence: high) [0x0075bfa0]
int Lua_DoEqualizeDealWithHuman_0075bfa0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bfc0]
int Lua_DoWhatWillAIGive_0075bfc0(lua_State* L);
// src: GUESS (confidence: high) [0x0075bfe0]
int Lua_DoWhatDoesAIWant_0075bfe0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c000]
int Lua_IsAIRequestingConcessions_0075c000(lua_State* L);
// src: GUESS (confidence: high) [0x0075c030]
int Lua_IsHumanMakingDemand_0075c030(lua_State* L);
// src: GUESS (confidence: high) [0x0075da50]
int Lua_GetRepeatActionPlayer_0075da50(lua_State* L);
// src: GUESS (confidence: high) [0x0075da80]
int Lua_SetRepeatActionPlayer_0075da80(lua_State* L);
// src: GUESS (confidence: high) [0x0075c060]
int Lua_GetStartDiploRepeatCount_0075c060(lua_State* L);
// src: GUESS (confidence: high) [0x0075dab0]
int Lua_ChangeStartDiploRepeatCount_0075dab0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c090]
int Lua_GetOfferTradeRepeatCount_0075c090(lua_State* L);
// src: GUESS (confidence: high) [0x0075dae0]
int Lua_SetOfferTradeRepeatCount_0075dae0(lua_State* L);
// src: GUESS (confidence: high) [0x0075db10]
int Lua_ChangeOfferTradeRepeatCount_0075db10(lua_State* L);
// src: GUESS (confidence: high) [0x0075afe0]
int Lua_OpenTechTree_0075afe0(lua_State* L);
// src: GUESS (confidence: high) [0x0075db40]
int Lua_BindMouse_0075db40(lua_State* L);
// src: GUESS (confidence: high) [0x0075db70]
int Lua_DebugKeyHandler_0075db70(lua_State* L);
// src: GUESS (confidence: high) [0x0075dbc0]
int Lua_BulkHideUI_0075dbc0(lua_State* L);
// src: GUESS (confidence: high) [0x0075dbf0]
int Lua_HasMadeProposal_0075dbf0(lua_State* L);
// src: GUESS (confidence: high) [0x0075dc80]
int Lua_ProposedDealExists_0075dc80(lua_State* L);
// src: GUESS (confidence: high) [0x0075b000]
int Lua_LoadProposedDeal_0075b000(lua_State* L);
// src: GUESS (confidence: high) [0x0075dd10]
int Lua_LoadCurrentDeal_0075dd10(lua_State* L);
// src: GUESS (confidence: high) [0x0075dd50]
int Lua_LoadHistoricDeal_0075dd50(lua_State* L);
// src: GUESS (confidence: high) [0x0075dd90]
int Lua_GetNumCurrentDeals_0075dd90(lua_State* L);
// src: GUESS (confidence: high) [0x0075ddd0]
int Lua_GetNumHistoricDeals_0075ddd0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b040]
int Lua_DoFinalizePlayerDeal_0075b040(lua_State* L);
// src: GUESS (confidence: high) [0x0075c0c0]
int Lua_RequestMinimapBroadcast_0075c0c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c100]
int Lua_GetTempString_0075c100(lua_State* L);
// src: GUESS (confidence: high) [0x0075c140]
int Lua_IsForceDiscussionModeQuitOnBack_0075c140(lua_State* L);
// src: GUESS (confidence: high) [0x0075de10]
int Lua_SetForceDiscussionModeQuitOnBack_0075de10(lua_State* L);
// src: GUESS (confidence: high) [0x0075b090]
int Lua_IsLoadedGame_0075b090(lua_State* L);
// src: GUESS (confidence: high) [0x0075de40]
int Lua_GetCredits_0075de40(lua_State* L);
// src: GUESS (confidence: high) [0x00760680]
int Lua_GetHallofFameData_00760680(lua_State* L);
// src: GUESS (confidence: high) [0x0075b0c0]
int Lua_RequestLeaderboardScores_0075b0c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b0e0]
int Lua_GetLeaderboardScores_0075b0e0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b100]
int Lua_GetLeaderboardTitle_0075b100(lua_State* L);
// src: GUESS (confidence: high) [0x0075b120]
int Lua_GetLeaderboardUserDataVersion_0075b120(lua_State* L);
// src: GUESS (confidence: high) [0x0075b140]
int Lua_GetAvailableLeaderboards_0075b140(lua_State* L);
// src: GUESS (confidence: high) [0x0075b160]
int Lua_SetLeaderboard_0075b160(lua_State* L);
// src: GUESS (confidence: high) [0x0075b1a0]
int Lua_SetLeaderboardCategory_0075b1a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b1d0]
int Lua_ScrollLeaderboardUp_0075b1d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b1f0]
int Lua_ScrollLeaderboardDown_0075b1f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075dfd0]
int Lua_GetDllGUID_0075dfd0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c0e0]
int Lua_SendPathfinderUpdate_0075c0e0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b210]
int Lua_DebugFlag_0075b210(lua_State* L);
// src: GUESS (confidence: high) [0x0075b240]
int Lua_HasShownLegal_0075b240(lua_State* L);
// src: GUESS (confidence: high) [0x0075c170]
int Lua_RequestLeaveLeader_0075c170(lua_State* L);
// src: GUESS (confidence: high) [0x0075c190]
int Lua_GetLeaderHeadRootUp_0075c190(lua_State* L);
// src: GUESS (confidence: high) [0x0075e0a0]
int Lua_SetLeaderHeadRootUp_0075e0a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075f910]
int Lua_AddPopup_0075f910(lua_State* L);
// src: GUESS (confidence: high) [0x0075b270]
int Lua_IsDX9_0075b270(lua_State* L);
// src: GUESS (confidence: high) [0x0075b290]
int Lua_AreMediumLeadersAllowed_0075b290(lua_State* L);
// src: GUESS (confidence: high) [0x0075e0d0]
int Lua_UnlockAchievement_0075e0d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075e5d0]
int Lua_TestLeaderMessage_0075e5d0(lua_State* L);
// src: GUESS (confidence: high) [0x00760340]
int Lua_GetReplayFiles_00760340(lua_State* L);
// src: GUESS (confidence: high) [0x0075f4c0]
int Lua_DeleteReplayFile_0075f4c0(lua_State* L);
// src: GUESS (confidence: high) [0x0075fc80]
int Lua_GetReplayFileHeader_0075fc80(lua_State* L);
// src: GUESS (confidence: high) [0x0075f5b0]
int Lua_GetReplayModificationTime_0075f5b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075f6f0]
int Lua_GetReplayModificationTimeRaw_0075f6f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075f7d0]
int Lua_GetReplayInfo_0075f7d0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b2b0]
int Lua_CompareFileTime_0075b2b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b310]
int Lua_SetAdvisorMessageHasBeenSeen_0075b310(lua_State* L);
// src: GUESS (confidence: high) [0x0075b360]
int Lua_HasAdvisorMessageBeenSeen_0075b360(lua_State* L);
// src: GUESS (confidence: high) [0x0075c1f0]
int Lua_PauseSounds_0075c1f0(lua_State* L);
// src: GUESS (confidence: high) [0x0075c250]
int Lua_IsSoundPaused_0075c250(lua_State* L);
// src: GUESS (confidence: high) [0x0075b3a0]
int Lua_AddPopupText_0075b3a0(lua_State* L);
// src: GUESS (confidence: high) [0x0075b410]
int Lua_SetDontShowPopups_0075b410(lua_State* L);
// src: GUESS (confidence: high) [0x0075b450]
int Lua_GetDontShowPopups_0075b450(lua_State* L);
// src: GUESS (confidence: high) [0x0075b480]
int Lua_PostKeyMessage_0075b480(lua_State* L);
// src: GUESS (confidence: high) [0x0075b4b0]
int Lua_IsTouchScreenEnabled_0075b4b0(lua_State* L);
// src: GUESS (confidence: high) [0x0075e680]
int Lua_GetUnitFlagIcon_0075e680(lua_State* L);
// src: GUESS (confidence: high) [0x0075e880]
int Lua_GetUnitPortraitIcon_0075e880(lua_State* L);

// src: GUESS (confidence: high) [0x00760d50]
void RegisterLuaFuncs_00760d50(lua_State* L)
{
    lua_pushcclosure(L, Lua_LookAtSelectionPlot_0075ab50, 0);
    lua_setfield(L, -2, "LookAtSelectionPlot");
    lua_pushcclosure(L, Lua_CanDoInterfaceMode_0075ab90, 0);
    lua_setfield(L, -2, "CanDoInterfaceMode");
    lua_pushcclosure(L, Lua_GetSelectionPlot_0075c2e0, 0);
    lua_setfield(L, -2, "GetSelectionPlot");
    lua_pushcclosure(L, Lua_GetHeadSelectedUnit_0075c350, 0);
    lua_setfield(L, -2, "GetHeadSelectedUnit");
    lua_pushcclosure(L, Lua_GetSelectedUnitID_0075c3f0, 0);
    lua_setfield(L, -2, "GetSelectedUnitID");
    lua_pushcclosure(L, Lua_SelectUnit_0075c450, 0);
    lua_setfield(L, -2, "SelectUnit");
    lua_pushcclosure(L, Lua_SelectGroup_0075c520, 0);
    lua_setfield(L, -2, "SelectGroup");
    lua_pushcclosure(L, Lua_SelectAll_0075c5e0, 0);
    lua_setfield(L, -2, "SelectAll");
    lua_pushcclosure(L, Lua_RemoveFromSelectionList_0075c660, 0);
    lua_setfield(L, -2, "RemoveFromSelectionList");
    lua_pushcclosure(L, Lua_MakeSelectionListDirty_0075b8b0, 0);
    lua_setfield(L, -2, "MakeSelectionListDirty");
    lua_pushcclosure(L, Lua_CanSelectionListFound_0075b8d0, 0);
    lua_setfield(L, -2, "CanSelectionListFound");
    lua_pushcclosure(L, Lua_CanSelectionListWork_0075b900, 0);
    lua_setfield(L, -2, "CanSelectionListWork");
    lua_pushcclosure(L, Lua_IsPopupUp_0075b930, 0);
    lua_setfield(L, -2, "IsPopupUp");
    lua_pushcclosure(L, Lua_IsPopupQueued_0075b960, 0);
    lua_setfield(L, -2, "IsPopupQueued");
    lua_pushcclosure(L, Lua_IsDiploOrPopupWaiting_0075b990, 0);
    lua_setfield(L, -2, "IsDiploOrPopupWaiting");
    lua_pushcclosure(L, Lua_IsPopupTypeOpen_0075abd0, 0);
    lua_setfield(L, -2, "IsPopupTypeOpen");
    lua_pushcclosure(L, Lua_GetPopupType_0075ac10, 0);
    lua_setfield(L, -2, "GetPopupType");
    lua_pushcclosure(L, Lua_GetPopupTypeName_0075ac70, 0);
    lua_setfield(L, -2, "GetPopupTypeName");
    lua_pushcclosure(L, Lua_GetPopupTypeByIndex_0075ad00, 0);
    lua_setfield(L, -2, "GetPopupTypeByIndex");
    lua_pushcclosure(L, Lua_GetPopupTypeCount_0075ad40, 0);
    lua_setfield(L, -2, "GetPopupTypeCount");
    lua_pushcclosure(L, Lua_RegisterPopupType_0075c6f0, 0);
    lua_setfield(L, -2, "RegisterPopupType");
    lua_pushcclosure(L, Lua_IsCityScreenViewingMode_0075b9c0, 0);
    lua_setfield(L, -2, "IsCityScreenViewingMode");
    lua_pushcclosure(L, Lua_SetCityScreenViewingMode_0075c7c0, 0);
    lua_setfield(L, -2, "SetCityScreenViewingMode");
    lua_pushcclosure(L, Lua_GetMultiplayerLobbyMode_0075c7f0, 0);
    lua_setfield(L, -2, "GetMultiplayerLobbyMode");
    lua_pushcclosure(L, Lua_SetMultiplayerLobbyMode_0075c820, 0);
    lua_setfield(L, -2, "SetMultiplayerLobbyMode");
    lua_pushcclosure(L, Lua_GetLastSelectedUnit_0075c850, 0);
    lua_setfield(L, -2, "GetLastSelectedUnit");
    lua_pushcclosure(L, Lua_SetLastSelectedUnit_0075c8c0, 0);
    lua_setfield(L, -2, "SetLastSelectedUnit");
    lua_pushcclosure(L, Lua_ChangePlotListColumn_0075c940, 0);
    lua_setfield(L, -2, "ChangePlotListColumn");
    lua_pushcclosure(L, Lua_GetOriginalPlot_0075c970, 0);
    lua_setfield(L, -2, "GetOriginalPlot");
    lua_pushcclosure(L, Lua_ClearSelectionList_0075b9f0, 0);
    lua_setfield(L, -2, "ClearSelectionList");
    lua_pushcclosure(L, Lua_InsertIntoSelectionList_0075ca10, 0);
    lua_setfield(L, -2, "InsertIntoSelectionList");
    lua_pushcclosure(L, Lua_SelectCity_0075cb10, 0);
    lua_setfield(L, -2, "SelectCity");
    lua_pushcclosure(L, Lua_SelectLookAtCity_0075ad70, 0);
    lua_setfield(L, -2, "SelectLookAtCity");
    lua_pushcclosure(L, Lua_AddSelectedCity_0075cbb0, 0);
    lua_setfield(L, -2, "AddSelectedCity");
    lua_pushcclosure(L, Lua_ClearSelectedCities_0075ba10, 0);
    lua_setfield(L, -2, "ClearSelectedCities");
    lua_pushcclosure(L, Lua_IsCitySelected_0075cc50, 0);
    lua_setfield(L, -2, "IsCitySelected");
    lua_pushcclosure(L, Lua_GetHeadSelectedCity_0075cce0, 0);
    lua_setfield(L, -2, "GetHeadSelectedCity");
    lua_pushcclosure(L, Lua_IsCitySelection_0075ba30, 0);
    lua_setfield(L, -2, "IsCitySelection");
    lua_pushcclosure(L, Lua_UpdateCityScreen_0075cd60, 0);
    lua_setfield(L, -2, "UpdateCityScreen");
    lua_pushcclosure(L, Lua_SetPlaceUnit_0075cde0, 0);
    lua_setfield(L, -2, "SetPlaceUnit");
    lua_pushcclosure(L, Lua_GetPlaceUnit_0075ce60, 0);
    lua_setfield(L, -2, "GetPlaceUnit");
    lua_pushcclosure(L, Lua_ClearPlaceUnit_0075adb0, 0);
    lua_setfield(L, -2, "ClearPlaceUnit");
    lua_pushcclosure(L, Lua_CanPlaceUnitAt_0075ced0, 0);
    lua_setfield(L, -2, "CanPlaceUnitAt");
    lua_pushcclosure(L, Lua_HighlightCanPlacePlots_0075cf80, 0);
    lua_setfield(L, -2, "HighlightCanPlacePlots");
    lua_pushcclosure(L, Lua_ClearEventMessages_006652a0, 0);
    lua_setfield(L, -2, "ClearEventMessages");
    lua_pushcclosure(L, Lua_GetCycleSelectionCounter_0075ba60, 0);
    lua_setfield(L, -2, "GetCycleSelectionCounter");
    lua_pushcclosure(L, Lua_SetCycleSelectionCounter_0075d010, 0);
    lua_setfield(L, -2, "SetCycleSelectionCounter");
    lua_pushcclosure(L, Lua_ChangeCycleSelectionCounter_0075d040, 0);
    lua_setfield(L, -2, "ChangeCycleSelectionCounter");
    lua_pushcclosure(L, Lua_GetEndTurnCounter_0075ba90, 0);
    lua_setfield(L, -2, "GetEndTurnCounter");
    lua_pushcclosure(L, Lua_SetEndTurnCounter_0075d070, 0);
    lua_setfield(L, -2, "SetEndTurnCounter");
    lua_pushcclosure(L, Lua_ChangeEndTurnCounter_0075d0a0, 0);
    lua_setfield(L, -2, "ChangeEndTurnCounter");
    lua_pushcclosure(L, Lua_CheckForCommandLineInvitation_0075c1c0, 0);
    lua_setfield(L, -2, "CheckForCommandLineInvitation");
    lua_pushcclosure(L, Lua_IsCombatFocus_0075bac0, 0);
    lua_setfield(L, -2, "IsCombatFocus");
    lua_pushcclosure(L, Lua_SetCombatFocus_0075d0d0, 0);
    lua_setfield(L, -2, "SetCombatFocus");
    lua_pushcclosure(L, Lua_IsDirty_0075d100, 0);
    lua_setfield(L, -2, "IsDirty");
    lua_pushcclosure(L, Lua_SetDirty_0075d140, 0);
    lua_setfield(L, -2, "SetDirty");
    lua_pushcclosure(L, Lua_MakeInterfaceDirty_0075baf0, 0);
    lua_setfield(L, -2, "MakeInterfaceDirty");
    lua_pushcclosure(L, Lua_UpdateCursorType_0075bb10, 0);
    lua_setfield(L, -2, "UpdateCursorType");
    lua_pushcclosure(L, Lua_LookAt_0075d190, 0);
    lua_setfield(L, -2, "LookAt");
    lua_pushcclosure(L, Lua_CenterCamera_0075d220, 0);
    lua_setfield(L, -2, "CenterCamera");
    lua_pushcclosure(L, Lua_ReleaseLockedCamera_0075bb40, 0);
    lua_setfield(L, -2, "ReleaseLockedCamera");
    lua_pushcclosure(L, Lua_IsCameraMoving_0075bb60, 0);
    lua_setfield(L, -2, "IsCameraMoving");
    lua_pushcclosure(L, Lua_IsFocused_0075bb90, 0);
    lua_setfield(L, -2, "IsFocused");
    lua_pushcclosure(L, Lua_RefreshYieldVisibleMode_0075bbc0, 0);
    lua_setfield(L, -2, "RefreshYieldVisibleMode");
    lua_pushcclosure(L, Lua_ToggleYieldVisibleMode_0075bbe0, 0);
    lua_setfield(L, -2, "ToggleYieldVisibleMode");
    lua_pushcclosure(L, Lua_SetYieldVisibleMode_0075d2a0, 0);
    lua_setfield(L, -2, "SetYieldVisibleMode");
    lua_pushcclosure(L, Lua_ToggleResourceVisibleMode_0075bc00, 0);
    lua_setfield(L, -2, "ToggleResourceVisibleMode");
    lua_pushcclosure(L, Lua_SetResourceVisibleMode_0075d2d0, 0);
    lua_setfield(L, -2, "SetResourceVisibleMode");
    lua_pushcclosure(L, Lua_ToggleGridVisibleMode_0075bc20, 0);
    lua_setfield(L, -2, "ToggleGridVisibleMode");
    lua_pushcclosure(L, Lua_SetGridVisibleMode_0075d300, 0);
    lua_setfield(L, -2, "SetGridVisibleMode");
    lua_pushcclosure(L, Lua_GetOriginalPlotCount_0075bc40, 0);
    lua_setfield(L, -2, "GetOriginalPlotCount");
    lua_pushcclosure(L, Lua_IsCityScreenUp_0075bc70, 0);
    lua_setfield(L, -2, "IsCityScreenUp");
    lua_pushcclosure(L, Lua_SetCityScreenUp_0075d330, 0);
    lua_setfield(L, -2, "SetCityScreenUp");
    lua_pushcclosure(L, Lua_CanEndTurn_0075bca0, 0);
    lua_setfield(L, -2, "CanEndTurn");
    lua_pushcclosure(L, Lua_WaitingForRemotePlayers_0075bcd0, 0);
    lua_setfield(L, -2, "WaitingForRemotePlayers");
    lua_pushcclosure(L, Lua_SetInterfaceMode_0075d360, 0);
    lua_setfield(L, -2, "SetInterfaceMode");
    lua_pushcclosure(L, Lua_GetInterfaceMode_0075d390, 0);
    lua_setfield(L, -2, "GetInterfaceMode");
    lua_pushcclosure(L, Lua_SetInterfaceModeValue_0075add0, 0);
    lua_setfield(L, -2, "SetInterfaceModeValue");
    lua_pushcclosure(L, Lua_GetInterfaceModeValue_0075bd00, 0);
    lua_setfield(L, -2, "GetInterfaceModeValue");
    lua_pushcclosure(L, Lua_GetInterfaceModeDebugItemID1_0075bd30, 0);
    lua_setfield(L, -2, "GetInterfaceModeDebugItemID1");
    lua_pushcclosure(L, Lua_SetInterfaceModeDebugItemID1_0075d3c0, 0);
    lua_setfield(L, -2, "SetInterfaceModeDebugItemID1");
    lua_pushcclosure(L, Lua_GetInterfaceModeDebugItemID2_0075bd60, 0);
    lua_setfield(L, -2, "GetInterfaceModeDebugItemID2");
    lua_pushcclosure(L, Lua_SetInterfaceModeDebugItemID2_0075d3f0, 0);
    lua_setfield(L, -2, "SetInterfaceModeDebugItemID2");
    lua_pushcclosure(L, Lua_SetFlashing_0075d420, 0);
    lua_setfield(L, -2, "SetFlashing");
    lua_pushcclosure(L, Lua_IsFlashing_0075d470, 0);
    lua_setfield(L, -2, "IsFlashing");
    lua_pushcclosure(L, Lua_SetDiplomacyLocked_0075d4b0, 0);
    lua_setfield(L, -2, "SetDiplomacyLocked");
    lua_pushcclosure(L, Lua_IsDiplomacyLocked_0075bd90, 0);
    lua_setfield(L, -2, "IsDiplomacyLocked");
    lua_pushcclosure(L, Lua_SetCanEndTurn_0075d4e0, 0);
    lua_setfield(L, -2, "SetCanEndTurn");
    lua_pushcclosure(L, Lua_IsHasMovedUnit_0075bdc0, 0);
    lua_setfield(L, -2, "IsHasMovedUnit");
    lua_pushcclosure(L, Lua_SetHasMovedUnit_0075d510, 0);
    lua_setfield(L, -2, "SetHasMovedUnit");
    lua_pushcclosure(L, Lua_IsForcePopup_0075bdf0, 0);
    lua_setfield(L, -2, "IsForcePopup");
    lua_pushcclosure(L, Lua_SetForcePopup_0075d540, 0);
    lua_setfield(L, -2, "SetForcePopup");
    lua_pushcclosure(L, Lua_LookAtCityOffset_0075d570, 0);
    lua_setfield(L, -2, "LookAtCityOffset");
    lua_pushcclosure(L, Lua_GetPlotListColumn_0075be20, 0);
    lua_setfield(L, -2, "GetPlotListColumn");
    lua_pushcclosure(L, Lua_VerifyPlotListColumn_0075be50, 0);
    lua_setfield(L, -2, "VerifyPlotListColumn");
    lua_pushcclosure(L, Lua_GetPlotListOffset_0075be70, 0);
    lua_setfield(L, -2, "GetPlotListOffset");
    lua_pushcclosure(L, Lua_ExitingToMainMenu_0075ae00, 0);
    lua_setfield(L, -2, "ExitingToMainMenu");
    lua_pushcclosure(L, Lua_IsInAdvancedStart_0075bea0, 0);
    lua_setfield(L, -2, "IsInAdvancedStart");
    lua_pushcclosure(L, Lua_SetInAdvancedStart_0075d5a0, 0);
    lua_setfield(L, -2, "SetInAdvancedStart");
    lua_pushcclosure(L, Lua_SetBusy_0075d5d0, 0);
    lua_setfield(L, -2, "SetBusy");
    lua_pushcclosure(L, Lua_IsNoSelectionListCycle_0075bed0, 0);
    lua_setfield(L, -2, "IsNoSelectionListCycle");
    lua_pushcclosure(L, Lua_SetNoSelectionListCycle_0075d600, 0);
    lua_setfield(L, -2, "SetNoSelectionListCycle");
    lua_pushcclosure(L, Lua_LocationSelect_0075d630, 0);
    lua_setfield(L, -2, "LocationSelect");
    lua_pushcclosure(L, Lua_DoSelectCityAtPlot_0075d700, 0);
    lua_setfield(L, -2, "DoSelectCityAtPlot");
    lua_pushcclosure(L, Lua_AltKeyDown_0075ae30, 0);
    lua_setfield(L, -2, "AltKeyDown");
    lua_pushcclosure(L, Lua_ShiftKeyDown_0075ae60, 0);
    lua_setfield(L, -2, "ShiftKeyDown");
    lua_pushcclosure(L, Lua_CtrlKeyDown_0075ae90, 0);
    lua_setfield(L, -2, "CtrlKeyDown");
    lua_pushcclosure(L, Lua_GetMouseOverHex_0075aec0, 0);
    lua_setfield(L, -2, "GetMouseOverHex");
    lua_pushcclosure(L, Lua_GetScratchDeal_0075d790, 0);
    lua_setfield(L, -2, "GetScratchDeal");
    lua_pushcclosure(L, Lua_ActivateNotification_0075af00, 0);
    lua_setfield(L, -2, "ActivateNotification");
    lua_pushcclosure(L, Lua_RemoveNotification_0075af30, 0);
    lua_setfield(L, -2, "RemoveNotification");
    lua_pushcclosure(L, Lua_RebroadcastNotifications_0075af60, 0);
    lua_setfield(L, -2, "RebroadcastNotifications");
    lua_pushcclosure(L, Lua_GetVersionInfo_0075ea80, 0);
    lua_setfield(L, -2, "GetVersionInfo");
    lua_pushcclosure(L, Lua_ExitGame_006e2900, 0);
    lua_setfield(L, -2, "ExitGame");
    lua_pushcclosure(L, Lua_SaveFileList_00760510, 0);
    lua_setfield(L, -2, "SaveFileList");
    lua_pushcclosure(L, Lua_LoadSaveFile_0075eac0, 0);
    lua_setfield(L, -2, "LoadSaveFile");
    lua_pushcclosure(L, Lua_QuickSave_0075af80, 0);
    lua_setfield(L, -2, "QuickSave");
    lua_pushcclosure(L, Lua_SaveGame_0075eb10, 0);
    lua_setfield(L, -2, "SaveGame");
    lua_pushcclosure(L, Lua_DeleteSavedGame_0075eec0, 0);
    lua_setfield(L, -2, "DeleteSavedGame");
    lua_pushcclosure(L, Lua_GetSavedGameModificationTime_0075f000, 0);
    lua_setfield(L, -2, "GetSavedGameModificationTime");
    lua_pushcclosure(L, Lua_GetSavedGameModificationTimeRaw_0075f180, 0);
    lua_setfield(L, -2, "GetSavedGameModificationTimeRaw");
    lua_pushcclosure(L, Lua_CopyLastAutoSave_0075ec90, 0);
    lua_setfield(L, -2, "CopyLastAutoSave");
    lua_pushcclosure(L, Lua_SaveMap_0075f2b0, 0);
    lua_setfield(L, -2, "SaveMap");
    lua_pushcclosure(L, Lua_GetMapPreview_0075d800, 0);
    lua_setfield(L, -2, "GetMapPreview");
    lua_pushcclosure(L, Lua_GetMapPlayers_0075d8b0, 0);
    lua_setfield(L, -2, "GetMapPlayers");
    lua_pushcclosure(L, Lua_IsMapScenario_0075f3f0, 0);
    lua_setfield(L, -2, "IsMapScenario");
    lua_pushcclosure(L, Lua_ResetScenarioPlayerSlots_0075d900, 0);
    lua_setfield(L, -2, "ResetScenarioPlayerSlots");
    lua_pushcclosure(L, Lua_MoveScenarioPlayerToSlot_0075d940, 0);
    lua_setfield(L, -2, "MoveScenarioPlayerToSlot");
    lua_pushcclosure(L, Lua_SetNextGameState_0075d9b0, 0);
    lua_setfield(L, -2, "SetNextGameState");
    lua_pushcclosure(L, Lua_GetCurrentGameState_0075afa0, 0);
    lua_setfield(L, -2, "GetCurrentGameState");
    lua_pushcclosure(L, Lua_incTurnTimerSemaphore_0075bf00, 0);
    lua_setfield(L, -2, "incTurnTimerSemaphore");
    lua_pushcclosure(L, Lua_decTurnTimerSemaphore_0075bf20, 0);
    lua_setfield(L, -2, "decTurnTimerSemaphore");
    lua_pushcclosure(L, Lua_interruptTurnTimer_0075bf40, 0);
    lua_setfield(L, -2, "interruptTurnTimer");
    lua_pushcclosure(L, Lua_OnHumanOpenedTradeScreen_0075d9f0, 0);
    lua_setfield(L, -2, "OnHumanOpenedTradeScreen");
    lua_pushcclosure(L, Lua_OnHumanDemand_0075da20, 0);
    lua_setfield(L, -2, "OnHumanDemand");
    lua_pushcclosure(L, Lua_DoProposeDeal_0075bf60, 0);
    lua_setfield(L, -2, "DoProposeDeal");
    lua_pushcclosure(L, Lua_DoDemand_0075bf80, 0);
    lua_setfield(L, -2, "DoDemand");
    lua_pushcclosure(L, Lua_DoEqualizeDealWithHuman_0075bfa0, 0);
    lua_setfield(L, -2, "DoEqualizeDealWithHuman");
    lua_pushcclosure(L, Lua_DoWhatWillAIGive_0075bfc0, 0);
    lua_setfield(L, -2, "DoWhatWillAIGive");
    lua_pushcclosure(L, Lua_DoWhatDoesAIWant_0075bfe0, 0);
    lua_setfield(L, -2, "DoWhatDoesAIWant");
    lua_pushcclosure(L, Lua_IsAIRequestingConcessions_0075c000, 0);
    lua_setfield(L, -2, "IsAIRequestingConcessions");
    lua_pushcclosure(L, Lua_IsHumanMakingDemand_0075c030, 0);
    lua_setfield(L, -2, "IsHumanMakingDemand");
    lua_pushcclosure(L, Lua_GetRepeatActionPlayer_0075da50, 0);
    lua_setfield(L, -2, "GetRepeatActionPlayer");
    lua_pushcclosure(L, Lua_SetRepeatActionPlayer_0075da80, 0);
    lua_setfield(L, -2, "SetRepeatActionPlayer");
    lua_pushcclosure(L, Lua_GetStartDiploRepeatCount_0075c060, 0);
    lua_setfield(L, -2, "GetStartDiploRepeatCount");
    lua_pushcclosure(L, Lua_ChangeStartDiploRepeatCount_0075dab0, 0);
    lua_setfield(L, -2, "ChangeStartDiploRepeatCount");
    lua_pushcclosure(L, Lua_GetOfferTradeRepeatCount_0075c090, 0);
    lua_setfield(L, -2, "GetOfferTradeRepeatCount");
    lua_pushcclosure(L, Lua_SetOfferTradeRepeatCount_0075dae0, 0);
    lua_setfield(L, -2, "SetOfferTradeRepeatCount");
    lua_pushcclosure(L, Lua_ChangeOfferTradeRepeatCount_0075db10, 0);
    lua_setfield(L, -2, "ChangeOfferTradeRepeatCount");
    lua_pushcclosure(L, Lua_OpenTechTree_0075afe0, 0);
    lua_setfield(L, -2, "OpenTechTree");
    lua_pushcclosure(L, Lua_BindMouse_0075db40, 0);
    lua_setfield(L, -2, "BindMouse");
    lua_pushcclosure(L, Lua_DebugKeyHandler_0075db70, 0);
    lua_setfield(L, -2, "DebugKeyHandler");
    lua_pushcclosure(L, Lua_BulkHideUI_0075dbc0, 0);
    lua_setfield(L, -2, "BulkHideUI");
    lua_pushcclosure(L, Lua_HasMadeProposal_0075dbf0, 0);
    lua_setfield(L, -2, "HasMadeProposal");
    lua_pushcclosure(L, Lua_ProposedDealExists_0075dc80, 0);
    lua_setfield(L, -2, "ProposedDealExists");
    lua_pushcclosure(L, Lua_LoadProposedDeal_0075b000, 0);
    lua_setfield(L, -2, "LoadProposedDeal");
    lua_pushcclosure(L, Lua_LoadCurrentDeal_0075dd10, 0);
    lua_setfield(L, -2, "LoadCurrentDeal");
    lua_pushcclosure(L, Lua_LoadHistoricDeal_0075dd50, 0);
    lua_setfield(L, -2, "LoadHistoricDeal");
    lua_pushcclosure(L, Lua_GetNumCurrentDeals_0075dd90, 0);
    lua_setfield(L, -2, "GetNumCurrentDeals");
    lua_pushcclosure(L, Lua_GetNumHistoricDeals_0075ddd0, 0);
    lua_setfield(L, -2, "GetNumHistoricDeals");
    lua_pushcclosure(L, Lua_DoFinalizePlayerDeal_0075b040, 0);
    lua_setfield(L, -2, "DoFinalizePlayerDeal");
    lua_pushcclosure(L, Lua_RequestMinimapBroadcast_0075c0c0, 0);
    lua_setfield(L, -2, "RequestMinimapBroadcast");
    lua_pushcclosure(L, Lua_GetTempString_0075c100, 0);
    lua_setfield(L, -2, "GetTempString");
    lua_pushcclosure(L, Lua_IsForceDiscussionModeQuitOnBack_0075c140, 0);
    lua_setfield(L, -2, "IsForceDiscussionModeQuitOnBack");
    lua_pushcclosure(L, Lua_SetForceDiscussionModeQuitOnBack_0075de10, 0);
    lua_setfield(L, -2, "SetForceDiscussionModeQuitOnBack");
    lua_pushcclosure(L, Lua_IsLoadedGame_0075b090, 0);
    lua_setfield(L, -2, "IsLoadedGame");
    lua_pushcclosure(L, Lua_GetCredits_0075de40, 0);
    lua_setfield(L, -2, "GetCredits");
    lua_pushcclosure(L, Lua_GetHallofFameData_00760680, 0);
    lua_setfield(L, -2, "GetHallofFameData");
    lua_pushcclosure(L, Lua_RequestLeaderboardScores_0075b0c0, 0);
    lua_setfield(L, -2, "RequestLeaderboardScores");
    lua_pushcclosure(L, Lua_GetLeaderboardScores_0075b0e0, 0);
    lua_setfield(L, -2, "GetLeaderboardScores");
    lua_pushcclosure(L, Lua_GetLeaderboardTitle_0075b100, 0);
    lua_setfield(L, -2, "GetLeaderboardTitle");
    lua_pushcclosure(L, Lua_GetLeaderboardUserDataVersion_0075b120, 0);
    lua_setfield(L, -2, "GetLeaderboardUserDataVersion");
    lua_pushcclosure(L, Lua_GetAvailableLeaderboards_0075b140, 0);
    lua_setfield(L, -2, "GetAvailableLeaderboards");
    lua_pushcclosure(L, Lua_SetLeaderboard_0075b160, 0);
    lua_setfield(L, -2, "SetLeaderboard");
    lua_pushcclosure(L, Lua_SetLeaderboardCategory_0075b1a0, 0);
    lua_setfield(L, -2, "SetLeaderboardCategory");
    lua_pushcclosure(L, Lua_ScrollLeaderboardUp_0075b1d0, 0);
    lua_setfield(L, -2, "ScrollLeaderboardUp");
    lua_pushcclosure(L, Lua_ScrollLeaderboardDown_0075b1f0, 0);
    lua_setfield(L, -2, "ScrollLeaderboardDown");
    lua_pushcclosure(L, Lua_GetDllGUID_0075dfd0, 0);
    lua_setfield(L, -2, "GetDllGUID");
    lua_pushcclosure(L, Lua_SendPathfinderUpdate_0075c0e0, 0);
    lua_setfield(L, -2, "SendPathfinderUpdate");
    lua_pushcclosure(L, Lua_DebugFlag_0075b210, 0);
    lua_setfield(L, -2, "DebugFlag");
    lua_pushcclosure(L, Lua_HasShownLegal_0075b240, 0);
    lua_setfield(L, -2, "HasShownLegal");
    lua_pushcclosure(L, Lua_RequestLeaveLeader_0075c170, 0);
    lua_setfield(L, -2, "RequestLeaveLeader");
    lua_pushcclosure(L, Lua_GetLeaderHeadRootUp_0075c190, 0);
    lua_setfield(L, -2, "GetLeaderHeadRootUp");
    lua_pushcclosure(L, Lua_SetLeaderHeadRootUp_0075e0a0, 0);
    lua_setfield(L, -2, "SetLeaderHeadRootUp");
    lua_pushcclosure(L, Lua_AddPopup_0075f910, 0);
    lua_setfield(L, -2, "AddPopup");
    lua_pushcclosure(L, Lua_IsDX9_0075b270, 0);
    lua_setfield(L, -2, "IsDX9");
    lua_pushcclosure(L, Lua_AreMediumLeadersAllowed_0075b290, 0);
    lua_setfield(L, -2, "AreMediumLeadersAllowed");
    lua_pushcclosure(L, Lua_UnlockAchievement_0075e0d0, 0);
    lua_setfield(L, -2, "UnlockAchievement");
    lua_pushcclosure(L, Lua_TestLeaderMessage_0075e5d0, 0);
    lua_setfield(L, -2, "TestLeaderMessage");
    lua_pushcclosure(L, Lua_GetReplayFiles_00760340, 0);
    lua_setfield(L, -2, "GetReplayFiles");
    lua_pushcclosure(L, Lua_DeleteReplayFile_0075f4c0, 0);
    lua_setfield(L, -2, "DeleteReplayFile");
    lua_pushcclosure(L, Lua_GetReplayFileHeader_0075fc80, 0);
    lua_setfield(L, -2, "GetReplayFileHeader");
    lua_pushcclosure(L, Lua_GetReplayModificationTime_0075f5b0, 0);
    lua_setfield(L, -2, "GetReplayModificationTime");
    lua_pushcclosure(L, Lua_GetReplayModificationTimeRaw_0075f6f0, 0);
    lua_setfield(L, -2, "GetReplayModificationTimeRaw");
    lua_pushcclosure(L, Lua_GetReplayInfo_0075f7d0, 0);
    lua_setfield(L, -2, "GetReplayInfo");
    lua_pushcclosure(L, Lua_CompareFileTime_0075b2b0, 0);
    lua_setfield(L, -2, "CompareFileTime");
    lua_pushcclosure(L, Lua_SetAdvisorMessageHasBeenSeen_0075b310, 0);
    lua_setfield(L, -2, "SetAdvisorMessageHasBeenSeen");
    lua_pushcclosure(L, Lua_HasAdvisorMessageBeenSeen_0075b360, 0);
    lua_setfield(L, -2, "HasAdvisorMessageBeenSeen");
    lua_pushcclosure(L, Lua_PauseSounds_0075c1f0, 0);
    lua_setfield(L, -2, "PauseSounds");
    lua_pushcclosure(L, Lua_IsSoundPaused_0075c250, 0);
    lua_setfield(L, -2, "IsSoundPaused");
    lua_pushcclosure(L, Lua_AddPopupText_0075b3a0, 0);
    lua_setfield(L, -2, "AddPopupText");
    lua_pushcclosure(L, Lua_SetDontShowPopups_0075b410, 0);
    lua_setfield(L, -2, "SetDontShowPopups");
    lua_pushcclosure(L, Lua_GetDontShowPopups_0075b450, 0);
    lua_setfield(L, -2, "GetDontShowPopups");
    lua_pushcclosure(L, Lua_PostKeyMessage_0075b480, 0);
    lua_setfield(L, -2, "PostKeyMessage");
    lua_pushcclosure(L, Lua_IsTouchScreenEnabled_0075b4b0, 0);
    lua_setfield(L, -2, "IsTouchScreenEnabled");
    lua_pushcclosure(L, Lua_GetUnitFlagIcon_0075e680, 0);
    lua_setfield(L, -2, "GetUnitFlagIcon");
    lua_pushcclosure(L, Lua_GetUnitPortraitIcon_0075e880, 0);
    lua_setfield(L, -2, "GetUnitPortraitIcon");
}
