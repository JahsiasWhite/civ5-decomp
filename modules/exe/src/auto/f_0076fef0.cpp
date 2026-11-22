#include "LuaApi.h"

// src: LIB [0x00889534]
extern "C" void lua_createtable(lua_State* L, int narr, int nrec);
// src: LIB [0x0088956a]
extern "C" void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
// src: LIB [0x00889528]
extern "C" void lua_setfield(lua_State* L, int idx, const char* k);

// src: GUESS (confidence: high) [0x0076e430]
int Lua_GetHDStrategicView_Cached_0076e430(lua_State* L);
// src: GUESS (confidence: high) [0x0076e450]
int Lua_SetHDStrategicView_Cached_0076e450(lua_State* L);
// src: GUESS (confidence: high) [0x0076e470]
int Lua_GetGPUTextureDecode_Cached_0076e470(lua_State* L);
// src: GUESS (confidence: high) [0x0076e490]
int Lua_SetGPUTextureDecode_Cached_0076e490(lua_State* L);
// src: GUESS (confidence: high) [0x0076e4b0]
int Lua_IsGPUTextureDecodeSupported_0076e4b0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e4d0]
int Lua_GetOverlayLevel_Cached_0076e4d0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e4f0]
int Lua_SetOverlayLevel_Cached_0076e4f0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e510]
int Lua_GetShadowLevel_Cached_0076e510(lua_State* L);
// src: GUESS (confidence: high) [0x0076e530]
int Lua_SetShadowLevel_Cached_0076e530(lua_State* L);
// src: GUESS (confidence: high) [0x0076e550]
int Lua_GetFOWLevel_Cached_0076e550(lua_State* L);
// src: GUESS (confidence: high) [0x0076e570]
int Lua_SetFOWLevel_Cached_0076e570(lua_State* L);
// src: GUESS (confidence: high) [0x0076e590]
int Lua_GetTerrainDetailLevel_Cached_0076e590(lua_State* L);
// src: GUESS (confidence: high) [0x0076e5b0]
int Lua_SetTerrainDetailLevel_Cached_0076e5b0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e5d0]
int Lua_GetTerrainTessLevel_Cached_0076e5d0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e5f0]
int Lua_SetTerrainTessLevel_Cached_0076e5f0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e610]
int Lua_GetTerrainShadowQuality_Cached_0076e610(lua_State* L);
// src: GUESS (confidence: high) [0x0076e630]
int Lua_SetTerrainShadowQuality_Cached_0076e630(lua_State* L);
// src: GUESS (confidence: high) [0x0076e650]
int Lua_GetWaterQuality_Cached_0076e650(lua_State* L);
// src: GUESS (confidence: high) [0x0076e670]
int Lua_SetWaterQuality_Cached_0076e670(lua_State* L);
// src: GUESS (confidence: high) [0x0076e690]
int Lua_GetTextureQuality_Cached_0076e690(lua_State* L);
// src: GUESS (confidence: high) [0x0076e6b0]
int Lua_SetTextureQuality_Cached_0076e6b0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e6d0]
int Lua_GetNumContinents_Cached_0076e6d0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e6f0]
int Lua_SetNumContinents_Cached_0076e6f0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e710]
int Lua_GetVSync_Cached_0076e710(lua_State* L);
// src: GUESS (confidence: high) [0x0076e730]
int Lua_SetVSync_Cached_0076e730(lua_State* L);
// src: GUESS (confidence: high) [0x0076e750]
int Lua_GetMinimizeGrayTiles_Cached_0076e750(lua_State* L);
// src: GUESS (confidence: high) [0x0076e770]
int Lua_SetMinimizeGrayTiles_Cached_0076e770(lua_State* L);
// src: GUESS (confidence: high) [0x0076e790]
int Lua_GetFadeShadows_Cached_0076e790(lua_State* L);
// src: GUESS (confidence: high) [0x0076e7b0]
int Lua_SetFadeShadows_Cached_0076e7b0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e7d0]
int Lua_GetLeaderQuality_Cached_0076e7d0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e7f0]
int Lua_SetLeaderQuality_Cached_0076e7f0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e810]
int Lua_ResetDefaultGraphicsOptions_0076e810(lua_State* L);
// src: GUESS (confidence: high) [0x0076e820]
int Lua_HasUserChangedGraphicsOptions_0076e820(lua_State* L);
// src: GUESS (confidence: high) [0x0076e840]
int Lua_GetAASamples_Cached_0076e840(lua_State* L);
// src: GUESS (confidence: high) [0x0076e860]
int Lua_SetAASamples_Cached_0076e860(lua_State* L);
// src: GUESS (confidence: high) [0x0076e880]
int Lua_IsAALevelSupported_0076e880(lua_State* L);
// src: GUESS (confidence: high) [0x0076e900]
int Lua_GetFullscreen_0076e900(lua_State* L);
// src: GUESS (confidence: high) [0x0076e8e0]
int Lua_GetFullscreen_Cached_0076e8e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e920]
int Lua_SetFullscreen_Cached_0076e920(lua_State* L);
// src: GUESS (confidence: high) [0x0076e940]
int Lua_GetResolution_Cached_0076e940(lua_State* L);
// src: GUESS (confidence: high) [0x0076e960]
int Lua_SetResolution_Cached_0076e960(lua_State* L);
// src: GUESS (confidence: high) [0x0076e980]
int Lua_GetWindowResolution_Cached_0076e980(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb50]
int Lua_SetWindowResolution_Cached_0076fb50(lua_State* L);
// src: GUESS (confidence: high) [0x0076e9e0]
int Lua_HasUserChangedResolution_0076e9e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076e9b0]
int Lua_GetMaxResolution_0076e9b0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ef40]
int Lua_GetPolicyInfo_0076ef40(lua_State* L);
// src: GUESS (confidence: high) [0x0076ef60]
int Lua_GetPolicyInfo_Cached_0076ef60(lua_State* L);
// src: GUESS (confidence: high) [0x0076ef80]
int Lua_SetPolicyInfo_Cached_0076ef80(lua_State* L);
// src: GUESS (confidence: high) [0x0076efa0]
int Lua_GetSmallUIAssets_0076efa0(lua_State* L);
// src: GUESS (confidence: high) [0x0076efc0]
int Lua_GetSmallUIAssets_Cached_0076efc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076efe0]
int Lua_SetSmallUIAssets_Cached_0076efe0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f000]
int Lua_GetAutoUIAssets_0076f000(lua_State* L);
// src: GUESS (confidence: high) [0x0076f020]
int Lua_GetAutoUIAssets_Cached_0076f020(lua_State* L);
// src: GUESS (confidence: high) [0x0076f040]
int Lua_SetAutoUIAssets_Cached_0076f040(lua_State* L);
// src: GUESS (confidence: high) [0x0076f060]
int Lua_GetAutoUnitCycle_0076f060(lua_State* L);
// src: GUESS (confidence: high) [0x0076f080]
int Lua_GetAutoUnitCycle_Cached_0076f080(lua_State* L);
// src: GUESS (confidence: high) [0x0076f0a0]
int Lua_SetAutoUnitCycle_Cached_0076f0a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f0c0]
int Lua_GetGridOn_0076f0c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f0e0]
int Lua_GetGridOn_Cached_0076f0e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f100]
int Lua_SetGridOn_Cached_0076f100(lua_State* L);
// src: GUESS (confidence: high) [0x0076f120]
int Lua_GetShowTradeOn_0076f120(lua_State* L);
// src: GUESS (confidence: high) [0x0076f140]
int Lua_GetShowTradeOn_Cached_0076f140(lua_State* L);
// src: GUESS (confidence: high) [0x0076f160]
int Lua_SetShowTradeOn_Cached_0076f160(lua_State* L);
// src: GUESS (confidence: high) [0x0076f180]
int Lua_GetScoreList_0076f180(lua_State* L);
// src: GUESS (confidence: high) [0x0076f1a0]
int Lua_GetScoreList_Cached_0076f1a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f1c0]
int Lua_SetScoreList_Cached_0076f1c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f1e0]
int Lua_GetMPScoreList_0076f1e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f200]
int Lua_GetMPScoreList_Cached_0076f200(lua_State* L);
// src: GUESS (confidence: high) [0x0076f220]
int Lua_SetMPScoreList_Cached_0076f220(lua_State* L);
// src: GUESS (confidence: high) [0x0076f240]
int Lua_GetResourceOn_0076f240(lua_State* L);
// src: GUESS (confidence: high) [0x0076f260]
int Lua_GetResourceOn_Cached_0076f260(lua_State* L);
// src: GUESS (confidence: high) [0x0076f280]
int Lua_SetResourceOn_Cached_0076f280(lua_State* L);
// src: GUESS (confidence: high) [0x0076f2a0]
int Lua_GetYieldOn_0076f2a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f2c0]
int Lua_GetYieldOn_Cached_0076f2c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f2e0]
int Lua_SetYieldOn_Cached_0076f2e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f300]
int Lua_GetHideTouchHelp_0076f300(lua_State* L);
// src: GUESS (confidence: high) [0x0076f320]
int Lua_GetHideTouchHelp_Cached_0076f320(lua_State* L);
// src: GUESS (confidence: high) [0x0076f340]
int Lua_SetHideTouchHelp_Cached_0076f340(lua_State* L);
// src: GUESS (confidence: high) [0x0076ea00]
int Lua_IsAutoWorkersDontReplace_0076ea00(lua_State* L);
// src: GUESS (confidence: high) [0x0076ea20]
int Lua_IsAutoWorkersDontReplace_Cached_0076ea20(lua_State* L);
// src: GUESS (confidence: high) [0x0076ea40]
int Lua_SetAutoWorkersDontReplace_Cached_0076ea40(lua_State* L);
// src: GUESS (confidence: high) [0x0076ea60]
int Lua_IsAutoWorkersDontRemoveFeatures_0076ea60(lua_State* L);
// src: GUESS (confidence: high) [0x0076ea80]
int Lua_IsAutoWorkersDontRemoveFeatures_Cached_0076ea80(lua_State* L);
// src: GUESS (confidence: high) [0x0076eaa0]
int Lua_SetAutoWorkersDontRemoveFeatures_Cached_0076eaa0(lua_State* L);
// src: GUESS (confidence: high) [0x0076eac0]
int Lua_IsNoCitizenWarning_0076eac0(lua_State* L);
// src: GUESS (confidence: high) [0x0076eae0]
int Lua_IsNoCitizenWarning_Cached_0076eae0(lua_State* L);
// src: GUESS (confidence: high) [0x0076eb00]
int Lua_SetNoCitizenWarning_Cached_0076eb00(lua_State* L);
// src: GUESS (confidence: high) [0x0076eb20]
int Lua_GetTutorialLevel_0076eb20(lua_State* L);
// src: GUESS (confidence: high) [0x0076eb40]
int Lua_GetTutorialLevel_Cached_0076eb40(lua_State* L);
// src: GUESS (confidence: high) [0x0076eb60]
int Lua_SetTutorialLevel_Cached_0076eb60(lua_State* L);
// src: GUESS (confidence: high) [0x0076eb80]
int Lua_IsNoRewardPopups_0076eb80(lua_State* L);
// src: GUESS (confidence: high) [0x0076eba0]
int Lua_IsNoRewardPopups_Cached_0076eba0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ebc0]
int Lua_SetNoRewardPopups_Cached_0076ebc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ebe0]
int Lua_IsNoTileRecommendations_0076ebe0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ec00]
int Lua_IsNoTileRecommendations_Cached_0076ec00(lua_State* L);
// src: GUESS (confidence: high) [0x0076ec20]
int Lua_SetNoTileRecommendations_Cached_0076ec20(lua_State* L);
// src: GUESS (confidence: high) [0x0076ec40]
int Lua_IsCivilianYields_0076ec40(lua_State* L);
// src: GUESS (confidence: high) [0x0076ec60]
int Lua_IsCivilianYields_Cached_0076ec60(lua_State* L);
// src: GUESS (confidence: high) [0x0076ec80]
int Lua_SetCivilianYields_Cached_0076ec80(lua_State* L);
// src: GUESS (confidence: high) [0x0076eca0]
int Lua_IsNoBasicHelp_0076eca0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ecc0]
int Lua_IsNoBasicHelp_Cached_0076ecc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ece0]
int Lua_SetNoBasicHelp_Cached_0076ece0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ed00]
int Lua_GetQuickSelectionAdvanceEnabled_0076ed00(lua_State* L);
// src: GUESS (confidence: high) [0x0076ed20]
int Lua_GetQuickSelectionAdvanceEnabled_Cached_0076ed20(lua_State* L);
// src: GUESS (confidence: high) [0x0076ed40]
int Lua_SetQuickSelectionAdvanceEnabled_Cached_0076ed40(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb80]
int Lua_GetLANNickName_0076fb80(lua_State* L);
// src: GUESS (confidence: high) [0x0076fba0]
int Lua_GetLANNickName_Cached_0076fba0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fbc0]
int Lua_SetLANNickName_Cached_0076fbc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ed60]
int Lua_GetTurnNotifySteamInvite_0076ed60(lua_State* L);
// src: GUESS (confidence: high) [0x0076ed80]
int Lua_GetTurnNotifySteamInvite_Cached_0076ed80(lua_State* L);
// src: GUESS (confidence: high) [0x0076eda0]
int Lua_SetTurnNotifySteamInvite_Cached_0076eda0(lua_State* L);
// src: GUESS (confidence: high) [0x0076edc0]
int Lua_GetTurnNotifyEmail_0076edc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ede0]
int Lua_GetTurnNotifyEmail_Cached_0076ede0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ee00]
int Lua_SetTurnNotifyEmail_Cached_0076ee00(lua_State* L);
// src: GUESS (confidence: high) [0x0076fc10]
int Lua_GetTurnNotifyEmailAddress_0076fc10(lua_State* L);
// src: GUESS (confidence: high) [0x0076fc30]
int Lua_GetTurnNotifyEmailAddress_Cached_0076fc30(lua_State* L);
// src: GUESS (confidence: high) [0x0076fc50]
int Lua_SetTurnNotifyEmailAddress_Cached_0076fc50(lua_State* L);
// src: GUESS (confidence: high) [0x0076fca0]
int Lua_GetTurnNotifySmtpEmailAddress_0076fca0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fcc0]
int Lua_GetTurnNotifySmtpEmailAddress_Cached_0076fcc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fce0]
int Lua_SetTurnNotifySmtpEmailAddress_Cached_0076fce0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fd30]
int Lua_GetTurnNotifySmtpHost_0076fd30(lua_State* L);
// src: GUESS (confidence: high) [0x0076fd50]
int Lua_GetTurnNotifySmtpHost_Cached_0076fd50(lua_State* L);
// src: GUESS (confidence: high) [0x0076fd70]
int Lua_SetTurnNotifySmtpHost_Cached_0076fd70(lua_State* L);
// src: GUESS (confidence: high) [0x0076ee20]
int Lua_GetTurnNotifySmtpPort_0076ee20(lua_State* L);
// src: GUESS (confidence: high) [0x0076ee40]
int Lua_GetTurnNotifySmtpPort_Cached_0076ee40(lua_State* L);
// src: GUESS (confidence: high) [0x0076ee60]
int Lua_SetTurnNotifySmtpPort_Cached_0076ee60(lua_State* L);
// src: GUESS (confidence: high) [0x0076fdc0]
int Lua_GetTurnNotifySmtpUsername_0076fdc0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fde0]
int Lua_GetTurnNotifySmtpUsername_Cached_0076fde0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fe00]
int Lua_SetTurnNotifySmtpUsername_Cached_0076fe00(lua_State* L);
// src: GUESS (confidence: high) [0x0076fe50]
int Lua_GetTurnNotifySmtpPassword_Cached_0076fe50(lua_State* L);
// src: GUESS (confidence: high) [0x0076fea0]
int Lua_SetTurnNotifySmtpPassword_Cached_0076fea0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ee80]
int Lua_GetTurnNotifySmtpTLS_0076ee80(lua_State* L);
// src: GUESS (confidence: high) [0x0076eea0]
int Lua_GetTurnNotifySmtpTLS_Cached_0076eea0(lua_State* L);
// src: GUESS (confidence: high) [0x0076eec0]
int Lua_SetTurnNotifySmtpTLS_Cached_0076eec0(lua_State* L);
// src: GUESS (confidence: high) [0x0076eee0]
int Lua_GetStraightZoom_0076eee0(lua_State* L);
// src: GUESS (confidence: high) [0x0076ef00]
int Lua_GetStraightZoom_Cached_0076ef00(lua_State* L);
// src: GUESS (confidence: high) [0x0076ef20]
int Lua_SetStraightZoom_Cached_0076ef20(lua_State* L);
// src: GUESS (confidence: high) [0x0076f360]
int Lua_GetBindMouseMode_0076f360(lua_State* L);
// src: GUESS (confidence: high) [0x0076f390]
int Lua_GetBindMouseMode_Cached_0076f390(lua_State* L);
// src: GUESS (confidence: high) [0x0076f3c0]
int Lua_SetBindMouseMode_Cached_0076f3c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f400]
int Lua_GetTooltip1Seconds_0076f400(lua_State* L);
// src: GUESS (confidence: high) [0x0076f430]
int Lua_GetTooltip1Seconds_Cached_0076f430(lua_State* L);
// src: GUESS (confidence: high) [0x0076f460]
int Lua_SetTooltip1Seconds_Cached_0076f460(lua_State* L);
// src: GUESS (confidence: high) [0x0076f4a0]
int Lua_GetTooltip2Seconds_0076f4a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f4d0]
int Lua_GetTooltip2Seconds_Cached_0076f4d0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f500]
int Lua_SetTooltip2Seconds_Cached_0076f500(lua_State* L);
// src: GUESS (confidence: high) [0x0076f540]
int Lua_IsDebugMode_0076f540(lua_State* L);
// src: GUESS (confidence: high) [0x0076f560]
int Lua_IsDebugMode_Cached_0076f560(lua_State* L);
// src: GUESS (confidence: high) [0x0076f580]
int Lua_SetDebugMode_Cached_0076f580(lua_State* L);
// src: GUESS (confidence: high) [0x0076f5a0]
int Lua_GetTurnsBetweenAutosave_0076f5a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f5d0]
int Lua_GetTurnsBetweenAutosave_Cached_0076f5d0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f600]
int Lua_SetTurnsBetweenAutosave_Cached_0076f600(lua_State* L);
// src: GUESS (confidence: high) [0x0076f640]
int Lua_GetNumAutosavesKept_0076f640(lua_State* L);
// src: GUESS (confidence: high) [0x0076f670]
int Lua_GetNumAutosavesKept_Cached_0076f670(lua_State* L);
// src: GUESS (confidence: high) [0x0076f6a0]
int Lua_SetNumAutosavesKept_Cached_0076f6a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f6e0]
int Lua_GetSinglePlayerAutoEndTurnEnabled_0076f6e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f700]
int Lua_GetSinglePlayerAutoEndTurnEnabled_Cached_0076f700(lua_State* L);
// src: GUESS (confidence: high) [0x0076f720]
int Lua_SetSinglePlayerAutoEndTurnEnabled_Cached_0076f720(lua_State* L);
// src: GUESS (confidence: high) [0x0076f740]
int Lua_GetMultiplayerAutoEndTurnEnabled_0076f740(lua_State* L);
// src: GUESS (confidence: high) [0x0076f760]
int Lua_GetMultiplayerAutoEndTurnEnabled_Cached_0076f760(lua_State* L);
// src: GUESS (confidence: high) [0x0076f780]
int Lua_SetMultiplayerAutoEndTurnEnabled_Cached_0076f780(lua_State* L);
// src: GUESS (confidence: high) [0x0076f7a0]
int Lua_GetSinglePlayerQuickCombatEnabled_0076f7a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f7c0]
int Lua_GetSinglePlayerQuickCombatEnabled_Cached_0076f7c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f7e0]
int Lua_SetSinglePlayerQuickCombatEnabled_Cached_0076f7e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f800]
int Lua_GetSinglePlayerQuickMovementEnabled_0076f800(lua_State* L);
// src: GUESS (confidence: high) [0x0076f820]
int Lua_GetSinglePlayerQuickMovementEnabled_Cached_0076f820(lua_State* L);
// src: GUESS (confidence: high) [0x0076f840]
int Lua_SetSinglePlayerQuickMovementEnabled_Cached_0076f840(lua_State* L);
// src: GUESS (confidence: high) [0x0076f860]
int Lua_GetMultiplayerQuickCombatEnabled_0076f860(lua_State* L);
// src: GUESS (confidence: high) [0x0076f880]
int Lua_GetMultiplayerQuickCombatEnabled_Cached_0076f880(lua_State* L);
// src: GUESS (confidence: high) [0x0076f8a0]
int Lua_SetMultiplayerQuickCombatEnabled_Cached_0076f8a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f8c0]
int Lua_GetMultiplayerQuickMovementEnabled_0076f8c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f8e0]
int Lua_GetMultiplayerQuickMovementEnabled_Cached_0076f8e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f900]
int Lua_SetMultiplayerQuickMovementEnabled_Cached_0076f900(lua_State* L);
// src: GUESS (confidence: high) [0x0076f920]
int Lua_GetEnableMapInertia_0076f920(lua_State* L);
// src: GUESS (confidence: high) [0x0076f940]
int Lua_GetEnableMapInertia_Cached_0076f940(lua_State* L);
// src: GUESS (confidence: high) [0x0076f960]
int Lua_SetEnableMapInertia_Cached_0076f960(lua_State* L);
// src: GUESS (confidence: high) [0x0076f980]
int Lua_GetSkipIntroVideo_0076f980(lua_State* L);
// src: GUESS (confidence: high) [0x0076f9a0]
int Lua_GetSkipIntroVideo_Cached_0076f9a0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f9c0]
int Lua_SetSkipIntroVideo_Cached_0076f9c0(lua_State* L);
// src: GUESS (confidence: high) [0x0076f9e0]
int Lua_GetDragSpeed_0076f9e0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fa00]
int Lua_GetDragSpeed_Cached_0076fa00(lua_State* L);
// src: GUESS (confidence: high) [0x0076fa20]
int Lua_SetDragSpeed_Cached_0076fa20(lua_State* L);
// src: GUESS (confidence: high) [0x0076fa40]
int Lua_GetPinchSpeed_0076fa40(lua_State* L);
// src: GUESS (confidence: high) [0x0076fa60]
int Lua_GetPinchSpeed_Cached_0076fa60(lua_State* L);
// src: GUESS (confidence: high) [0x0076fa80]
int Lua_SetPinchSpeed_Cached_0076fa80(lua_State* L);
// src: GUESS (confidence: high) [0x0076faa0]
int Lua_ResetTutorial_0076faa0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fab0]
int Lua_CommitGameOptions_0076fab0(lua_State* L);
// src: GUESS (confidence: high) [0x0076faf0]
int Lua_SyncGameOptionsCache_0076faf0(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb00]
int Lua_CommitGraphicsOptions_0076fb00(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb10]
int Lua_SyncGraphicsOptionsCache_0076fb10(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb20]
int Lua_CommitResolutionOptions_0076fb20(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb30]
int Lua_SyncResolutionOptionsCache_0076fb30(lua_State* L);
// src: GUESS (confidence: high) [0x0076fb40]
int Lua_ResetDefaultGameOptions_0076fb40(lua_State* L);

