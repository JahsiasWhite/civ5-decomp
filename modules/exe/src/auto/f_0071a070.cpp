// c5d-model: Orchestrator (Argon)

#include "LuaApi.h"

// src: LIB [0x00923928]
extern "C" void lua_setfield(lua_State* L, int idx, const char* k);

// src: EXE [0x006e6a90]
int l_GetHDStrategicView_Cached(lua_State* L);
// src: EXE [0x00595ec0]
int l_SetHDStrategicView_Cached(lua_State* L);
// src: EXE [0x007b4200]
int l_GetGPUTextureDecode_Cached(lua_State* L);
// src: EXE [0x00439cd0]
int l_SetGPUTextureDecode_Cached(lua_State* L);
// src: EXE [0x00763830]
int l_IsGPUTextureDecodeSupported(lua_State* L);
// src: EXE [0x004fc980]
int l_GetOverlayLevel_Cached(lua_State* L);
// src: EXE [0x00490680]
int l_SetOverlayLevel_Cached(lua_State* L);
// src: EXE [0x0040e300]
int l_GetShadowLevel_Cached(lua_State* L);
// src: EXE [0x0059d450]
int l_SetShadowLevel_Cached(lua_State* L);
// src: EXE [0x005d3930]
int l_GetFOWLevel_Cached(lua_State* L);
// src: EXE [0x005a96a0]
int l_SetFOWLevel_Cached(lua_State* L);
// src: EXE [0x0056d9f0]
int l_GetTerrainDetailLevel_Cached(lua_State* L);
// src: EXE [0x007302a0]
int l_SetTerrainDetailLevel_Cached(lua_State* L);
// src: EXE [0x004230f0]
int l_GetTerrainTessLevel_Cached(lua_State* L);
// src: EXE [0x004d6ba0]
int l_SetTerrainTessLevel_Cached(lua_State* L);
// src: EXE [0x00762090]
int l_GetTerrainShadowQuality_Cached(lua_State* L);
// src: EXE [0x00751ba0]
int l_SetTerrainShadowQuality_Cached(lua_State* L);
// src: EXE [0x00735b90]
int l_GetWaterQuality_Cached(lua_State* L);
// src: EXE [0x005b8320]
int l_SetWaterQuality_Cached(lua_State* L);
// src: EXE [0x007b1ee0]
int l_GetTextureQuality_Cached(lua_State* L);
// src: EXE [0x005c86a0]
int l_SetTextureQuality_Cached(lua_State* L);
// src: EXE [0x0047cc40]
int l_GetNumContinents_Cached(lua_State* L);
// src: EXE [0x00730280]
int l_SetNumContinents_Cached(lua_State* L);
// src: EXE [0x00508f70]
int l_GetVSync_Cached(lua_State* L);
// src: EXE [0x0070f540]
int l_SetVSync_Cached(lua_State* L);
// src: EXE [0x005860a0]
int l_GetMinimizeGrayTiles_Cached(lua_State* L);
// src: EXE [0x005ccef0]
int l_SetMinimizeGrayTiles_Cached(lua_State* L);
// src: EXE [0x00570020]
int l_GetFadeShadows_Cached(lua_State* L);
// src: EXE [0x00688b50]
int l_SetFadeShadows_Cached(lua_State* L);
// src: EXE [0x0061a230]
int l_GetLeaderQuality_Cached(lua_State* L);
// src: EXE [0x0073f910]
int l_SetLeaderQuality_Cached(lua_State* L);
// src: EXE [0x0071ea80]
int l_ResetDefaultGraphicsOptions(lua_State* L);
// src: EXE [0x0061d420]
int l_HasUserChangedGraphicsOptions(lua_State* L);
// src: EXE [0x006fa3c0]
int l_GetAASamples_Cached(lua_State* L);
// src: EXE [0x00539320]
int l_SetAASamples_Cached(lua_State* L);
// src: EXE [0x006f4c50]
int l_IsAALevelSupported(lua_State* L);
// src: EXE [0x0041e220]
int l_GetFullscreen(lua_State* L);
// src: EXE [0x0066fac0]
int l_GetFullscreen_Cached(lua_State* L);
// src: EXE [0x0062b260]
int l_SetFullscreen_Cached(lua_State* L);
// src: EXE [0x0077ac90]
int l_GetResolution_Cached(lua_State* L);
// src: EXE [0x0062a9c0]
int l_SetResolution_Cached(lua_State* L);
// src: EXE [0x005704c0]
int l_GetWindowResolution_Cached(lua_State* L);
// src: EXE [0x0061f050]
int l_SetWindowResolution_Cached(lua_State* L);
// src: EXE [0x0069dd80]
int l_HasUserChangedResolution(lua_State* L);
// src: EXE [0x0072f410]
int l_GetMaxResolution(lua_State* L);
// src: EXE [0x0070c9f0]
int l_GetPolicyInfo(lua_State* L);
// src: EXE [0x005bd1d0]
int l_GetPolicyInfo_Cached(lua_State* L);
// src: EXE [0x006624d0]
int l_SetPolicyInfo_Cached(lua_State* L);
// src: EXE [0x005afa60]
int l_GetSmallUIAssets(lua_State* L);
// src: EXE [0x00494140]
int l_GetSmallUIAssets_Cached(lua_State* L);
// src: EXE [0x005805b0]
int l_SetSmallUIAssets_Cached(lua_State* L);
// src: EXE [0x00485b60]
int l_GetAutoUIAssets(lua_State* L);
// src: EXE [0x004b7240]
int l_GetAutoUIAssets_Cached(lua_State* L);
// src: EXE [0x007b3a40]
int l_SetAutoUIAssets_Cached(lua_State* L);
// src: EXE [0x006a9630]
int l_GetAutoUnitCycle(lua_State* L);
// src: EXE [0x00655a00]
int l_GetAutoUnitCycle_Cached(lua_State* L);
// src: EXE [0x00722650]
int l_SetAutoUnitCycle_Cached(lua_State* L);
// src: EXE [0x00592860]
int l_GetGridOn(lua_State* L);
// src: EXE [0x0069f160]
int l_GetGridOn_Cached(lua_State* L);
// src: EXE [0x00605630]
int l_SetGridOn_Cached(lua_State* L);
// src: EXE [0x007646a0]
int l_GetShowTradeOn(lua_State* L);
// src: EXE [0x00685b50]
int l_GetShowTradeOn_Cached(lua_State* L);
// src: EXE [0x005509d0]
int l_SetShowTradeOn_Cached(lua_State* L);
// src: EXE [0x00665d80]
int l_GetScoreList(lua_State* L);
// src: EXE [0x005fcbc0]
int l_GetScoreList_Cached(lua_State* L);
// src: EXE [0x00685020]
int l_SetScoreList_Cached(lua_State* L);
// src: EXE [0x00624a00]
int l_GetMPScoreList(lua_State* L);
// src: EXE [0x005c5900]
int l_GetMPScoreList_Cached(lua_State* L);
// src: EXE [0x006dcc10]
int l_SetMPScoreList_Cached(lua_State* L);
// src: EXE [0x0076f970]
int l_GetResourceOn(lua_State* L);
// src: EXE [0x004c3380]
int l_GetResourceOn_Cached(lua_State* L);
// src: EXE [0x00564410]
int l_SetResourceOn_Cached(lua_State* L);
// src: EXE [0x00596970]
int l_GetYieldOn(lua_State* L);
// src: EXE [0x0074bd40]
int l_GetYieldOn_Cached(lua_State* L);
// src: EXE [0x00412ca0]
int l_SetYieldOn_Cached(lua_State* L);
// src: EXE [0x00743b20]
int l_GetHideTouchHelp(lua_State* L);
// src: EXE [0x0073b5a0]
int l_GetHideTouchHelp_Cached(lua_State* L);
// src: EXE [0x004480b0]
int l_SetHideTouchHelp_Cached(lua_State* L);
// src: EXE [0x00766b40]
int l_IsAutoWorkersDontReplace(lua_State* L);
// src: EXE [0x007336f0]
int l_IsAutoWorkersDontReplace_Cached(lua_State* L);
// src: EXE [0x006e3ae0]
int l_SetAutoWorkersDontReplace_Cached(lua_State* L);
// src: EXE [0x0077dc40]
int l_IsAutoWorkersDontRemoveFeatures(lua_State* L);
// src: EXE [0x00404a40]
int l_IsAutoWorkersDontRemoveFeatures_Cached(lua_State* L);
// src: EXE [0x0045a920]
int l_SetAutoWorkersDontRemoveFeatures_Cached(lua_State* L);
// src: EXE [0x007a1b60]
int l_IsNoCitizenWarning(lua_State* L);
// src: EXE [0x006015d0]
int l_IsNoCitizenWarning_Cached(lua_State* L);
// src: EXE [0x00743c80]
int l_SetNoCitizenWarning_Cached(lua_State* L);
// src: EXE [0x0051b410]
int l_GetTutorialLevel(lua_State* L);
// src: EXE [0x0057f9c0]
int l_GetTutorialLevel_Cached(lua_State* L);
// src: EXE [0x0045d460]
int l_SetTutorialLevel_Cached(lua_State* L);
// src: EXE [0x005ba930]
int l_IsNoRewardPopups(lua_State* L);
// src: EXE [0x00571830]
int l_IsNoRewardPopups_Cached(lua_State* L);
// src: EXE [0x006f5980]
int l_SetNoRewardPopups_Cached(lua_State* L);
// src: EXE [0x00786630]
int l_IsNoTileRecommendations(lua_State* L);
// src: EXE [0x0070cd90]
int l_IsNoTileRecommendations_Cached(lua_State* L);
// src: EXE [0x005833c0]
int l_SetNoTileRecommendations_Cached(lua_State* L);
// src: EXE [0x0041a210]
int l_IsCivilianYields(lua_State* L);
// src: EXE [0x00493180]
int l_IsCivilianYields_Cached(lua_State* L);
// src: EXE [0x005b7900]
int l_SetCivilianYields_Cached(lua_State* L);
// src: EXE [0x0049c220]
int l_IsNoBasicHelp(lua_State* L);
// src: EXE [0x00469fa0]
int l_IsNoBasicHelp_Cached(lua_State* L);
// src: EXE [0x0065f350]
int l_SetNoBasicHelp_Cached(lua_State* L);
// src: EXE [0x00558230]
int l_GetQuickSelectionAdvanceEnabled(lua_State* L);
// src: EXE [0x004cdb40]
int l_GetQuickSelectionAdvanceEnabled_Cached(lua_State* L);
// src: EXE [0x005bfc10]
int l_SetQuickSelectionAdvanceEnabled_Cached(lua_State* L);
// src: EXE [0x0050a760]
int l_GetLANNickName(lua_State* L);
// src: EXE [0x0050cf90]
int l_GetLANNickName_Cached(lua_State* L);
// src: EXE [0x00626ce0]
int l_SetLANNickName_Cached(lua_State* L);
// src: EXE [0x0045b060]
int l_GetTurnNotifySteamInvite(lua_State* L);
// src: EXE [0x0058f750]
int l_GetTurnNotifySteamInvite_Cached(lua_State* L);
// src: EXE [0x00607d90]
int l_SetTurnNotifySteamInvite_Cached(lua_State* L);
// src: EXE [0x00401480]
int l_GetTurnNotifyEmail(lua_State* L);
// src: EXE [0x0064efd0]
int l_GetTurnNotifyEmail_Cached(lua_State* L);
// src: EXE [0x005bc100]
int l_SetTurnNotifyEmail_Cached(lua_State* L);
// src: EXE [0x004a2280]
int l_GetTurnNotifyEmailAddress(lua_State* L);
// src: EXE [0x004fae80]
int l_GetTurnNotifyEmailAddress_Cached(lua_State* L);
// src: EXE [0x00720180]
int l_SetTurnNotifyEmailAddress_Cached(lua_State* L);
// src: EXE [0x005a4790]
int l_GetTurnNotifySmtpEmailAddress(lua_State* L);
// src: EXE [0x00477460]
int l_GetTurnNotifySmtpEmailAddress_Cached(lua_State* L);
// src: EXE [0x00404fe0]
int l_SetTurnNotifySmtpEmailAddress_Cached(lua_State* L);
// src: EXE [0x005a93f0]
int l_GetTurnNotifySmtpHost(lua_State* L);
// src: EXE [0x0040e2b0]
int l_GetTurnNotifySmtpHost_Cached(lua_State* L);
// src: EXE [0x0047eb90]
int l_SetTurnNotifySmtpHost_Cached(lua_State* L);
// src: EXE [0x00627980]
int l_GetTurnNotifySmtpPort(lua_State* L);
// src: EXE [0x00538790]
int l_GetTurnNotifySmtpPort_Cached(lua_State* L);
// src: EXE [0x00686e80]
int l_SetTurnNotifySmtpPort_Cached(lua_State* L);
// src: EXE [0x007751f0]
int l_GetTurnNotifySmtpUsername(lua_State* L);
// src: EXE [0x004c3d30]
int l_GetTurnNotifySmtpUsername_Cached(lua_State* L);
// src: EXE [0x0051c290]
int l_SetTurnNotifySmtpUsername_Cached(lua_State* L);
// src: EXE [0x005837a0]
int l_GetTurnNotifySmtpPassword_Cached(lua_State* L);
// src: EXE [0x00773320]
int l_SetTurnNotifySmtpPassword_Cached(lua_State* L);
// src: EXE [0x0054ef20]
int l_GetTurnNotifySmtpTLS(lua_State* L);
// src: EXE [0x00519670]
int l_GetTurnNotifySmtpTLS_Cached(lua_State* L);
// src: EXE [0x00724390]
int l_SetTurnNotifySmtpTLS_Cached(lua_State* L);
// src: EXE [0x006a6890]
int l_GetStraightZoom(lua_State* L);
// src: EXE [0x00626cb0]
int l_GetStraightZoom_Cached(lua_State* L);
// src: EXE [0x0079ece0]
int l_SetStraightZoom_Cached(lua_State* L);
// src: EXE [0x0049eae0]
int l_GetBindMouseMode(lua_State* L);
// src: EXE [0x004380d0]
int l_GetBindMouseMode_Cached(lua_State* L);
// src: EXE [0x005c0ce0]
int l_SetBindMouseMode_Cached(lua_State* L);
// src: EXE [0x00436680]
int l_GetTooltip1Seconds(lua_State* L);
// src: EXE [0x00622b20]
int l_GetTooltip1Seconds_Cached(lua_State* L);
// src: EXE [0x006439d0]
int l_SetTooltip1Seconds_Cached(lua_State* L);
// src: EXE [0x004bc990]
int l_GetTooltip2Seconds(lua_State* L);
// src: EXE [0x0057b640]
int l_GetTooltip2Seconds_Cached(lua_State* L);
// src: EXE [0x0063dbe0]
int l_SetTooltip2Seconds_Cached(lua_State* L);
// src: EXE [0x00448240]
int l_IsDebugMode(lua_State* L);
// src: EXE [0x006cd4c0]
int l_IsDebugMode_Cached(lua_State* L);
// src: EXE [0x004bb070]
int l_SetDebugMode_Cached(lua_State* L);
// src: EXE [0x00709ad0]
int l_GetTurnsBetweenAutosave(lua_State* L);
// src: EXE [0x0063bfc0]
int l_GetTurnsBetweenAutosave_Cached(lua_State* L);
// src: EXE [0x006d89d0]
int l_SetTurnsBetweenAutosave_Cached(lua_State* L);
// src: EXE [0x0053f670]
int l_GetNumAutosavesKept(lua_State* L);
// src: EXE [0x00539340]
int l_GetNumAutosavesKept_Cached(lua_State* L);
// src: EXE [0x005dacc0]
int l_SetNumAutosavesKept_Cached(lua_State* L);
// src: EXE [0x0049ed60]
int l_GetSinglePlayerAutoEndTurnEnabled(lua_State* L);
// src: EXE [0x007b5800]
int l_GetSinglePlayerAutoEndTurnEnabled_Cached(lua_State* L);
// src: EXE [0x006ad380]
int l_SetSinglePlayerAutoEndTurnEnabled_Cached(lua_State* L);
// src: EXE [0x00515310]
int l_GetMultiplayerAutoEndTurnEnabled(lua_State* L);
// src: EXE [0x006fb170]
int l_GetMultiplayerAutoEndTurnEnabled_Cached(lua_State* L);
// src: EXE [0x0072f650]
int l_SetMultiplayerAutoEndTurnEnabled_Cached(lua_State* L);
// src: EXE [0x006b7fa0]
int l_GetSinglePlayerQuickCombatEnabled(lua_State* L);
// src: EXE [0x006d1160]
int l_GetSinglePlayerQuickCombatEnabled_Cached(lua_State* L);
// src: EXE [0x004c2460]
int l_SetSinglePlayerQuickCombatEnabled_Cached(lua_State* L);
// src: EXE [0x004bf920]
int l_GetSinglePlayerQuickMovementEnabled(lua_State* L);
// src: EXE [0x00635830]
int l_GetSinglePlayerQuickMovementEnabled_Cached(lua_State* L);
// src: EXE [0x0067f4e0]
int l_SetSinglePlayerQuickMovementEnabled_Cached(lua_State* L);
// src: EXE [0x0070b840]
int l_GetMultiplayerQuickCombatEnabled(lua_State* L);
// src: EXE [0x005c15a0]
int l_GetMultiplayerQuickCombatEnabled_Cached(lua_State* L);
// src: EXE [0x00435850]
int l_SetMultiplayerQuickCombatEnabled_Cached(lua_State* L);
// src: EXE [0x00496870]
int l_GetMultiplayerQuickMovementEnabled(lua_State* L);
// src: EXE [0x00706f40]
int l_GetMultiplayerQuickMovementEnabled_Cached(lua_State* L);
// src: EXE [0x00507800]
int l_SetMultiplayerQuickMovementEnabled_Cached(lua_State* L);
// src: EXE [0x0065ce50]
int l_GetEnableMapInertia(lua_State* L);
// src: EXE [0x007a0730]
int l_GetEnableMapInertia_Cached(lua_State* L);
// src: EXE [0x006d9d90]
int l_SetEnableMapInertia_Cached(lua_State* L);
// src: EXE [0x00537390]
int l_GetSkipIntroVideo(lua_State* L);
// src: EXE [0x00780050]
int l_GetSkipIntroVideo_Cached(lua_State* L);
// src: EXE [0x00795f30]
int l_SetSkipIntroVideo_Cached(lua_State* L);
// src: EXE [0x0060ccd0]
int l_GetDragSpeed(lua_State* L);
// src: EXE [0x00755c30]
int l_GetDragSpeed_Cached(lua_State* L);
// src: EXE [0x00509750]
int l_SetDragSpeed_Cached(lua_State* L);
// src: EXE [0x00604340]
int l_GetPinchSpeed(lua_State* L);
// src: EXE [0x0071daf0]
int l_GetPinchSpeed_Cached(lua_State* L);
// src: EXE [0x006826c0]
int l_SetPinchSpeed_Cached(lua_State* L);
// src: EXE [0x0044b680]
int l_ResetTutorial(lua_State* L);
// src: EXE [0x006a69a0]
int l_CommitGameOptions(lua_State* L);
// src: EXE [0x00496f40]
int l_SyncGameOptionsCache(lua_State* L);
// src: EXE [0x0070edb0]
int l_CommitGraphicsOptions(lua_State* L);
// src: EXE [0x00729fc0]
int l_SyncGraphicsOptionsCache(lua_State* L);
// src: EXE [0x00577ad0]
int l_CommitResolutionOptions(lua_State* L);
// src: EXE [0x00508670]
int l_SyncResolutionOptionsCache(lua_State* L);
// src: EXE [0x006346e0]
int l_ResetDefaultGameOptions(lua_State* L);

