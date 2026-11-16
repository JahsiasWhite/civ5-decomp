// c5d-model: Orchestrator (Argon)

#include "LuaApi.h"

// src: LIB [0x00923928]
extern "C" void lua_setfield(lua_State* L, int idx, const char* k);

// src: EXE [0x00435740]
int l_LookAtSelectionPlot(lua_State* L);
// src: EXE [0x00511c50]
int l_CanDoInterfaceMode(lua_State* L);
// src: EXE [0x005e6870]
int l_GetSelectionPlot(lua_State* L);
// src: EXE [0x006ddff0]
int l_GetHeadSelectedUnit(lua_State* L);
// src: EXE [0x00451a10]
int l_GetSelectedUnitID(lua_State* L);
// src: EXE [0x0048fee0]
int l_SelectUnit(lua_State* L);
// src: EXE [0x00671650]
int l_SelectGroup(lua_State* L);
// src: EXE [0x0061b0b0]
int l_SelectAll(lua_State* L);
// src: EXE [0x006f1fe0]
int l_RemoveFromSelectionList(lua_State* L);
// src: EXE [0x007b1730]
int l_MakeSelectionListDirty(lua_State* L);
// src: EXE [0x00420540]
int l_CanSelectionListFound(lua_State* L);
// src: EXE [0x0068d330]
int l_CanSelectionListWork(lua_State* L);
// src: EXE [0x005e0bf0]
int l_IsPopupUp(lua_State* L);
// src: EXE [0x005afde0]
int l_IsPopupQueued(lua_State* L);
// src: EXE [0x006ac290]
int l_IsDiploOrPopupWaiting(lua_State* L);
// src: EXE [0x004fc560]
int l_IsPopupTypeOpen(lua_State* L);
// src: EXE [0x006791e0]
int l_GetPopupType(lua_State* L);
// src: EXE [0x0060ec00]
int l_GetPopupTypeName(lua_State* L);
// src: EXE [0x00668ae0]
int l_GetPopupTypeByIndex(lua_State* L);
// src: EXE [0x0076e790]
int l_GetPopupTypeCount(lua_State* L);
// src: EXE [0x00734820]
int l_RegisterPopupType(lua_State* L);
// src: EXE [0x006840f0]
int l_IsCityScreenViewingMode(lua_State* L);
// src: EXE [0x0067fc70]
int l_SetCityScreenViewingMode(lua_State* L);
// src: EXE [0x006ba470]
int l_GetMultiplayerLobbyMode(lua_State* L);
// src: EXE [0x0054b7e0]
int l_SetMultiplayerLobbyMode(lua_State* L);
// src: EXE [0x006195a0]
int l_GetLastSelectedUnit(lua_State* L);
// src: EXE [0x0055c600]
int l_SetLastSelectedUnit(lua_State* L);
// src: EXE [0x00483ee0]
int l_ChangePlotListColumn(lua_State* L);
// src: EXE [0x0060f9a0]
int l_GetOriginalPlot(lua_State* L);
// src: EXE [0x0079f130]
int l_ClearSelectionList(lua_State* L);
// src: EXE [0x005494f0]
int l_InsertIntoSelectionList(lua_State* L);
// src: EXE [0x0068c270]
int l_SelectCity(lua_State* L);
// src: EXE [0x0045a800]
int l_SelectLookAtCity(lua_State* L);
// src: EXE [0x0044d960]
int l_AddSelectedCity(lua_State* L);
// src: EXE [0x00710750]
int l_ClearSelectedCities(lua_State* L);
// src: EXE [0x00775f90]
int l_IsCitySelected(lua_State* L);
// src: EXE [0x004f8230]
int l_GetHeadSelectedCity(lua_State* L);
// src: EXE [0x0046d7f0]
int l_IsCitySelection(lua_State* L);
// src: EXE [0x0059f210]
int l_UpdateCityScreen(lua_State* L);
// src: EXE [0x0053d810]
int l_SetPlaceUnit(lua_State* L);
// src: EXE [0x00489510]
int l_GetPlaceUnit(lua_State* L);
// src: EXE [0x0057c5d0]
int l_ClearPlaceUnit(lua_State* L);
// src: EXE [0x004a4210]
int l_CanPlaceUnitAt(lua_State* L);
// src: EXE [0x004b4790]
int l_HighlightCanPlacePlots(lua_State* L);
// src: EXE [0x007793a0]
int l_ClearEventMessages(lua_State* L);
// src: EXE [0x0043f430]
int l_GetCycleSelectionCounter(lua_State* L);
// src: EXE [0x0049a4a0]
int l_SetCycleSelectionCounter(lua_State* L);
// src: EXE [0x0065da10]
int l_ChangeCycleSelectionCounter(lua_State* L);
// src: EXE [0x0065f550]
int l_GetEndTurnCounter(lua_State* L);
// src: EXE [0x0045aee0]
int l_SetEndTurnCounter(lua_State* L);
// src: EXE [0x00479bc0]
int l_ChangeEndTurnCounter(lua_State* L);
// src: EXE [0x0064c350]
int l_CheckForCommandLineInvitation(lua_State* L);
// src: EXE [0x0068e120]
int l_IsCombatFocus(lua_State* L);
// src: EXE [0x00726020]
int l_SetCombatFocus(lua_State* L);
// src: EXE [0x004aa180]
int l_IsDirty(lua_State* L);
// src: EXE [0x00776960]
int l_SetDirty(lua_State* L);
// src: EXE [0x00544740]
int l_MakeInterfaceDirty(lua_State* L);
// src: EXE [0x0079b1d0]
int l_UpdateCursorType(lua_State* L);
// src: EXE [0x0042f310]
int l_LookAt(lua_State* L);
// src: EXE [0x004333d0]
int l_CenterCamera(lua_State* L);
// src: EXE [0x005afa40]
int l_ReleaseLockedCamera(lua_State* L);
// src: EXE [0x005d6940]
int l_IsCameraMoving(lua_State* L);
// src: EXE [0x007a1e30]
int l_IsFocused(lua_State* L);
// src: EXE [0x00443b30]
int l_RefreshYieldVisibleMode(lua_State* L);
// src: EXE [0x0070fe00]
int l_ToggleYieldVisibleMode(lua_State* L);
// src: EXE [0x004bd2a0]
int l_SetYieldVisibleMode(lua_State* L);
// src: EXE [0x005272d0]
int l_ToggleResourceVisibleMode(lua_State* L);
// src: EXE [0x0047e860]
int l_SetResourceVisibleMode(lua_State* L);
// src: EXE [0x00735520]
int l_ToggleGridVisibleMode(lua_State* L);
// src: EXE [0x0061f660]
int l_SetGridVisibleMode(lua_State* L);
// src: EXE [0x004c2410]
int l_GetOriginalPlotCount(lua_State* L);
// src: EXE [0x005e76d0]
int l_IsCityScreenUp(lua_State* L);
// src: EXE [0x0079aa80]
int l_SetCityScreenUp(lua_State* L);
// src: EXE [0x007adaa0]
int l_CanEndTurn(lua_State* L);
// src: EXE [0x006341d0]
int l_WaitingForRemotePlayers(lua_State* L);
// src: EXE [0x00736020]
int l_SetInterfaceMode(lua_State* L);
// src: EXE [0x0062d460]
int l_GetInterfaceMode(lua_State* L);
// src: EXE [0x00654800]
int l_SetInterfaceModeValue(lua_State* L);
// src: EXE [0x0075f890]
int l_GetInterfaceModeValue(lua_State* L);
// src: EXE [0x0064efa0]
int l_GetInterfaceModeDebugItemID1(lua_State* L);
// src: EXE [0x004c2be0]
int l_SetInterfaceModeDebugItemID1(lua_State* L);
// src: EXE [0x00565670]
int l_GetInterfaceModeDebugItemID2(lua_State* L);
// src: EXE [0x007381d0]
int l_SetInterfaceModeDebugItemID2(lua_State* L);
// src: EXE [0x004cc8a0]
int l_SetFlashing(lua_State* L);
// src: EXE [0x0051d2e0]
int l_IsFlashing(lua_State* L);
// src: EXE [0x004364b0]
int l_SetDiplomacyLocked(lua_State* L);
// src: EXE [0x004d3450]
int l_IsDiplomacyLocked(lua_State* L);
// src: EXE [0x006f6680]
int l_SetCanEndTurn(lua_State* L);
// src: EXE [0x00552bd0]
int l_IsHasMovedUnit(lua_State* L);
// src: EXE [0x00451cc0]
int l_SetHasMovedUnit(lua_State* L);
// src: EXE [0x006ad600]
int l_IsForcePopup(lua_State* L);
// src: EXE [0x00694130]
int l_SetForcePopup(lua_State* L);
// src: EXE [0x007aa860]
int l_LookAtCityOffset(lua_State* L);
// src: EXE [0x00786120]
int l_GetPlotListColumn(lua_State* L);
// src: EXE [0x00615390]
int l_VerifyPlotListColumn(lua_State* L);
// src: EXE [0x005e8890]
int l_GetPlotListOffset(lua_State* L);
// src: EXE [0x00717410]
int l_ExitingToMainMenu(lua_State* L);
// src: EXE [0x00559f60]
int l_IsInAdvancedStart(lua_State* L);
// src: EXE [0x006bcd50]
int l_SetInAdvancedStart(lua_State* L);
// src: EXE [0x0076f4a0]
int l_SetBusy(lua_State* L);
// src: EXE [0x005adf50]
int l_IsNoSelectionListCycle(lua_State* L);
// src: EXE [0x007ba7f0]
int l_SetNoSelectionListCycle(lua_State* L);
// src: EXE [0x00634bb0]
int l_LocationSelect(lua_State* L);
// src: EXE [0x00406280]
int l_DoSelectCityAtPlot(lua_State* L);
// src: EXE [0x0059b650]
int l_AltKeyDown(lua_State* L);
// src: EXE [0x004b0ad0]
int l_ShiftKeyDown(lua_State* L);
// src: EXE [0x0073dc20]
int l_CtrlKeyDown(lua_State* L);
// src: EXE [0x006f5940]
int l_GetMouseOverHex(lua_State* L);
// src: EXE [0x005b9830]
int l_GetScratchDeal(lua_State* L);
// src: EXE [0x006b3fe0]
int l_ActivateNotification(lua_State* L);
// src: EXE [0x00521b30]
int l_RemoveNotification(lua_State* L);
// src: EXE [0x0079bc20]
int l_RebroadcastNotifications(lua_State* L);
// src: EXE [0x0051d2a0]
int l_GetVersionInfo(lua_State* L);
// src: EXE [0x00620720]
int l_ExitGame(lua_State* L);
// src: EXE [0x00629d80]
int l_SaveFileList(lua_State* L);
// src: EXE [0x0050c450]
int l_LoadSaveFile(lua_State* L);
// src: EXE [0x007a0710]
int l_QuickSave(lua_State* L);
// src: EXE [0x00672480]
int l_SaveGame(lua_State* L);
// src: EXE [0x00621910]
int l_DeleteSavedGame(lua_State* L);
// src: EXE [0x005a1270]
int l_GetSavedGameModificationTime(lua_State* L);
// src: EXE [0x00742bf0]
int l_GetSavedGameModificationTimeRaw(lua_State* L);
// src: EXE [0x005d23c0]
int l_CopyLastAutoSave(lua_State* L);
// src: EXE [0x0056cb60]
int l_SaveMap(lua_State* L);
// src: EXE [0x00604400]
int l_GetMapPreview(lua_State* L);
// src: EXE [0x00754d60]
int l_GetMapPlayers(lua_State* L);
// src: EXE [0x005e7530]
int l_IsMapScenario(lua_State* L);
// src: EXE [0x0064fcf0]
int l_ResetScenarioPlayerSlots(lua_State* L);
// src: EXE [0x0066efd0]
int l_MoveScenarioPlayerToSlot(lua_State* L);
// src: EXE [0x004a05d0]
int l_SetNextGameState(lua_State* L);
// src: EXE [0x0061b600]
int l_GetCurrentGameState(lua_State* L);
// src: EXE [0x0051f8f0]
int l_incTurnTimerSemaphore(lua_State* L);
// src: EXE [0x004569c0]
int l_decTurnTimerSemaphore(lua_State* L);
// src: EXE [0x0047caa0]
int l_interruptTurnTimer(lua_State* L);
// src: EXE [0x006e10a0]
int l_OnHumanOpenedTradeScreen(lua_State* L);
// src: EXE [0x005f1840]
int l_OnHumanDemand(lua_State* L);
// src: EXE [0x0060ef20]
int l_DoProposeDeal(lua_State* L);
// src: EXE [0x005092e0]
int l_DoDemand(lua_State* L);
// src: EXE [0x00796750]
int l_DoEqualizeDealWithHuman(lua_State* L);
// src: EXE [0x004c94d0]
int l_DoWhatWillAIGive(lua_State* L);
// src: EXE [0x004d8490]
int l_DoWhatDoesAIWant(lua_State* L);
// src: EXE [0x00596370]
int l_IsAIRequestingConcessions(lua_State* L);
// src: EXE [0x0042a9c0]
int l_IsHumanMakingDemand(lua_State* L);
// src: EXE [0x0065d5d0]
int l_GetRepeatActionPlayer(lua_State* L);
// src: EXE [0x00446b40]
int l_SetRepeatActionPlayer(lua_State* L);
// src: EXE [0x0079be00]
int l_GetStartDiploRepeatCount(lua_State* L);
// src: EXE [0x005e5060]
int l_ChangeStartDiploRepeatCount(lua_State* L);
// src: EXE [0x006ca650]
int l_GetOfferTradeRepeatCount(lua_State* L);
// src: EXE [0x0059a070]
int l_SetOfferTradeRepeatCount(lua_State* L);
// src: EXE [0x005800f0]
int l_ChangeOfferTradeRepeatCount(lua_State* L);
// src: EXE [0x00477550]
int l_OpenTechTree(lua_State* L);
// src: EXE [0x004c0f50]
int l_BindMouse(lua_State* L);
// src: EXE [0x0073ba10]
int l_DebugKeyHandler(lua_State* L);
// src: EXE [0x0079ee30]
int l_BulkHideUI(lua_State* L);
// src: EXE [0x00439090]
int l_HasMadeProposal(lua_State* L);
// src: EXE [0x00544cd0]
int l_ProposedDealExists(lua_State* L);
// src: EXE [0x0071cb10]
int l_LoadProposedDeal(lua_State* L);
// src: EXE [0x006ac140]
int l_LoadCurrentDeal(lua_State* L);
// src: EXE [0x004f83c0]
int l_LoadHistoricDeal(lua_State* L);
// src: EXE [0x0056b440]
int l_GetNumCurrentDeals(lua_State* L);
// src: EXE [0x005700c0]
int l_GetNumHistoricDeals(lua_State* L);
// src: EXE [0x005a8440]
int l_DoFinalizePlayerDeal(lua_State* L);
// src: EXE [0x00654530]
int l_RequestMinimapBroadcast(lua_State* L);
// src: EXE [0x00680ef0]
int l_GetTempString(lua_State* L);
// src: EXE [0x004985a0]
int l_IsForceDiscussionModeQuitOnBack(lua_State* L);
// src: EXE [0x00503650]
int l_SetForceDiscussionModeQuitOnBack(lua_State* L);
// src: EXE [0x006abc20]
int l_IsLoadedGame(lua_State* L);
// src: EXE [0x0042baf0]
int l_GetCredits(lua_State* L);
// src: EXE [0x00710770]
int l_GetHallofFameData(lua_State* L);
// src: EXE [0x0045ae20]
int l_RequestLeaderboardScores(lua_State* L);
// src: EXE [0x0047f5b0]
int l_GetLeaderboardScores(lua_State* L);
// src: EXE [0x0060fb80]
int l_GetLeaderboardTitle(lua_State* L);
// src: EXE [0x007768e0]
int l_GetLeaderboardUserDataVersion(lua_State* L);
// src: EXE [0x0071cc00]
int l_GetAvailableLeaderboards(lua_State* L);
// src: EXE [0x004c2ba0]
int l_SetLeaderboard(lua_State* L);
// src: EXE [0x006145c0]
int l_SetLeaderboardCategory(lua_State* L);
// src: EXE [0x0060cdd0]
int l_ScrollLeaderboardUp(lua_State* L);
// src: EXE [0x0049a650]
int l_ScrollLeaderboardDown(lua_State* L);
// src: EXE [0x00781180]
int l_GetDllGUID(lua_State* L);
// src: EXE [0x00669e30]
int l_SendPathfinderUpdate(lua_State* L);
// src: EXE [0x0041e240]
int l_DebugFlag(lua_State* L);
// src: EXE [0x0061b820]
int l_HasShownLegal(lua_State* L);
// src: EXE [0x005db290]
int l_RequestLeaveLeader(lua_State* L);
// src: EXE [0x0060fa40]
int l_GetLeaderHeadRootUp(lua_State* L);
// src: EXE [0x0052c320]
int l_SetLeaderHeadRootUp(lua_State* L);
// src: EXE [0x00624260]
int l_AddPopup(lua_State* L);
// src: EXE [0x00777300]
int l_IsDX9(lua_State* L);
// src: EXE [0x00687f90]
int l_AreMediumLeadersAllowed(lua_State* L);
// src: EXE [0x006e5e90]
int l_UnlockAchievement(lua_State* L);
// src: EXE [0x00500350]
int l_TestLeaderMessage(lua_State* L);
// src: EXE [0x005ca050]
int l_GetReplayFiles(lua_State* L);
// src: EXE [0x0040d710]
int l_DeleteReplayFile(lua_State* L);
// src: EXE [0x005c08e0]
int l_GetReplayFileHeader(lua_State* L);
// src: EXE [0x006fdeb0]
int l_GetReplayModificationTime(lua_State* L);
// src: EXE [0x0046d070]
int l_GetReplayModificationTimeRaw(lua_State* L);
// src: EXE [0x0075ede0]
int l_GetReplayInfo(lua_State* L);
// src: EXE [0x00656b70]
int l_CompareFileTime(lua_State* L);
// src: EXE [0x0053dc20]
int l_SetAdvisorMessageHasBeenSeen(lua_State* L);
// src: EXE [0x00685290]
int l_HasAdvisorMessageBeenSeen(lua_State* L);
// src: EXE [0x00766a00]
int l_PauseSounds(lua_State* L);
// src: EXE [0x00421180]
int l_IsSoundPaused(lua_State* L);
// src: EXE [0x0068b750]
int l_AddPopupText(lua_State* L);
// src: EXE [0x006ad4d0]
int l_SetDontShowPopups(lua_State* L);
// src: EXE [0x0052e1d0]
int l_GetDontShowPopups(lua_State* L);
// src: EXE [0x004c1e00]
int l_PostKeyMessage(lua_State* L);
// src: EXE [0x004cc840]
int l_IsTouchScreenEnabled(lua_State* L);
// src: EXE [0x0058fae0]
int l_GetUnitFlagIcon(lua_State* L);
// src: EXE [0x0050dee0]
int l_GetUnitPortraitIcon(lua_State* L);