// src: GUESS (confidence: high) [0x0076fef0]
int RegisterLuaFuncs_0076fef0(lua_State* L)
{
    lua_createtable(L, 0, 0);
    lua_pushcclosure(L, Lua_GetHDStrategicView_Cached_0076e430, 0);
    lua_setfield(L, -2, "GetHDStrategicView_Cached");
    lua_pushcclosure(L, Lua_SetHDStrategicView_Cached_0076e450, 0);
    lua_setfield(L, -2, "SetHDStrategicView_Cached");
    lua_pushcclosure(L, Lua_GetGPUTextureDecode_Cached_0076e470, 0);
    lua_setfield(L, -2, "GetGPUTextureDecode_Cached");
    lua_pushcclosure(L, Lua_SetGPUTextureDecode_Cached_0076e490, 0);
    lua_setfield(L, -2, "SetGPUTextureDecode_Cached");
    lua_pushcclosure(L, Lua_IsGPUTextureDecodeSupported_0076e4b0, 0);
    lua_setfield(L, -2, "IsGPUTextureDecodeSupported");
    lua_pushcclosure(L, Lua_GetOverlayLevel_Cached_0076e4d0, 0);
    lua_setfield(L, -2, "GetOverlayLevel_Cached");
    lua_pushcclosure(L, Lua_SetOverlayLevel_Cached_0076e4f0, 0);
    lua_setfield(L, -2, "SetOverlayLevel_Cached");
    lua_pushcclosure(L, Lua_GetShadowLevel_Cached_0076e510, 0);
    lua_setfield(L, -2, "GetShadowLevel_Cached");
    lua_pushcclosure(L, Lua_SetShadowLevel_Cached_0076e530, 0);
    lua_setfield(L, -2, "SetShadowLevel_Cached");
    lua_pushcclosure(L, Lua_GetFOWLevel_Cached_0076e550, 0);
    lua_setfield(L, -2, "GetFOWLevel_Cached");
    lua_pushcclosure(L, Lua_SetFOWLevel_Cached_0076e570, 0);
    lua_setfield(L, -2, "SetFOWLevel_Cached");
    lua_pushcclosure(L, Lua_GetTerrainDetailLevel_Cached_0076e590, 0);
    lua_setfield(L, -2, "GetTerrainDetailLevel_Cached");
    lua_pushcclosure(L, Lua_SetTerrainDetailLevel_Cached_0076e5b0, 0);
    lua_setfield(L, -2, "SetTerrainDetailLevel_Cached");
    lua_pushcclosure(L, Lua_GetTerrainTessLevel_Cached_0076e5d0, 0);
    lua_setfield(L, -2, "GetTerrainTessLevel_Cached");
    lua_pushcclosure(L, Lua_SetTerrainTessLevel_Cached_0076e5f0, 0);
    lua_setfield(L, -2, "SetTerrainTessLevel_Cached");
    lua_pushcclosure(L, Lua_GetTerrainShadowQuality_Cached_0076e610, 0);
    lua_setfield(L, -2, "GetTerrainShadowQuality_Cached");
    lua_pushcclosure(L, Lua_SetTerrainShadowQuality_Cached_0076e630, 0);
    lua_setfield(L, -2, "SetTerrainShadowQuality_Cached");
    lua_pushcclosure(L, Lua_GetWaterQuality_Cached_0076e650, 0);
    lua_setfield(L, -2, "GetWaterQuality_Cached");
    lua_pushcclosure(L, Lua_SetWaterQuality_Cached_0076e670, 0);
    lua_setfield(L, -2, "SetWaterQuality_Cached");
    lua_pushcclosure(L, Lua_GetTextureQuality_Cached_0076e690, 0);
    lua_setfield(L, -2, "GetTextureQuality_Cached");
    lua_pushcclosure(L, Lua_SetTextureQuality_Cached_0076e6b0, 0);
    lua_setfield(L, -2, "SetTextureQuality_Cached");
    lua_pushcclosure(L, Lua_GetNumContinents_Cached_0076e6d0, 0);
    lua_setfield(L, -2, "GetNumContinents_Cached");
    lua_pushcclosure(L, Lua_SetNumContinents_Cached_0076e6f0, 0);
    lua_setfield(L, -2, "SetNumContinents_Cached");
    lua_pushcclosure(L, Lua_GetVSync_Cached_0076e710, 0);
    lua_setfield(L, -2, "GetVSync_Cached");
    lua_pushcclosure(L, Lua_SetVSync_Cached_0076e730, 0);
    lua_setfield(L, -2, "SetVSync_Cached");
    lua_pushcclosure(L, Lua_GetMinimizeGrayTiles_Cached_0076e750, 0);
    lua_setfield(L, -2, "GetMinimizeGrayTiles_Cached");
    lua_pushcclosure(L, Lua_SetMinimizeGrayTiles_Cached_0076e770, 0);
    lua_setfield(L, -2, "SetMinimizeGrayTiles_Cached");
    lua_pushcclosure(L, Lua_GetFadeShadows_Cached_0076e790, 0);
    lua_setfield(L, -2, "GetFadeShadows_Cached");
    lua_pushcclosure(L, Lua_SetFadeShadows_Cached_0076e7b0, 0);
    lua_setfield(L, -2, "SetFadeShadows_Cached");
    lua_pushcclosure(L, Lua_GetLeaderQuality_Cached_0076e7d0, 0);
    lua_setfield(L, -2, "GetLeaderQuality_Cached");
    lua_pushcclosure(L, Lua_SetLeaderQuality_Cached_0076e7f0, 0);
    lua_setfield(L, -2, "SetLeaderQuality_Cached");
    lua_pushcclosure(L, Lua_ResetDefaultGraphicsOptions_0076e810, 0);
    lua_setfield(L, -2, "ResetDefaultGraphicsOptions");
    lua_pushcclosure(L, Lua_HasUserChangedGraphicsOptions_0076e820, 0);
    lua_setfield(L, -2, "HasUserChangedGraphicsOptions");
    lua_pushcclosure(L, Lua_GetAASamples_Cached_0076e840, 0);
    lua_setfield(L, -2, "GetAASamples_Cached");
    lua_pushcclosure(L, Lua_SetAASamples_Cached_0076e860, 0);
    lua_setfield(L, -2, "SetAASamples_Cached");
    lua_pushcclosure(L, Lua_IsAALevelSupported_0076e880, 0);
    lua_setfield(L, -2, "IsAALevelSupported");
    lua_pushcclosure(L, Lua_GetFullscreen_0076e900, 0);
    lua_setfield(L, -2, "GetFullscreen");
    lua_pushcclosure(L, Lua_GetFullscreen_Cached_0076e8e0, 0);
    lua_setfield(L, -2, "GetFullscreen_Cached");
    lua_pushcclosure(L, Lua_SetFullscreen_Cached_0076e920, 0);
    lua_setfield(L, -2, "SetFullscreen_Cached");
    lua_pushcclosure(L, Lua_GetResolution_Cached_0076e940, 0);
    lua_setfield(L, -2, "GetResolution_Cached");
    lua_pushcclosure(L, Lua_SetResolution_Cached_0076e960, 0);
    lua_setfield(L, -2, "SetResolution_Cached");
    lua_pushcclosure(L, Lua_GetWindowResolution_Cached_0076e980, 0);
    lua_setfield(L, -2, "GetWindowResolution_Cached");
    lua_pushcclosure(L, Lua_SetWindowResolution_Cached_0076fb50, 0);
    lua_setfield(L, -2, "SetWindowResolution_Cached");
    lua_pushcclosure(L, Lua_HasUserChangedResolution_0076e9e0, 0);
    lua_setfield(L, -2, "HasUserChangedResolution");
    lua_pushcclosure(L, Lua_GetMaxResolution_0076e9b0, 0);
    lua_setfield(L, -2, "GetMaxResolution");
    lua_pushcclosure(L, Lua_GetPolicyInfo_0076ef40, 0);
    lua_setfield(L, -2, "GetPolicyInfo");
    lua_pushcclosure(L, Lua_GetPolicyInfo_Cached_0076ef60, 0);
    lua_setfield(L, -2, "GetPolicyInfo_Cached");
    lua_pushcclosure(L, Lua_SetPolicyInfo_Cached_0076ef80, 0);
    lua_setfield(L, -2, "SetPolicyInfo_Cached");
    lua_pushcclosure(L, Lua_GetSmallUIAssets_0076efa0, 0);
    lua_setfield(L, -2, "GetSmallUIAssets");
    lua_pushcclosure(L, Lua_GetSmallUIAssets_Cached_0076efc0, 0);
    lua_setfield(L, -2, "GetSmallUIAssets_Cached");
    lua_pushcclosure(L, Lua_SetSmallUIAssets_Cached_0076efe0, 0);
    lua_setfield(L, -2, "SetSmallUIAssets_Cached");
    lua_pushcclosure(L, Lua_GetAutoUIAssets_0076f000, 0);
    lua_setfield(L, -2, "GetAutoUIAssets");
    lua_pushcclosure(L, Lua_GetAutoUIAssets_Cached_0076f020, 0);
    lua_setfield(L, -2, "GetAutoUIAssets_Cached");
    lua_pushcclosure(L, Lua_SetAutoUIAssets_Cached_0076f040, 0);
    lua_setfield(L, -2, "SetAutoUIAssets_Cached");
    lua_pushcclosure(L, Lua_GetAutoUnitCycle_0076f060, 0);
    lua_setfield(L, -2, "GetAutoUnitCycle");
    lua_pushcclosure(L, Lua_GetAutoUnitCycle_Cached_0076f080, 0);
    lua_setfield(L, -2, "GetAutoUnitCycle_Cached");
    lua_pushcclosure(L, Lua_SetAutoUnitCycle_Cached_0076f0a0, 0);
    lua_setfield(L, -2, "SetAutoUnitCycle_Cached");
    lua_pushcclosure(L, Lua_GetGridOn_0076f0c0, 0);
    lua_setfield(L, -2, "GetGridOn");
    lua_pushcclosure(L, Lua_GetGridOn_Cached_0076f0e0, 0);
    lua_setfield(L, -2, "GetGridOn_Cached");
    lua_pushcclosure(L, Lua_SetGridOn_Cached_0076f100, 0);
    lua_setfield(L, -2, "SetGridOn_Cached");
    lua_pushcclosure(L, Lua_GetShowTradeOn_0076f120, 0);
    lua_setfield(L, -2, "GetShowTradeOn");
    lua_pushcclosure(L, Lua_GetShowTradeOn_Cached_0076f140, 0);
    lua_setfield(L, -2, "GetShowTradeOn_Cached");
    lua_pushcclosure(L, Lua_SetShowTradeOn_Cached_0076f160, 0);
    lua_setfield(L, -2, "SetShowTradeOn_Cached");
    lua_pushcclosure(L, Lua_GetScoreList_0076f180, 0);
    lua_setfield(L, -2, "GetScoreList");
    lua_pushcclosure(L, Lua_GetScoreList_Cached_0076f1a0, 0);
    lua_setfield(L, -2, "GetScoreList_Cached");
    lua_pushcclosure(L, Lua_SetScoreList_Cached_0076f1c0, 0);
    lua_setfield(L, -2, "SetScoreList_Cached");
    lua_pushcclosure(L, Lua_GetMPScoreList_0076f1e0, 0);
    lua_setfield(L, -2, "GetMPScoreList");
    lua_pushcclosure(L, Lua_GetMPScoreList_Cached_0076f200, 0);
    lua_setfield(L, -2, "GetMPScoreList_Cached");
    lua_pushcclosure(L, Lua_SetMPScoreList_Cached_0076f220, 0);
    lua_setfield(L, -2, "SetMPScoreList_Cached");
    lua_pushcclosure(L, Lua_GetResourceOn_0076f240, 0);
    lua_setfield(L, -2, "GetResourceOn");
    lua_pushcclosure(L, Lua_GetResourceOn_Cached_0076f260, 0);
    lua_setfield(L, -2, "GetResourceOn_Cached");
    lua_pushcclosure(L, Lua_SetResourceOn_Cached_0076f280, 0);
    lua_setfield(L, -2, "SetResourceOn_Cached");
    lua_pushcclosure(L, Lua_GetYieldOn_0076f2a0, 0);
    lua_setfield(L, -2, "GetYieldOn");
    lua_pushcclosure(L, Lua_GetYieldOn_Cached_0076f2c0, 0);
    lua_setfield(L, -2, "GetYieldOn_Cached");
    lua_pushcclosure(L, Lua_SetYieldOn_Cached_0076f2e0, 0);
    lua_setfield(L, -2, "SetYieldOn_Cached");
    lua_pushcclosure(L, Lua_GetHideTouchHelp_0076f300, 0);
    lua_setfield(L, -2, "GetHideTouchHelp");
    lua_pushcclosure(L, Lua_GetHideTouchHelp_Cached_0076f320, 0);
    lua_setfield(L, -2, "GetHideTouchHelp_Cached");
    lua_pushcclosure(L, Lua_SetHideTouchHelp_Cached_0076f340, 0);
    lua_setfield(L, -2, "SetHideTouchHelp_Cached");
    lua_pushcclosure(L, Lua_IsAutoWorkersDontReplace_0076ea00, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontReplace");
    lua_pushcclosure(L, Lua_IsAutoWorkersDontReplace_Cached_0076ea20, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontReplace_Cached");
    lua_pushcclosure(L, Lua_SetAutoWorkersDontReplace_Cached_0076ea40, 0);
    lua_setfield(L, -2, "SetAutoWorkersDontReplace_Cached");
    lua_pushcclosure(L, Lua_IsAutoWorkersDontRemoveFeatures_0076ea60, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontRemoveFeatures");
    lua_pushcclosure(L, Lua_IsAutoWorkersDontRemoveFeatures_Cached_0076ea80, 0);
    lua_setfield(L, -2, "IsAutoWorkersDontRemoveFeatures_Cached");
    lua_pushcclosure(L, Lua_SetAutoWorkersDontRemoveFeatures_Cached_0076eaa0, 0);
    lua_setfield(L, -2, "SetAutoWorkersDontRemoveFeatures_Cached");
    lua_pushcclosure(L, Lua_IsNoCitizenWarning_0076eac0, 0);
    lua_setfield(L, -2, "IsNoCitizenWarning");
    lua_pushcclosure(L, Lua_IsNoCitizenWarning_Cached_0076eae0, 0);
    lua_setfield(L, -2, "IsNoCitizenWarning_Cached");
    lua_pushcclosure(L, Lua_SetNoCitizenWarning_Cached_0076eb00, 0);
    lua_setfield(L, -2, "SetNoCitizenWarning_Cached");
    lua_pushcclosure(L, Lua_GetTutorialLevel_0076eb20, 0);
    lua_setfield(L, -2, "GetTutorialLevel");
    lua_pushcclosure(L, Lua_GetTutorialLevel_Cached_0076eb40, 0);
    lua_setfield(L, -2, "GetTutorialLevel_Cached");
    lua_pushcclosure(L, Lua_SetTutorialLevel_Cached_0076eb60, 0);
    lua_setfield(L, -2, "SetTutorialLevel_Cached");
    lua_pushcclosure(L, Lua_IsNoRewardPopups_0076eb80, 0);
    lua_setfield(L, -2, "IsNoRewardPopups");
    lua_pushcclosure(L, Lua_IsNoRewardPopups_Cached_0076eba0, 0);
    lua_setfield(L, -2, "IsNoRewardPopups_Cached");
    lua_pushcclosure(L, Lua_SetNoRewardPopups_Cached_0076ebc0, 0);
    lua_setfield(L, -2, "SetNoRewardPopups_Cached");
    lua_pushcclosure(L, Lua_IsNoTileRecommendations_0076ebe0, 0);
    lua_setfield(L, -2, "IsNoTileRecommendations");
    lua_pushcclosure(L, Lua_IsNoTileRecommendations_Cached_0076ec00, 0);
    lua_setfield(L, -2, "IsNoTileRecommendations_Cached");
    lua_pushcclosure(L, Lua_SetNoTileRecommendations_Cached_0076ec20, 0);
    lua_setfield(L, -2, "SetNoTileRecommendations_Cached");
    lua_pushcclosure(L, Lua_IsCivilianYields_0076ec40, 0);
    lua_setfield(L, -2, "IsCivilianYields");
    lua_pushcclosure(L, Lua_IsCivilianYields_Cached_0076ec60, 0);
    lua_setfield(L, -2, "IsCivilianYields_Cached");
    lua_pushcclosure(L, Lua_SetCivilianYields_Cached_0076ec80, 0);
    lua_setfield(L, -2, "SetCivilianYields_Cached");
    lua_pushcclosure(L, Lua_IsNoBasicHelp_0076eca0, 0);
    lua_setfield(L, -2, "IsNoBasicHelp");
    lua_pushcclosure(L, Lua_IsNoBasicHelp_Cached_0076ecc0, 0);
    lua_setfield(L, -2, "IsNoBasicHelp_Cached");
    lua_pushcclosure(L, Lua_SetNoBasicHelp_Cached_0076ece0, 0);
    lua_setfield(L, -2, "SetNoBasicHelp_Cached");
    lua_pushcclosure(L, Lua_GetQuickSelectionAdvanceEnabled_0076ed00, 0);
    lua_setfield(L, -2, "GetQuickSelectionAdvanceEnabled");
    lua_pushcclosure(L, Lua_GetQuickSelectionAdvanceEnabled_Cached_0076ed20, 0);
    lua_setfield(L, -2, "GetQuickSelectionAdvanceEnabled_Cached");
    lua_pushcclosure(L, Lua_SetQuickSelectionAdvanceEnabled_Cached_0076ed40, 0);
    lua_setfield(L, -2, "SetQuickSelectionAdvanceEnabled_Cached");
    lua_pushcclosure(L, Lua_GetLANNickName_0076fb80, 0);
    lua_setfield(L, -2, "GetLANNickName");
    lua_pushcclosure(L, Lua_GetLANNickName_Cached_0076fba0, 0);
    lua_setfield(L, -2, "GetLANNickName_Cached");
    lua_pushcclosure(L, Lua_SetLANNickName_Cached_0076fbc0, 0);
    lua_setfield(L, -2, "SetLANNickName_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySteamInvite_0076ed60, 0);
    lua_setfield(L, -2, "GetTurnNotifySteamInvite");
    lua_pushcclosure(L, Lua_GetTurnNotifySteamInvite_Cached_0076ed80, 0);
    lua_setfield(L, -2, "GetTurnNotifySteamInvite_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySteamInvite_Cached_0076eda0, 0);
    lua_setfield(L, -2, "SetTurnNotifySteamInvite_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifyEmail_0076edc0, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmail");
    lua_pushcclosure(L, Lua_GetTurnNotifyEmail_Cached_0076ede0, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmail_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifyEmail_Cached_0076ee00, 0);
    lua_setfield(L, -2, "SetTurnNotifyEmail_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifyEmailAddress_0076fc10, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmailAddress");
    lua_pushcclosure(L, Lua_GetTurnNotifyEmailAddress_Cached_0076fc30, 0);
    lua_setfield(L, -2, "GetTurnNotifyEmailAddress_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifyEmailAddress_Cached_0076fc50, 0);
    lua_setfield(L, -2, "SetTurnNotifyEmailAddress_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpEmailAddress_0076fca0, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpEmailAddress");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpEmailAddress_Cached_0076fcc0, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpEmailAddress_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySmtpEmailAddress_Cached_0076fce0, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpEmailAddress_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpHost_0076fd30, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpHost");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpHost_Cached_0076fd50, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpHost_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySmtpHost_Cached_0076fd70, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpHost_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpPort_0076ee20, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpPort");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpPort_Cached_0076ee40, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpPort_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySmtpPort_Cached_0076ee60, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpPort_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpUsername_0076fdc0, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpUsername");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpUsername_Cached_0076fde0, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpUsername_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySmtpUsername_Cached_0076fe00, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpUsername_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpPassword_Cached_0076fe50, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpPassword_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySmtpPassword_Cached_0076fea0, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpPassword_Cached");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpTLS_0076ee80, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpTLS");
    lua_pushcclosure(L, Lua_GetTurnNotifySmtpTLS_Cached_0076eea0, 0);
    lua_setfield(L, -2, "GetTurnNotifySmtpTLS_Cached");
    lua_pushcclosure(L, Lua_SetTurnNotifySmtpTLS_Cached_0076eec0, 0);
    lua_setfield(L, -2, "SetTurnNotifySmtpTLS_Cached");
    lua_pushcclosure(L, Lua_GetStraightZoom_0076eee0, 0);
    lua_setfield(L, -2, "GetStraightZoom");
    lua_pushcclosure(L, Lua_GetStraightZoom_Cached_0076ef00, 0);
    lua_setfield(L, -2, "GetStraightZoom_Cached");
    lua_pushcclosure(L, Lua_SetStraightZoom_Cached_0076ef20, 0);
    lua_setfield(L, -2, "SetStraightZoom_Cached");
    lua_pushcclosure(L, Lua_GetBindMouseMode_0076f360, 0);
    lua_setfield(L, -2, "GetBindMouseMode");
    lua_pushcclosure(L, Lua_GetBindMouseMode_Cached_0076f390, 0);
    lua_setfield(L, -2, "GetBindMouseMode_Cached");
    lua_pushcclosure(L, Lua_SetBindMouseMode_Cached_0076f3c0, 0);
    lua_setfield(L, -2, "SetBindMouseMode_Cached");
    lua_pushcclosure(L, Lua_GetTooltip1Seconds_0076f400, 0);
    lua_setfield(L, -2, "GetTooltip1Seconds");
    lua_pushcclosure(L, Lua_GetTooltip1Seconds_Cached_0076f430, 0);
    lua_setfield(L, -2, "GetTooltip1Seconds_Cached");
    lua_pushcclosure(L, Lua_SetTooltip1Seconds_Cached_0076f460, 0);
    lua_setfield(L, -2, "SetTooltip1Seconds_Cached");
    lua_pushcclosure(L, Lua_GetTooltip2Seconds_0076f4a0, 0);
    lua_setfield(L, -2, "GetTooltip2Seconds");
    lua_pushcclosure(L, Lua_GetTooltip2Seconds_Cached_0076f4d0, 0);
    lua_setfield(L, -2, "GetTooltip2Seconds_Cached");
    lua_pushcclosure(L, Lua_SetTooltip2Seconds_Cached_0076f500, 0);
    lua_setfield(L, -2, "SetTooltip2Seconds_Cached");
    lua_pushcclosure(L, Lua_IsDebugMode_0076f540, 0);
    lua_setfield(L, -2, "IsDebugMode");
    lua_pushcclosure(L, Lua_IsDebugMode_Cached_0076f560, 0);
    lua_setfield(L, -2, "IsDebugMode_Cached");
    lua_pushcclosure(L, Lua_SetDebugMode_Cached_0076f580, 0);
    lua_setfield(L, -2, "SetDebugMode_Cached");
    lua_pushcclosure(L, Lua_GetTurnsBetweenAutosave_0076f5a0, 0);
    lua_setfield(L, -2, "GetTurnsBetweenAutosave");
    lua_pushcclosure(L, Lua_GetTurnsBetweenAutosave_Cached_0076f5d0, 0);
    lua_setfield(L, -2, "GetTurnsBetweenAutosave_Cached");
    lua_pushcclosure(L, Lua_SetTurnsBetweenAutosave_Cached_0076f600, 0);
    lua_setfield(L, -2, "SetTurnsBetweenAutosave_Cached");
    lua_pushcclosure(L, Lua_GetNumAutosavesKept_0076f640, 0);
    lua_setfield(L, -2, "GetNumAutosavesKept");
    lua_pushcclosure(L, Lua_GetNumAutosavesKept_Cached_0076f670, 0);
    lua_setfield(L, -2, "GetNumAutosavesKept_Cached");
    lua_pushcclosure(L, Lua_SetNumAutosavesKept_Cached_0076f6a0, 0);
    lua_setfield(L, -2, "SetNumAutosavesKept_Cached");
    lua_pushcclosure(L, Lua_GetSinglePlayerAutoEndTurnEnabled_0076f6e0, 0);
    lua_setfield(L, -2, "GetSinglePlayerAutoEndTurnEnabled");
    lua_pushcclosure(L, Lua_GetSinglePlayerAutoEndTurnEnabled_Cached_0076f700, 0);
    lua_setfield(L, -2, "GetSinglePlayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, Lua_SetSinglePlayerAutoEndTurnEnabled_Cached_0076f720, 0);
    lua_setfield(L, -2, "SetSinglePlayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, Lua_GetMultiplayerAutoEndTurnEnabled_0076f740, 0);
    lua_setfield(L, -2, "GetMultiplayerAutoEndTurnEnabled");
    lua_pushcclosure(L, Lua_GetMultiplayerAutoEndTurnEnabled_Cached_0076f760, 0);
    lua_setfield(L, -2, "GetMultiplayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, Lua_SetMultiplayerAutoEndTurnEnabled_Cached_0076f780, 0);
    lua_setfield(L, -2, "SetMultiplayerAutoEndTurnEnabled_Cached");
    lua_pushcclosure(L, Lua_GetSinglePlayerQuickCombatEnabled_0076f7a0, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickCombatEnabled");
    lua_pushcclosure(L, Lua_GetSinglePlayerQuickCombatEnabled_Cached_0076f7c0, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, Lua_SetSinglePlayerQuickCombatEnabled_Cached_0076f7e0, 0);
    lua_setfield(L, -2, "SetSinglePlayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, Lua_GetSinglePlayerQuickMovementEnabled_0076f800, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickMovementEnabled");
    lua_pushcclosure(L, Lua_GetSinglePlayerQuickMovementEnabled_Cached_0076f820, 0);
    lua_setfield(L, -2, "GetSinglePlayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, Lua_SetSinglePlayerQuickMovementEnabled_Cached_0076f840, 0);
    lua_setfield(L, -2, "SetSinglePlayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, Lua_GetMultiplayerQuickCombatEnabled_0076f860, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickCombatEnabled");
    lua_pushcclosure(L, Lua_GetMultiplayerQuickCombatEnabled_Cached_0076f880, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, Lua_SetMultiplayerQuickCombatEnabled_Cached_0076f8a0, 0);
    lua_setfield(L, -2, "SetMultiplayerQuickCombatEnabled_Cached");
    lua_pushcclosure(L, Lua_GetMultiplayerQuickMovementEnabled_0076f8c0, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickMovementEnabled");
    lua_pushcclosure(L, Lua_GetMultiplayerQuickMovementEnabled_Cached_0076f8e0, 0);
    lua_setfield(L, -2, "GetMultiplayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, Lua_SetMultiplayerQuickMovementEnabled_Cached_0076f900, 0);
    lua_setfield(L, -2, "SetMultiplayerQuickMovementEnabled_Cached");
    lua_pushcclosure(L, Lua_GetEnableMapInertia_0076f920, 0);
    lua_setfield(L, -2, "GetEnableMapInertia");
    lua_pushcclosure(L, Lua_GetEnableMapInertia_Cached_0076f940, 0);
    lua_setfield(L, -2, "GetEnableMapInertia_Cached");
    lua_pushcclosure(L, Lua_SetEnableMapInertia_Cached_0076f960, 0);
    lua_setfield(L, -2, "SetEnableMapInertia_Cached");
    lua_pushcclosure(L, Lua_GetSkipIntroVideo_0076f980, 0);
    lua_setfield(L, -2, "GetSkipIntroVideo");
    lua_pushcclosure(L, Lua_GetSkipIntroVideo_Cached_0076f9a0, 0);
    lua_setfield(L, -2, "GetSkipIntroVideo_Cached");
    lua_pushcclosure(L, Lua_SetSkipIntroVideo_Cached_0076f9c0, 0);
    lua_setfield(L, -2, "SetSkipIntroVideo_Cached");
    lua_pushcclosure(L, Lua_GetDragSpeed_0076f9e0, 0);
    lua_setfield(L, -2, "GetDragSpeed");
    lua_pushcclosure(L, Lua_GetDragSpeed_Cached_0076fa00, 0);
    lua_setfield(L, -2, "GetDragSpeed_Cached");
    lua_pushcclosure(L, Lua_SetDragSpeed_Cached_0076fa20, 0);
    lua_setfield(L, -2, "SetDragSpeed_Cached");
    lua_pushcclosure(L, Lua_GetPinchSpeed_0076fa40, 0);
    lua_setfield(L, -2, "GetPinchSpeed");
    lua_pushcclosure(L, Lua_GetPinchSpeed_Cached_0076fa60, 0);
    lua_setfield(L, -2, "GetPinchSpeed_Cached");
    lua_pushcclosure(L, Lua_SetPinchSpeed_Cached_0076fa80, 0);
    lua_setfield(L, -2, "SetPinchSpeed_Cached");
    lua_pushcclosure(L, Lua_ResetTutorial_0076faa0, 0);
    lua_setfield(L, -2, "ResetTutorial");
    lua_pushcclosure(L, Lua_CommitGameOptions_0076fab0, 0);
    lua_setfield(L, -2, "CommitGameOptions");
    lua_pushcclosure(L, Lua_SyncGameOptionsCache_0076faf0, 0);
    lua_setfield(L, -2, "SyncGameOptionsCache");
    lua_pushcclosure(L, Lua_CommitGraphicsOptions_0076fb00, 0);
    lua_setfield(L, -2, "CommitGraphicsOptions");
    lua_pushcclosure(L, Lua_SyncGraphicsOptionsCache_0076fb10, 0);
    lua_setfield(L, -2, "SyncGraphicsOptionsCache");
    lua_pushcclosure(L, Lua_CommitResolutionOptions_0076fb20, 0);
    lua_setfield(L, -2, "CommitResolutionOptions");
    lua_pushcclosure(L, Lua_SyncResolutionOptionsCache_0076fb30, 0);
    lua_setfield(L, -2, "SyncResolutionOptionsCache");
    lua_pushcclosure(L, Lua_HasUserChangedResolution_0076e9e0, 0);
    lua_setfield(L, -2, "HasUserChangedResolution\0");
    lua_pushcclosure(L, Lua_ResetDefaultGameOptions_0076fb40, 0);
    lua_setfield(L, -2, "ResetDefaultGameOptions");
    return 1;
}