// src: GUESS (confidence: high) [0x0071a070]
int RegisterLuaOptions_0071a070(lua_State* L)
{
    lua_createtable(L, 0, 0);
    lua_pushcclosure(L, l_GetHDStrategicView_Cached, 0);
    lua_setfield(L, -2, "GetHDStrategicView_Cached");
    lua_pushcclosure(L, l_SetHDStrategicView_Cached, 0);
    lua_setfield(L, -2, "SetHDStrategicView_Cached");
    lua_pushcclosure(L, l_GetGPUTextureDecode_Cached, 0);
    lua_setfield(L, -2, "GetGPUTextureDecode_Cached");
    lua_pushcclosure(L, l_SetGPUTextureDecode_Cached, 0);
    lua_setfield(L, -2, "SetGPUTextureDecode_Cached");
    lua_pushcclosure(L, l_IsGPUTextureDecodeSupported, 0);
    lua_setfield(L, -2, "IsGPUTextureDecodeSupported");
    lua_pushcclosure(L, l_GetOverlayLevel_Cached, 0);
    lua_setfield(L, -2, "GetOverlayLevel_Cached");
    lua_pushcclosure(L, l_SetOverlayLevel_Cached, 0);
    lua_setfield(L, -2, "SetOverlayLevel_Cached");
    lua_pushcclosure(L, l_GetShadowLevel_Cached, 0);
    lua_setfield(L, -2, "GetShadowLevel_Cached");
    lua_pushcclosure(L, l_SetShadowLevel_Cached, 0);
    lua_setfield(L, -2, "SetShadowLevel_Cached");
    lua_pushcclosure(L, l_GetFOWLevel_Cached, 0);
    lua_setfield(L, -2, "GetFOWLevel_Cached");
    lua_pushcclosure(L, l_SetFOWLevel_Cached, 0);
    lua_setfield(L, -2, "SetFOWLevel_Cached");
    lua_pushcclosure(L, l_GetTerrainDetailLevel_Cached, 0);
    lua_setfield(L, -2, "GetTerrainDetailLevel_Cached");
    lua_pushcclosure(L, l_SetTerrainDetailLevel_Cached, 0);
    lua_setfield(L, -2, "SetTerrainDetailLevel_Cached");
    lua_pushcclosure(L, l_GetTerrainTessLevel_Cached, 0);
    lua_setfield(L, -2, "GetTerrainTessLevel_Cached");
    lua_pushcclosure(L, l_SetTerrainTessLevel_Cached, 0);
    lua_setfield(L, -2, "SetTerrainTessLevel_Cached");
    lua_pushcclosure(L, l_GetTerrainShadowQuality_Cached, 0);
    lua_setfield(L, -2, "GetTerrainShadowQuality_Cached");
    lua_pushcclosure(L, l_SetTerrainShadowQuality_Cached, 0);
    lua_setfield(L, -2, "SetTerrainShadowQuality_Cached");
    lua_pushcclosure(L, l_GetWaterQuality_Cached, 0);
    lua_setfield(L, -2, "GetWaterQuality_Cached");
    lua_pushcclosure(L, l_SetWaterQuality_Cached, 0);
    lua_setfield(L, -2, "SetWaterQuality_Cached");
    lua_pushcclosure(L, l_GetTextureQuality_Cached, 0);
    lua_setfield(L, -2, "GetTextureQuality_Cached");
    lua_pushcclosure(L, l_SetTextureQuality_Cached, 0);
    lua_setfield(L, -2, "SetTextureQuality_Cached");
    lua_pushcclosure(L, l_GetNumContinents_Cached, 0);
    lua_setfield(L, -2, "GetNumContinents_Cached");
    lua_pushcclosure(L, l_SetNumContinents_Cached, 0);
    lua_setfield(L, -2, "SetNumContinents_Cached");
    lua_pushcclosure(L, l_GetVSync_Cached, 0);
    lua_setfield(L, -2, "GetVSync_Cached");
    lua_pushcclosure(L, l_SetVSync_Cached, 0);
    lua_setfield(L, -2, "SetVSync_Cached");
    lua_pushcclosure(L, l_GetMinimizeGrayTiles_Cached, 0);
    lua_setfield(L, -2, "GetMinimizeGrayTiles_Cached");
    lua_pushcclosure(L, l_SetMinimizeGrayTiles_Cached, 0);
    lua_setfield(L, -2, "SetMinimizeGrayTiles_Cached");
    lua_pushcclosure(L, l_GetFadeShadows_Cached, 0);
    lua_setfield(L, -2, "GetFadeShadows_Cached");
    lua_pushcclosure(L, l_SetFadeShadows_Cached, 0);
    lua_setfield(L, -2, "SetFadeShadows_Cached");
    lua_pushcclosure(L, l_GetLeaderQuality_Cached, 0);
    lua_setfield(L, -2, "GetLeaderQuality_Cached");
    lua_pushcclosure(L, l_SetLeaderQuality_Cached, 0);
    lua_setfield(L, -2, "SetLeaderQuality_Cached");
    lua_pushcclosure(L, l_ResetDefaultGraphicsOptions, 0);
    lua_setfield(L, -2, "ResetDefaultGraphicsOptions");
    lua_pushcclosure(L, l_HasUserChangedGraphicsOptions, 0);
    lua_setfield(L, -2, "HasUserChangedGraphicsOptions");
    lua_pushcclosure(L, l_GetAASamples_Cached, 0);
    lua_setfield(L, -2, "GetAASamples_Cached");
    lua_pushcclosure(L, l_SetAASamples_Cached, 0);
    lua_setfield(L, -2, "SetAASamples_Cached");
    lua_pushcclosure(L, l_IsAALevelSupported, 0);
    lua_setfield(L, -2, "IsAALevelSupported");
    lua_pushcclosure(L, l_GetFullscreen, 0);
    lua_setfield(L, -2, "GetFullscreen");
    lua_pushcclosure(L, l_GetFullscreen_Cached, 0);
    lua_setfield(L, -2, "GetFullscreen_Cached");
    lua_pushcclosure(L, l_SetFullscreen_Cached, 0);
    lua_setfield(L, -2, "SetFullscreen_Cached");
    lua_pushcclosure(L, l_GetResolution_Cached, 0);
    lua_setfield(L, -2, "GetResolution_Cached");
    lua_pushcclosure(L, l_SetResolution_Cached, 0);
    lua_setfield(L, -2, "SetResolution_Cached");
    lua_pushcclosure(L, l_GetWindowResolution_Cached, 0);
    lua_setfield(L, -2, "GetWindowResolution_Cached");
    lua_pushcclosure(L, l_SetWindowResolution_Cached, 0);
    lua_setfield(L, -2, "SetWindowResolution_Cached");
    lua_pushcclosure(L, l_HasUserChangedResolution, 0);
    lua_setfield(L, -2, "HasUserChangedResolution");
    lua_pushcclosure(L, l_GetMaxResolution, 0);
    lua_setfield(L, -2, "GetMaxResolution");
    lua_pushcclosure(L, l_GetPolicyInfo, 0);
    lua_setfield(L, -2, "GetPolicyInfo");
    lua_pushcclosure(L, l_GetPolicyInfo_Cached, 0);
    lua_setfield(L, -2, "GetPolicyInfo_Cached");
    lua_pushcclosure(L, l_SetPolicyInfo_Cached, 0);
    lua_setfield(L, -2, "SetPolicyInfo_Cached");
    lua_pushcclosure(L, l_GetSmallUIAssets, 0);
    lua_setfield(L, -2, "GetSmallUIAssets");
    lua_pushcclosure(L, l_GetSmallUIAssets_Cached, 0);
    lua_setfield(L, -2, "GetSmallUIAssets_Cached");
    lua_pushcclosure(L, l_SetSmallUIAssets_Cached, 0);
    lua_setfield(L, -2, "SetSmallUIAssets_Cached");
    lua_pushcclosure(L, l_GetAutoUIAssets, 0);
    lua_setfield(L, -2, "GetAutoUIAssets");
    lua_pushcclosure(L, l_GetAutoUIAssets_Cached, 0);
    lua_setfield(L, -2, "GetAutoUIAssets_Cached");
    lua_pushcclosure(L, l_SetAutoUIAssets_Cached, 0);
    lua_setfield(L, -2, "SetAutoUIAssets_Cached");
    lua_pushcclosure(L, l_GetAutoUnitCycle, 0);
    lua_setfield(L, -2, "GetAutoUnitCycle");
    lua_pushcclosure(L, l_GetAutoUnitCycle_Cached, 0);
    lua_setfield(L, -2, "GetAutoUnitCycle_Cached");
    lua_pushcclosure(L, l_SetAutoUnitCycle_Cached, 0);
    lua_setfield(L, -2, "SetAutoUnitCycle_Cached");
    lua_pushcclosure(L, l_GetGridOn, 0);
    lua_setfield(L, -2, "GetGridOn");
    lua_pushcclosure(L, l_GetGridOn_Cached, 0);
    lua_setfield(L, -2, "GetGridOn_Cached");
    lua_pushcclosure(L, l_SetGridOn_Cached, 0);
    lua_setfield(L, -2, "SetGridOn_Cached");
    lua_pushcclosure(L, l_GetShowTradeOn, 0);
    lua_setfield(L, -2, "GetShowTradeOn");
    lua_pushcclosure(L, l_GetShowTradeOn_Cached, 0);
    lua_setfield(L, -2, "GetShowTradeOn_Cached");
    lua_pushcclosure(L, l_SetShowTradeOn_Cached, 0);
    lua_setfield(L, -2, "SetShowTradeOn_Cached");
    lua_pushcclosure(L, l_GetScoreList, 0);
    lua_setfield(L, -2, "GetScoreList");
    lua_pushcclosure(L, l_GetScoreList_Cached, 0);
    lua_setfield(L, -2, "GetScoreList_Cached");
    lua_pushcclosure(L, l_SetScoreList_Cached, 0);
    lua_setfield(L, -2, "SetScoreList_Cached");
    lua_pushcclosure(L, l_GetMPScoreList, 0);
    lua_setfield(L, -2, "GetMPScoreList");
    lua_pushcclosure(L, l_GetMPScoreList_Cached, 0);
    lua_setfield(L, -2, "GetMPScoreList_Cached");
    lua_pushcclosure(L, l_SetMPScoreList_Cached, 0);
    lua_setfield(L, -2, "SetMPScoreList_Cached");
    lua_pushcclosure(L, l_GetResourceOn, 0);
    lua_setfield(L, -2, "GetResourceOn");
    lua_pushcclosure(L, l_GetResourceOn_Cached, 0);
    lua_setfield(L, -2, "GetResourceOn_Cached");
    lua_pushcclosure(L, l_SetResourceOn_Cached, 0);
    lua_setfield(L, -2, "SetResourceOn_Cached");
    lua_pushcclosure(L, l_GetYieldOn, 0);
    lua_setfield(L, -2, "GetYieldOn");
    lua_pushcclosure(L, l_GetYieldOn_Cached, 0);
    lua_setfield(L, -2, "GetYieldOn_Cached");
    lua_pushcclosure(L, l_SetYieldOn_Cached, 0);
    lua_setfield(L, -2, "SetYieldOn_Cached");
    lua_pushcclosure(L, l_GetHideTouchHelp, 0);
    lua_setfield(L, -2, "GetHideTouchHelp");
    lua_pushcclosure(L, l_GetHideTouchHelp_Cached, 0);
    lua_setfield(L, -2, "GetHideTouchHelp_Cached");
    lua_pushcclosure(L, l_SetHideTouchHelp_Cached, 0);
    lua_setfield(L, -2, "SetHideTouchHelp_Cached");
    lua_pushcclosure(L, l_IsAutoWorkersDontReplace, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontReplace");
    lua_pushcclosure(L, l_IsAutoWorkersDontReplace_Cached, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontReplace_Cached");
    lua_pushcclosure(L, l_SetAutoWorkersDontReplace_Cached, 0);
    lua_setfield(L, -2, "SetAutoWorkersDontReplace_Cached");
    lua_pushcclosure(L, l_IsAutoWorkersDontRemoveFeatures, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontRemoveFeatures");
    lua_pushcclosure(L, l_IsAutoWorkersDontRemoveFeatures_Cached, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontRemoveFeatures_Cached");
    lua_pushcclosure(L, l_SetAutoWorkersDontRemoveFeatures_Cached, 0);
    lua_setfield(L, -2, "SetAutoWorkersDontRemoveFeatures_Cached");
    lua_pushcclosure(L, l_IsNoCitizenWarning, 0);
    lua_setfield(L, -2, "IsNoCitizenWarning");
    lua_pushcclosure(L, l_IsNoCitizenWarning_Cached, 0);
    lua_setfield(L, -2, "IsNoCitizenWarning_Cached");
    lua_pushcclosure(L, l_SetNoCitizenWarning_Cached, 0);
    lua_setfield(L, -2, "SetNoCitizenWarning_Cached");
    lua_pushcclosure(L, l_GetTutorialLevel, 0);
    lua_setfield(L, -2, "GetTutorialLevel");
    lua_pushcclosure(L, l_GetTutorialLevel_Cached, 0);
    lua_setfield(L, -2, "GetTutorialLevel_Cached");
    lua_pushcclosure(L, l_SetTutorialLevel_Cached, 0);
    lua_setfield(L, -2, "SetTutorialLevel_Cached");
    lua_pushcclosure(L, l_IsNoRewardPopups, 0);
    lua_setfield(L, -2, "IsNoRewardPopups");
    lua_pushcclosure(L, l_IsNoRewardPopups_Cached, 0);
    lua_setfield(L, -2, "IsNoRewardPopups_Cached");
    lua_pushcclosure(L, l_SetNoRewardPopups_Cached, 0);
    lua_setfield(L, -2, "SetNoRewardPopups_Cached");
    lua_pushcclosure(L, l_IsNoTileRecommendations, 0);
    lua_setfield(L, -2, "IsNoTileRecommendations");
    lua_pushcclosure(L, l_IsNoTileRecommendations_Cached, 0);
    lua_setfield(L, -2, "IsNoTileRecommendations_Cached");
    lua_pushcclosure(L, l_SetNoTileRecommendations_Cached, 0);
    lua_setfield(L, -2, "SetNoTileRecommendations_Cached");
    lua_pushcclosure(L, l_IsCivilianYields, 0);
    lua_setfield(L, -2, "IsCivilianYields");
    lua_pushcclosure(L, l_IsCivilianYields_Cached, 0);
    lua_setfield(L, -2, "IsCivilianYields_Cached");
    lua_pushcclosure(L, l_SetCivilianYields_Cached, 0);
    lua_setfield(L, -2, "SetCivilianYields_Cached");
    lua_pushcclosure(L, l_IsNoBasicHelp, 0);
    lua_setfield(L, -2, "IsNoBasicHelp");
    lua_pushcclosure(L, l_IsNoBasicHelp_Cached, 0);
    lua_setfield(L, -2, "IsNoBasicHelp_Cached");
    lua_pushcclosure(L, l_SetNoBasicHelp_Cached, 0);
    lua_setfield(L, -2, "SetNoBasicHelp_Cached");
    lua_pushcclosure(L, l_GetQuickSelectionAdvanceEnabled, 0);
    lua_setfield(L, -2, "GetQuickSelectionAdvanceEnabled");
    lua_pushcclosure(L, l_GetQuickSelectionAdvanceEnabled_Cached, 0);
    lua_setfield(L, -2, "GetQuickSelectionAdvanceEnabled_Cached");
    lua_pushcclosure(L, l_SetQuickSelectionAdvanceEnabled_Cached, 0);
    lua_setfield(L, -2, "SetQuickSelectionAdvanceEnabled_Cached");
    lua_pushcclosure(L, l_GetLANNickName, 0);
    lua_setfield(L, -2, "GetLANNickName");
    lua_pushcclosure(L, l_GetLANNickName_Cached, 0);
    lua_setfield(L, -2, "GetLANNickName_Cached");
    lua_pushcclosure(L, l_SetLANNickName_Cached, 0);
    lua_setfield(L, -2, "SetLANNickName_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySteamInvite, 0);
    lua_setfield(L, -2, "GetTurnNotifySteamInvite");
    lua_pushcclosure(L, l_GetTurnNotifySteamInvite_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySteamInvite_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySteamInvite_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySteamInvite_Cached");
    lua_pushcclosure(L, l_GetTurnNotifyEmail, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmail");
    lua_pushcclosure(L, l_GetTurnNotifyEmail_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmail_Cached");
    lua_pushcclosure(L, l_SetTurnNotifyEmail_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifyEmail_Cached");
    lua_pushcclosure(L, l_GetTurnNotifyEmailAddress, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmailAddress");
    lua_pushcclosure(L, l_GetTurnNotifyEmailAddress_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmailAddress_Cached");
    lua_pushcclosure(L, l_SetTurnNotifyEmailAddress_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifyEmailAddress_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySmtpEmailAddress, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpEmailAddress");
    lua_pushcclosure(L, l_GetTurnNotifySmtpEmailAddress_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpEmailAddress_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySmtpEmailAddress_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpEmailAddress_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySmtpHost, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpHost");
    lua_pushcclosure(L, l_GetTurnNotifySmtpHost_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpHost_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySmtpHost_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpHost_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySmtpPort, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpPort");
    lua_pushcclosure(L, l_GetTurnNotifySmtpPort_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpPort_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySmtpPort_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpPort_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySmtpUsername, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpUsername");
    lua_pushcclosure(L, l_GetTurnNotifySmtpUsername_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpUsername_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySmtpUsername_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpUsername_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySmtpPassword_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpPassword_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySmtpPassword_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpPassword_Cached");
    lua_pushcclosure(L, l_GetTurnNotifySmtpTLS, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpTLS");
    lua_pushcclosure(L, l_GetTurnNotifySmtpTLS_Cached, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpTLS_Cached");
    lua_pushcclosure(L, l_SetTurnNotifySmtpTLS_Cached, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpTLS_Cached");
    lua_pushcclosure(L, l_GetStraightZoom, 0);
    lua_setfield(L, -2, "GetStraightZoom");
    lua_pushcclosure(L, l_GetStraightZoom_Cached, 0);
    lua_setfield(L, -2, "GetStraightZoom_Cached");
    lua_pushcclosure(L, l_SetStraightZoom_Cached, 0);
    lua_setfield(L, -2, "SetStraightZoom_Cached");
    lua_pushcclosure(L, l_GetBindMouseMode, 0);
    lua_setfield(L, -2, "GetBindMouseMode");
    lua_pushcclosure(L, l_GetBindMouseMode_Cached, 0);
    lua_setfield(L, -2, "GetBindMouseMode_Cached");
    lua_pushcclosure(L, l_SetBindMouseMode_Cached, 0);
    lua_setfield(L, -2, "SetBindMouseMode_Cached");
    lua_pushcclosure(L, l_GetTooltip1Seconds, 0);
    lua_setfield(L, -2, "GetTooltip1Seconds");
    lua_pushcclosure(L, l_GetTooltip1Seconds_Cached, 0);
    lua_setfield(L, -2, "GetTooltip1Seconds_Cached");
    lua_pushcclosure(L, l_SetTooltip1Seconds_Cached, 0);
    lua_setfield(L, -2, "SetTooltip1Seconds_Cached");
    lua_pushcclosure(L, l_GetTooltip2Seconds, 0);
    lua_setfield(L, -2, "GetTooltip2Seconds");
    lua_pushcclosure(L, l_GetTooltip2Seconds_Cached, 0);
    lua_setfield(L, -2, "GetTooltip2Seconds_Cached");
    lua_pushcclosure(L, l_SetTooltip2Seconds_Cached, 0);
    lua_setfield(L, -2, "SetTooltip2Seconds_Cached");
    lua_pushcclosure(L, l_IsDebugMode, 0);
    lua_setfield(L, -2, "IsDebugMode");
    lua_pushcclosure(L, l_IsDebugMode_Cached, 0);
    lua_setfield(L, -2, "IsDebugMode_Cached");
    lua_pushcclosure(L, l_SetDebugMode_Cached, 0);
    lua_setfield(L, -2, "SetDebugMode_Cached");
    lua_pushcclosure(L, l_GetTurnsBetweenAutosave, 0);
    lua_setfield(L, -2, "GetTurnsBetweenAutosave");
    lua_pushcclosure(L, l_GetTurnsBetweenAutosave_Cached, 0);
    lua_setfield(L, -2, "GetTurnsBetweenAutosave_Cached");
    lua_pushcclosure(L, l_SetTurnsBetweenAutosave_Cached, 0);
    lua_setfield(L, -2, "SetTurnsBetweenAutosave_Cached");
    lua_pushcclosure(L, l_GetNumAutosavesKept, 0);
    lua_setfield(L, -2, "GetNumAutosavesKept");
    lua_pushcclosure(L, l_GetNumAutosavesKept_Cached, 0);
    lua_setfield(L, -2, "GetNumAutosavesKept_Cached");
    lua_pushcclosure(L, l_SetNumAutosavesKept_Cached, 0);
    lua_setfield(L, -2, "SetNumAutosavesKept_Cached");
    lua_pushcclosure(L, l_GetSinglePlayerAutoEndTurnEnabled, 0);
    lua_setfield(L, -2, "GetSinglePlayerAutoEndTurnEnabled");
    lua_pushcclosure(L, l_GetSinglePlayerAutoEndTurnEnabled_Cached, 0);
    lua_setfield(L, -2, "GetSinglePlayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, l_SetSinglePlayerAutoEndTurnEnabled_Cached, 0);
    lua_setfield(L, -2, "SetSinglePlayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, l_GetMultiplayerAutoEndTurnEnabled, 0);
    lua_setfield(L, -2, "GetMultiplayerAutoEndTurnEnabled");
    lua_pushcclosure(L, l_GetMultiplayerAutoEndTurnEnabled_Cached, 0);
    lua_setfield(L, -2, "GetMultiplayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, l_SetMultiplayerAutoEndTurnEnabled_Cached, 0);
    lua_setfield(L, -2, "SetMultiplayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, l_GetSinglePlayerQuickCombatEnabled, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickCombatEnabled");
    lua_pushcclosure(L, l_GetSinglePlayerQuickCombatEnabled_Cached, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, l_SetSinglePlayerQuickCombatEnabled_Cached, 0);
    lua_setfield(L, -2, "SetSinglePlayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, l_GetSinglePlayerQuickMovementEnabled, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickMovementEnabled");
    lua_pushcclosure(L, l_GetSinglePlayerQuickMovementEnabled_Cached, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, l_SetSinglePlayerQuickMovementEnabled_Cached, 0);
    lua_setfield(L, -2, "SetSinglePlayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, l_GetMultiplayerQuickCombatEnabled, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickCombatEnabled");
    lua_pushcclosure(L, l_GetMultiplayerQuickCombatEnabled_Cached, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, l_SetMultiplayerQuickCombatEnabled_Cached, 0);
    lua_setfield(L, -2, "SetMultiplayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, l_GetMultiplayerQuickMovementEnabled, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickMovementEnabled");
    lua_pushcclosure(L, l_GetMultiplayerQuickMovementEnabled_Cached, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, l_SetMultiplayerQuickMovementEnabled_Cached, 0);
    lua_setfield(L, -2, "SetMultiplayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, l_GetEnableMapInertia, 0);
    lua_setfield(L, -2, "GetEnableMapInertia");
    lua_pushcclosure(L, l_GetEnableMapInertia_Cached, 0);
    lua_setfield(L, -2, "GetEnableMapInertia_Cached");
    lua_pushcclosure(L, l_SetEnableMapInertia_Cached, 0);
    lua_setfield(L, -2, "SetEnableMapInertia_Cached");
    lua_pushcclosure(L, l_GetSkipIntroVideo, 0);
    lua_setfield(L, -2, "GetSkipIntroVideo");
    lua_pushcclosure(L, l_GetSkipIntroVideo_Cached, 0);
    lua_setfield(L, -2, "GetSkipIntroVideo_Cached");
    lua_pushcclosure(L, l_SetSkipIntroVideo_Cached, 0);
    lua_setfield(L, -2, "SetSkipIntroVideo_Cached");
    lua_pushcclosure(L, l_GetDragSpeed, 0);
    lua_setfield(L, -2, "GetDragSpeed");
    lua_pushcclosure(L, l_GetDragSpeed_Cached, 0);
    lua_setfield(L, -2, "GetDragSpeed_Cached");
    lua_pushcclosure(L, l_SetDragSpeed_Cached, 0);
    lua_setfield(L, -2, "SetDragSpeed_Cached");
    lua_pushcclosure(L, l_GetPinchSpeed, 0);
    lua_setfield(L, -2, "GetPinchSpeed");
    lua_pushcclosure(L, l_GetPinchSpeed_Cached, 0);
    lua_setfield(L, -2, "GetPinchSpeed_Cached");
    lua_pushcclosure(L, l_SetPinchSpeed_Cached, 0);
    lua_setfield(L, -2, "SetPinchSpeed_Cached");
    lua_pushcclosure(L, l_ResetTutorial, 0);
    lua_setfield(L, -2, "ResetTutorial");
    lua_pushcclosure(L, l_CommitGameOptions, 0);
    lua_setfield(L, -2, "CommitGameOptions");
    lua_pushcclosure(L, l_SyncGameOptionsCache, 0);
    lua_setfield(L, -2, "SyncGameOptionsCache");
    lua_pushcclosure(L, l_CommitGraphicsOptions, 0);
    lua_setfield(L, -2, "CommitGraphicsOptions");
    lua_pushcclosure(L, l_SyncGraphicsOptionsCache, 0);
    lua_setfield(L, -2, "SyncGraphicsOptionsCache");
    lua_pushcclosure(L, l_CommitResolutionOptions, 0);
    lua_setfield(L, -2, "CommitResolutionOptions");
    lua_pushcclosure(L, l_SyncResolutionOptionsCache, 0);
    lua_setfield(L, -2, "SyncResolutionOptionsCache");
    lua_pushcclosure(L, l_HasUserChangedResolution, 0);
    lua_setfield(L, -2, "HasUserChangedResolution\0");
    lua_pushcclosure(L, l_ResetDefaultGameOptions, 0);
    lua_setfield(L, -2, "ResetDefaultGameOptions");
    return 1;
}