// src: GUESS (confidence: high) [0x006a7630]
void RegisterLuaUI_006a7630(lua_State* L)
{
    lua_pushcclosure(L, l_LookAtSelectionPlot, 0);
    lua_setfield(L, -2, "LookAtSelectionPlot");
    lua_pushcclosure(L, l_CanDoInterfaceMode, 0);
    lua_setfield(L, -2, "CanDoInterfaceMode");
    lua_pushcclosure(L, l_GetSelectionPlot, 0);
    lua_setfield(L, -2, "GetSelectionPlot");
    lua_pushcclosure(L, l_GetHeadSelectedUnit, 0);
    lua_setfield(L, -2, "GetHeadSelectedUnit");
    lua_pushcclosure(L, l_GetSelectedUnitID, 0);
    lua_setfield(L, -2, "GetSelectedUnitID");
    lua_pushcclosure(L, l_SelectUnit, 0);
    lua_setfield(L, -2, "SelectUnit");
    lua_pushcclosure(L, l_SelectGroup, 0);
    lua_setfield(L, -2, "SelectGroup");
    lua_pushcclosure(L, l_SelectAll, 0);
    lua_setfield(L, -2, "SelectAll");
    lua_pushcclosure(L, l_RemoveFromSelectionList, 0);
    lua_setfield(L, -2, "RemoveFromSelectionList");
    lua_pushcclosure(L, l_MakeSelectionListDirty, 0);
    lua_setfield(L, -2, "MakeSelectionListDirty");
    lua_pushcclosure(L, l_CanSelectionListFound, 0);
    lua_setfield(L, -2, "CanSelectionListFound");
    lua_pushcclosure(L, l_CanSelectionListWork, 0);
    lua_setfield(L, -2, "CanSelectionListWork");
    lua_pushcclosure(L, l_IsPopupUp, 0);
    lua_setfield(L, -2, "IsPopupUp");
    lua_pushcclosure(L, l_IsPopupQueued, 0);
    lua_setfield(L, -2, "IsPopupQueued");
    lua_pushcclosure(L, l_IsDiploOrPopupWaiting, 0);
    lua_setfield(L, -2, "IsDiploOrPopupWaiting");
    lua_pushcclosure(L, l_IsPopupTypeOpen, 0);
    lua_setfield(L, -2, "IsPopupTypeOpen");
    lua_pushcclosure(L, l_GetPopupType, 0);
    lua_setfield(L, -2, "GetPopupType");
    lua_pushcclosure(L, l_GetPopupTypeName, 0);
    lua_setfield(L, -2, "GetPopupTypeName");
    lua_pushcclosure(L, l_GetPopupTypeByIndex, 0);
    lua_setfield(L, -2, "GetPopupTypeByIndex");
    lua_pushcclosure(L, l_GetPopupTypeCount, 0);
    lua_setfield(L, -2, "GetPopupTypeCount");
    lua_pushcclosure(L, l_RegisterPopupType, 0);
    lua_setfield(L, -2, "RegisterPopupType");
    lua_pushcclosure(L, l_IsCityScreenViewingMode, 0);
    lua_setfield(L, -2, "IsCityScreenViewingMode");
    lua_pushcclosure(L, l_SetCityScreenViewingMode, 0);
    lua_setfield(L, -2, "SetCityScreenViewingMode");
    lua_pushcclosure(L, l_GetMultiplayerLobbyMode, 0);
    lua_setfield(L, -2, "GetMultiplayerLobbyMode");
    lua_pushcclosure(L, l_SetMultiplayerLobbyMode, 0);
    lua_setfield(L, -2, "SetMultiplayerLobbyMode");
    lua_pushcclosure(L, l_GetLastSelectedUnit, 0);
    lua_setfield(L, -2, "GetLastSelectedUnit");
    lua_pushcclosure(L, l_SetLastSelectedUnit, 0);
    lua_setfield(L, -2, "SetLastSelectedUnit");
    lua_pushcclosure(L, l_ChangePlotListColumn, 0);
    lua_setfield(L, -2, "ChangePlotListColumn");
    lua_pushcclosure(L, l_GetOriginalPlot, 0);
    lua_setfield(L, -2, "GetOriginalPlot");
    lua_pushcclosure(L, l_ClearSelectionList, 0);
    lua_setfield(L, -2, "ClearSelectionList");
    lua_pushcclosure(L, l_InsertIntoSelectionList, 0);
    lua_setfield(L, -2, "InsertIntoSelectionList");
    lua_pushcclosure(L, l_SelectCity, 0);
    lua_setfield(L, -2, "SelectCity");
    lua_pushcclosure(L, l_SelectLookAtCity, 0);
    lua_setfield(L, -2, "SelectLookAtCity");
    lua_pushcclosure(L, l_AddSelectedCity, 0);
    lua_setfield(L, -2, "AddSelectedCity");
    lua_pushcclosure(L, l_ClearSelectedCities, 0);
    lua_setfield(L, -2, "ClearSelectedCities");
    lua_pushcclosure(L, l_IsCitySelected, 0);
    lua_setfield(L, -2, "IsCitySelected");
    lua_pushcclosure(L, l_GetHeadSelectedCity, 0);
    lua_setfield(L, -2, "GetHeadSelectedCity");
    lua_pushcclosure(L, l_IsCitySelection, 0);
    lua_setfield(L, -2, "IsCitySelection");
    lua_pushcclosure(L, l_UpdateCityScreen, 0);
    lua_setfield(L, -2, "UpdateCityScreen");
    lua_pushcclosure(L, l_SetPlaceUnit, 0);
    lua_setfield(L, -2, "SetPlaceUnit");
    lua_pushcclosure(L, l_GetPlaceUnit, 0);
    lua_setfield(L, -2, "GetPlaceUnit");
    lua_pushcclosure(L, l_ClearPlaceUnit, 0);
    lua_setfield(L, -2, "ClearPlaceUnit");
    lua_pushcclosure(L, l_CanPlaceUnitAt, 0);
    lua_setfield(L, -2, "CanPlaceUnitAt");
    lua_pushcclosure(L, l_HighlightCanPlacePlots, 0);
    lua_setfield(L, -2, "HighlightCanPlacePlots");
    lua_pushcclosure(L, l_ClearEventMessages, 0);
    lua_setfield(L, -2, "ClearEventMessages");
    lua_pushcclosure(L, l_GetCycleSelectionCounter, 0);
    lua_setfield(L, -2, "GetCycleSelectionCounter");
    lua_pushcclosure(L, l_SetCycleSelectionCounter, 0);
    lua_setfield(L, -2, "SetCycleSelectionCounter");
    lua_pushcclosure(L, l_ChangeCycleSelectionCounter, 0);
    lua_setfield(L, -2, "ChangeCycleSelectionCounter");
    lua_pushcclosure(L, l_GetEndTurnCounter, 0);
    lua_setfield(L, -2, "GetEndTurnCounter");
    lua_pushcclosure(L, l_SetEndTurnCounter, 0);
    lua_setfield(L, -2, "SetEndTurnCounter");
    lua_pushcclosure(L, l_ChangeEndTurnCounter, 0);
    lua_setfield(L, -2, "ChangeEndTurnCounter");
    lua_pushcclosure(L, l_CheckForCommandLineInvitation, 0);
    lua_setfield(L, -2, "CheckForCommandLineInvitation");
    lua_pushcclosure(L, l_IsCombatFocus, 0);
    lua_setfield(L, -2, "IsCombatFocus");
    lua_pushcclosure(L, l_SetCombatFocus, 0);
    lua_setfield(L, -2, "SetCombatFocus");
    lua_pushcclosure(L, l_IsDirty, 0);
    lua_setfield(L, -2, "IsDirty");
    lua_pushcclosure(L, l_SetDirty, 0);
    lua_setfield(L, -2, "SetDirty");
    lua_pushcclosure(L, l_MakeInterfaceDirty, 0);
    lua_setfield(L, -2, "MakeInterfaceDirty");
    lua_pushcclosure(L, l_UpdateCursorType, 0);
    lua_setfield(L, -2, "UpdateCursorType");
    lua_pushcclosure(L, l_LookAt, 0);
    lua_setfield(L, -2, "LookAt");
    lua_pushcclosure(L, l_CenterCamera, 0);
    lua_setfield(L, -2, "CenterCamera");
    lua_pushcclosure(L, l_ReleaseLockedCamera, 0);
    lua_setfield(L, -2, "ReleaseLockedCamera");
    lua_pushcclosure(L, l_IsCameraMoving, 0);
    lua_setfield(L, -2, "IsCameraMoving");
    lua_pushcclosure(L, l_IsFocused, 0);
    lua_setfield(L, -2, "IsFocused");
    lua_pushcclosure(L, l_RefreshYieldVisibleMode, 0);
    lua_setfield(L, -2, "RefreshYieldVisibleMode");
    lua_pushcclosure(L, l_ToggleYieldVisibleMode, 0);
    lua_setfield(L, -2, "ToggleYieldVisibleMode");
    lua_pushcclosure(L, l_SetYieldVisibleMode, 0);
    lua_setfield(L, -2, "SetYieldVisibleMode");
    lua_pushcclosure(L, l_ToggleResourceVisibleMode, 0);
    lua_setfield(L, -2, "ToggleResourceVisibleMode");
    lua_pushcclosure(L, l_SetResourceVisibleMode, 0);
    lua_setfield(L, -2, "SetResourceVisibleMode");
    lua_pushcclosure(L, l_ToggleGridVisibleMode, 0);
    lua_setfield(L, -2, "ToggleGridVisibleMode");
    lua_pushcclosure(L, l_SetGridVisibleMode, 0);
    lua_setfield(L, -2, "SetGridVisibleMode");
    lua_pushcclosure(L, l_GetOriginalPlotCount, 0);
    lua_setfield(L, -2, "GetOriginalPlotCount");
    lua_pushcclosure(L, l_IsCityScreenUp, 0);
    lua_setfield(L, -2, "IsCityScreenUp");
    lua_pushcclosure(L, l_SetCityScreenUp, 0);
    lua_setfield(L, -2, "SetCityScreenUp");
    lua_pushcclosure(L, l_CanEndTurn, 0);
    lua_setfield(L, -2, "CanEndTurn");
    lua_pushcclosure(L, l_WaitingForRemotePlayers, 0);
    lua_setfield(L, -2, "WaitingForRemotePlayers");
    lua_pushcclosure(L, l_SetInterfaceMode, 0);
    lua_setfield(L, -2, "SetInterfaceMode");
    lua_pushcclosure(L, l_GetInterfaceMode, 0);
    lua_setfield(L, -2, "GetInterfaceMode");
    lua_pushcclosure(L, l_SetInterfaceModeValue, 0);
    lua_setfield(L, -2, "SetInterfaceModeValue");
    lua_pushcclosure(L, l_GetInterfaceModeValue, 0);
    lua_setfield(L, -2, "GetInterfaceModeValue");
    lua_pushcclosure(L, l_GetInterfaceModeDebugItemID1, 0);
    lua_setfield(L, -2, "GetInterfaceModeDebugItemID1");
    lua_pushcclosure(L, l_SetInterfaceModeDebugItemID1, 0);
    lua_setfield(L, -2, "SetInterfaceModeDebugItemID1");
    lua_pushcclosure(L, l_GetInterfaceModeDebugItemID2, 0);
    lua_setfield(L, -2, "GetInterfaceModeDebugItemID2");
    lua_pushcclosure(L, l_SetInterfaceModeDebugItemID2, 0);
    lua_setfield(L, -2, "SetInterfaceModeDebugItemID2");
    lua_pushcclosure(L, l_SetFlashing, 0);
    lua_setfield(L, -2, "SetFlashing");
    lua_pushcclosure(L, l_IsFlashing, 0);
    lua_setfield(L, -2, "IsFlashing");
    lua_pushcclosure(L, l_SetDiplomacyLocked, 0);
    lua_setfield(L, -2, "SetDiplomacyLocked");
    lua_pushcclosure(L, l_IsDiplomacyLocked, 0);
    lua_setfield(L, -2, "IsDiplomacyLocked");
    lua_pushcclosure(L, l_SetCanEndTurn, 0);
    lua_setfield(L, -2, "SetCanEndTurn");
    lua_pushcclosure(L, l_IsHasMovedUnit, 0);
    lua_setfield(L, -2, "IsHasMovedUnit");
    lua_pushcclosure(L, l_SetHasMovedUnit, 0);
    lua_setfield(L, -2, "SetHasMovedUnit");
    lua_pushcclosure(L, l_IsForcePopup, 0);
    lua_setfield(L, -2, "IsForcePopup");
    lua_pushcclosure(L, l_SetForcePopup, 0);
    lua_setfield(L, -2, "SetForcePopup");
    lua_pushcclosure(L, l_LookAtCityOffset, 0);
    lua_setfield(L, -2, "LookAtCityOffset");
    lua_pushcclosure(L, l_GetPlotListColumn, 0);
    lua_setfield(L, -2, "GetPlotListColumn");
    lua_pushcclosure(L, l_VerifyPlotListColumn, 0);
    lua_setfield(L, -2, "VerifyPlotListColumn");
    lua_pushcclosure(L, l_GetPlotListOffset, 0);
    lua_setfield(L, -2, "GetPlotListOffset");
    lua_pushcclosure(L, l_ExitingToMainMenu, 0);
    lua_setfield(L, -2, "ExitingToMainMenu");
    lua_pushcclosure(L, l_IsInAdvancedStart, 0);
    lua_setfield(L, -2, "IsInAdvancedStart");
    lua_pushcclosure(L, l_SetInAdvancedStart, 0);
    lua_setfield(L, -2, "SetInAdvancedStart");
    lua_pushcclosure(L, l_SetBusy, 0);
    lua_setfield(L, -2, "SetBusy");
    lua_pushcclosure(L, l_IsNoSelectionListCycle, 0);
    lua_setfield(L, -2, "IsNoSelectionListCycle");
    lua_pushcclosure(L, l_SetNoSelectionListCycle, 0);
    lua_setfield(L, -2, "SetNoSelectionListCycle");
    lua_pushcclosure(L, l_LocationSelect, 0);
    lua_setfield(L, -2, "LocationSelect");
    lua_pushcclosure(L, l_DoSelectCityAtPlot, 0);
    lua_setfield(L, -2, "DoSelectCityAtPlot");
    lua_pushcclosure(L, l_AltKeyDown, 0);
    lua_setfield(L, -2, "AltKeyDown");
    lua_pushcclosure(L, l_ShiftKeyDown, 0);
    lua_setfield(L, -2, "ShiftKeyDown");
    lua_pushcclosure(L, l_CtrlKeyDown, 0);
    lua_setfield(L, -2, "CtrlKeyDown");
    lua_pushcclosure(L, l_GetMouseOverHex, 0);
    lua_setfield(L, -2, "GetMouseOverHex");
    lua_pushcclosure(L, l_GetScratchDeal, 0);
    lua_setfield(L, -2, "GetScratchDeal");
    lua_pushcclosure(L, l_ActivateNotification, 0);
    lua_setfield(L, -2, "ActivateNotification");
    lua_pushcclosure(L, l_RemoveNotification, 0);
    lua_setfield(L, -2, "RemoveNotification");
    lua_pushcclosure(L, l_RebroadcastNotifications, 0);
    lua_setfield(L, -2, "RebroadcastNotifications");
    lua_pushcclosure(L, l_GetVersionInfo, 0);
    lua_setfield(L, -2, "GetVersionInfo");
    lua_pushcclosure(L, l_ExitGame, 0);
    lua_setfield(L, -2, "ExitGame");
    lua_pushcclosure(L, l_SaveFileList, 0);
    lua_setfield(L, -2, "SaveFileList");
    lua_pushcclosure(L, l_LoadSaveFile, 0);
    lua_setfield(L, -2, "LoadSaveFile");
    lua_pushcclosure(L, l_QuickSave, 0);
    lua_setfield(L, -2, "QuickSave");
    lua_pushcclosure(L, l_SaveGame, 0);
    lua_setfield(L, -2, "SaveGame");
    lua_pushcclosure(L, l_DeleteSavedGame, 0);
    lua_setfield(L, -2, "DeleteSavedGame");
    lua_pushcclosure(L, l_GetSavedGameModificationTime, 0);
    lua_setfield(L, -2, "GetSavedGameModificationTime");
    lua_pushcclosure(L, l_GetSavedGameModificationTimeRaw, 0);
    lua_setfield(L, -2, "GetSavedGameModificationTimeRaw");
    lua_pushcclosure(L, l_CopyLastAutoSave, 0);
    lua_setfield(L, -2, "CopyLastAutoSave");
    lua_pushcclosure(L, l_SaveMap, 0);
    lua_setfield(L, -2, "SaveMap");
    lua_pushcclosure(L, l_GetMapPreview, 0);
    lua_setfield(L, -2, "GetMapPreview");
    lua_pushcclosure(L, l_GetMapPlayers, 0);
    lua_setfield(L, -2, "GetMapPlayers");
    lua_pushcclosure(L, l_IsMapScenario, 0);
    lua_setfield(L, -2, "IsMapScenario");
    lua_pushcclosure(L, l_ResetScenarioPlayerSlots, 0);
    lua_setfield(L, -2, "ResetScenarioPlayerSlots");
    lua_pushcclosure(L, l_MoveScenarioPlayerToSlot, 0);
    lua_setfield(L, -2, "MoveScenarioPlayerToSlot");
    lua_pushcclosure(L, l_SetNextGameState, 0);
    lua_setfield(L, -2, "SetNextGameState");
    lua_pushcclosure(L, l_GetCurrentGameState, 0);
    lua_setfield(L, -2, "GetCurrentGameState");
    lua_pushcclosure(L, l_incTurnTimerSemaphore, 0);
    lua_setfield(L, -2, "incTurnTimerSemaphore");
    lua_pushcclosure(L, l_decTurnTimerSemaphore, 0);
    lua_setfield(L, -2, "decTurnTimerSemaphore");
    lua_pushcclosure(L, l_interruptTurnTimer, 0);
    lua_setfield(L, -2, "interruptTurnTimer");
    lua_pushcclosure(L, l_OnHumanOpenedTradeScreen, 0);
    lua_setfield(L, -2, "OnHumanOpenedTradeScreen");
    lua_pushcclosure(L, l_OnHumanDemand, 0);
    lua_setfield(L, -2, "OnHumanDemand");
    lua_pushcclosure(L, l_DoProposeDeal, 0);
    lua_setfield(L, -2, "DoProposeDeal");
    lua_pushcclosure(L, l_DoDemand, 0);
    lua_setfield(L, -2, "DoDemand");
    lua_pushcclosure(L, l_DoEqualizeDealWithHuman, 0);
    lua_setfield(L, -2, "DoEqualizeDealWithHuman");
    lua_pushcclosure(L, l_DoWhatWillAIGive, 0);
    lua_setfield(L, -2, "DoWhatWillAIGive");
    lua_pushcclosure(L, l_DoWhatDoesAIWant, 0);
    lua_setfield(L, -2, "DoWhatDoesAIWant");
    lua_pushcclosure(L, l_IsAIRequestingConcessions, 0);
    lua_setfield(L, -2, "IsAIRequestingConcessions");
    lua_pushcclosure(L, l_IsHumanMakingDemand, 0);
    lua_setfield(L, -2, "IsHumanMakingDemand");
    lua_pushcclosure(L, l_GetRepeatActionPlayer, 0);
    lua_setfield(L, -2, "GetRepeatActionPlayer");
    lua_pushcclosure(L, l_SetRepeatActionPlayer, 0);
    lua_setfield(L, -2, "SetRepeatActionPlayer");
    lua_pushcclosure(L, l_GetStartDiploRepeatCount, 0);
    lua_setfield(L, -2, "GetStartDiploRepeatCount");
    lua_pushcclosure(L, l_ChangeStartDiploRepeatCount, 0);
    lua_setfield(L, -2, "ChangeStartDiploRepeatCount");
    lua_pushcclosure(L, l_GetOfferTradeRepeatCount, 0);
    lua_setfield(L, -2, "GetOfferTradeRepeatCount");
    lua_pushcclosure(L, l_SetOfferTradeRepeatCount, 0);
    lua_setfield(L, -2, "SetOfferTradeRepeatCount");
    lua_pushcclosure(L, l_ChangeOfferTradeRepeatCount, 0);
    lua_setfield(L, -2, "ChangeOfferTradeRepeatCount");
    lua_pushcclosure(L, l_OpenTechTree, 0);
    lua_setfield(L, -2, "OpenTechTree");
    lua_pushcclosure(L, l_BindMouse, 0);
    lua_setfield(L, -2, "BindMouse");
    lua_pushcclosure(L, l_DebugKeyHandler, 0);
    lua_setfield(L, -2, "DebugKeyHandler");
    lua_pushcclosure(L, l_BulkHideUI, 0);
    lua_setfield(L, -2, "BulkHideUI");
    lua_pushcclosure(L, l_HasMadeProposal, 0);
    lua_setfield(L, -2, "HasMadeProposal");
    lua_pushcclosure(L, l_ProposedDealExists, 0);
    lua_setfield(L, -2, "ProposedDealExists");
    lua_pushcclosure(L, l_LoadProposedDeal, 0);
    lua_setfield(L, -2, "LoadProposedDeal");
    lua_pushcclosure(L, l_LoadCurrentDeal, 0);
    lua_setfield(L, -2, "LoadCurrentDeal");
    lua_pushcclosure(L, l_LoadHistoricDeal, 0);
    lua_setfield(L, -2, "LoadHistoricDeal");
    lua_pushcclosure(L, l_GetNumCurrentDeals, 0);
    lua_setfield(L, -2, "GetNumCurrentDeals");
    lua_pushcclosure(L, l_GetNumHistoricDeals, 0);
    lua_setfield(L, -2, "GetNumHistoricDeals");
    lua_pushcclosure(L, l_DoFinalizePlayerDeal, 0);
    lua_setfield(L, -2, "DoFinalizePlayerDeal");
    lua_pushcclosure(L, l_RequestMinimapBroadcast, 0);
    lua_setfield(L, -2, "RequestMinimapBroadcast");
    lua_pushcclosure(L, l_GetTempString, 0);
    lua_setfield(L, -2, "GetTempString");
    lua_pushcclosure(L, l_IsForceDiscussionModeQuitOnBack, 0);
    lua_setfield(L, -2, "IsForceDiscussionModeQuitOnBack");
    lua_pushcclosure(L, l_SetForceDiscussionModeQuitOnBack, 0);
    lua_setfield(L, -2, "SetForceDiscussionModeQuitOnBack");
    lua_pushcclosure(L, l_IsLoadedGame, 0);
    lua_setfield(L, -2, "IsLoadedGame");
    lua_pushcclosure(L, l_GetCredits, 0);
    lua_setfield(L, -2, "GetCredits");
    lua_pushcclosure(L, l_GetHallofFameData, 0);
    lua_setfield(L, -2, "GetHallofFameData");
    lua_pushcclosure(L, l_RequestLeaderboardScores, 0);
    lua_setfield(L, -2, "RequestLeaderboardScores");
    lua_pushcclosure(L, l_GetLeaderboardScores, 0);
    lua_setfield(L, -2, "GetLeaderboardScores");
    lua_pushcclosure(L, l_GetLeaderboardTitle, 0);
    lua_setfield(L, -2, "GetLeaderboardTitle");
    lua_pushcclosure(L, l_GetLeaderboardUserDataVersion, 0);
    lua_setfield(L, -2, "GetLeaderboardUserDataVersion");
    lua_pushcclosure(L, l_GetAvailableLeaderboards, 0);
    lua_setfield(L, -2, "GetAvailableLeaderboards");
    lua_pushcclosure(L, l_SetLeaderboard, 0);
    lua_setfield(L, -2, "SetLeaderboard");
    lua_pushcclosure(L, l_SetLeaderboardCategory, 0);
    lua_setfield(L, -2, "SetLeaderboardCategory");
    lua_pushcclosure(L, l_ScrollLeaderboardUp, 0);
    lua_setfield(L, -2, "ScrollLeaderboardUp");
    lua_pushcclosure(L, l_ScrollLeaderboardDown, 0);
    lua_setfield(L, -2, "ScrollLeaderboardDown");
    lua_pushcclosure(L, l_GetDllGUID, 0);
    lua_setfield(L, -2, "GetDllGUID");
    lua_pushcclosure(L, l_SendPathfinderUpdate, 0);
    lua_setfield(L, -2, "SendPathfinderUpdate");
    lua_pushcclosure(L, l_DebugFlag, 0);
    lua_setfield(L, -2, "DebugFlag");
    lua_pushcclosure(L, l_HasShownLegal, 0);
    lua_setfield(L, -2, "HasShownLegal");
    lua_pushcclosure(L, l_RequestLeaveLeader, 0);
    lua_setfield(L, -2, "RequestLeaveLeader");
    lua_pushcclosure(L, l_GetLeaderHeadRootUp, 0);
    lua_setfield(L, -2, "GetLeaderHeadRootUp");
    lua_pushcclosure(L, l_SetLeaderHeadRootUp, 0);
    lua_setfield(L, -2, "SetLeaderHeadRootUp");
    lua_pushcclosure(L, l_AddPopup, 0);
    lua_setfield(L, -2, "AddPopup");
    lua_pushcclosure(L, l_IsDX9, 0);
    lua_setfield(L, -2, "IsDX9");
    lua_pushcclosure(L, l_AreMediumLeadersAllowed, 0);
    lua_setfield(L, -2, "AreMediumLeadersAllowed");
    lua_pushcclosure(L, l_UnlockAchievement, 0);
    lua_setfield(L, -2, "UnlockAchievement");
    lua_pushcclosure(L, l_TestLeaderMessage, 0);
    lua_setfield(L, -2, "TestLeaderMessage");
    lua_pushcclosure(L, l_GetReplayFiles, 0);
    lua_setfield(L, -2, "GetReplayFiles");
    lua_pushcclosure(L, l_DeleteReplayFile, 0);
    lua_setfield(L, -2, "DeleteReplayFile");
    lua_pushcclosure(L, l_GetReplayFileHeader, 0);
    lua_setfield(L, -2, "GetReplayFileHeader");
    lua_pushcclosure(L, l_GetReplayModificationTime, 0);
    lua_setfield(L, -2, "GetReplayModificationTime");
    lua_pushcclosure(L, l_GetReplayModificationTimeRaw, 0);
    lua_setfield(L, -2, "GetReplayModificationTimeRaw");
    lua_pushcclosure(L, l_GetReplayInfo, 0);
    lua_setfield(L, -2, "GetReplayInfo");
    lua_pushcclosure(L, l_CompareFileTime, 0);
    lua_setfield(L, -2, "CompareFileTime");
    lua_pushcclosure(L, l_SetAdvisorMessageHasBeenSeen, 0);
    lua_setfield(L, -2, "SetAdvisorMessageHasBeenSeen");
    lua_pushcclosure(L, l_HasAdvisorMessageBeenSeen, 0);
    lua_setfield(L, -2, "HasAdvisorMessageBeenSeen");
    lua_pushcclosure(L, l_PauseSounds, 0);
    lua_setfield(L, -2, "PauseSounds");
    lua_pushcclosure(L, l_IsSoundPaused, 0);
    lua_setfield(L, -2, "IsSoundPaused");
    lua_pushcclosure(L, l_AddPopupText, 0);
    lua_setfield(L, -2, "AddPopupText");
    lua_pushcclosure(L, l_SetDontShowPopups, 0);
    lua_setfield(L, -2, "SetDontShowPopups");
    lua_pushcclosure(L, l_GetDontShowPopups, 0);
    lua_setfield(L, -2, "GetDontShowPopups");
    lua_pushcclosure(L, l_PostKeyMessage, 0);
    lua_setfield(L, -2, "PostKeyMessage");
    lua_pushcclosure(L, l_IsTouchScreenEnabled, 0);
    lua_setfield(L, -2, "IsTouchScreenEnabled");
    lua_pushcclosure(L, l_GetUnitFlagIcon, 0);
    lua_setfield(L, -2, "GetUnitFlagIcon");
    lua_pushcclosure(L, l_GetUnitPortraitIcon, 0);
    lua_setfield(L, -2, "GetUnitPortraitIcon");
}
