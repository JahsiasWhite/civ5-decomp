// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0064fd80]

#include "LuaApi.h"

// src: EXE [0x00a70f04]
extern const char g_str_MainMenu_00a70f04[];
// src: EXE [0x00a7100c]
extern const char g_str_PopupPriority_00a7100c[];
// src: EXE [0x00a7101c]
extern const char g_str_LegalScreen_00a7101c[];
// src: EXE [0x00a71028]
extern const char g_str_SinglePlayerScreen_00a71028[];
// src: EXE [0x00a7103c]
extern const char g_str_MultiplayerSelectScreen_00a7103c[];
// src: EXE [0x00a71054]
extern const char g_str_ModsEULAScreen_00a71054[];
// src: EXE [0x00a71064]
extern const char g_str_OtherMenu_00a71064[];
// src: EXE [0x00a71070]
extern const char g_str_Credits_00a71070[];
// src: EXE [0x00a71078]
extern const char g_str_GameSetupScreen_00a71078[];
// src: EXE [0x00a71088]
extern const char g_str_LoadGameScreen_00a71088[];
// src: EXE [0x00a71098]
extern const char g_str_LoadTutorial_00a71098[];
// src: EXE [0x00a710a8]
extern const char g_str_ModsMenuScreen_00a710a8[];
// src: EXE [0x00a710b8]
extern const char g_str_ModdingScenarioSetupScreen_00a710b8[];
// src: EXE [0x00a710d4]
extern const char g_str_ModdingSinglePlayer_00a710d4[];
// src: EXE [0x00a710e8]
extern const char g_str_ModMultiplayerSelectScreen_00a710e8[];
// src: EXE [0x00a71104]
extern const char g_str_ModsBrowserScreen_00a71104[];
// src: EXE [0x00a71118]
extern const char g_str_ModdingGameSetupScreen_00a71118[];
// src: EXE [0x00a71130]
extern const char g_str_ModsCustom_00a71130[];
// src: EXE [0x00a7113c]
extern const char g_str_LoadGameScreen_00a7113c[];
// src: EXE [0x00a7114c]
extern const char g_str_AdvancedSetup_00a7114c[];
// src: EXE [0x00a7115c]
extern const char g_str_SelectCivilization_00a7115c[];
// src: EXE [0x00a71170]
extern const char g_str_Civilopedia_00a71170[];
// src: EXE [0x00a7117c]
extern const char g_str_GenericPopup_00a7117c[];
// src: EXE [0x00a7118c]
extern const char g_str_TextPopup_00a7118c[];
// src: EXE [0x00a71198]
extern const char g_str_LeaderHead_00a71198[];
// src: EXE [0x00a711a4]
extern const char g_str_CustomMod_00a711a4[];
// src: EXE [0x00a711b0]
extern const char g_str_LobbyScreen_00a711b0[];
// src: EXE [0x00a711bc]
extern const char g_str_MPLoadGameScreen_00a711bc[];
// src: EXE [0x00a711d0]
extern const char g_str_MPGameSetupScreen_00a711d0[];
// src: EXE [0x00a711e4]
extern const char g_str_JoiningScreen_00a711e4[];
// src: EXE [0x00a711f4]
extern const char g_str_StagingScreen_00a711f4[];
// src: EXE [0x00a71204]
extern const char g_str_AdvisorCounsel_00a71204[];
// src: EXE [0x00a71214]
extern const char g_str_AdvisorInfo_00a71214[];
// src: EXE [0x00a71220]
extern const char g_str_AdvisorModal_00a71220[];
// src: EXE [0x00a71230]
extern const char g_str_BarbarianCamp_00a71230[];
// src: EXE [0x00a71240]
extern const char g_str_CityStateDiplo_00a71240[];
// src: EXE [0x00a71250]
extern const char g_str_CityStateGreeting_00a71250[];
// src: EXE [0x00a71264]
extern const char g_str_GoldenAge_00a71264[];
// src: EXE [0x00a71270]
extern const char g_str_GreatPersonReward_00a71270[];
// src: EXE [0x00a71284]
extern const char g_str_CityStateList_00a71284[];
// src: EXE [0x00a71294]
extern const char g_str_NaturalWonderPopup_00a71294[];
// src: EXE [0x00a712a8]
extern const char g_str_VoteResults_00a712a8[];
// src: EXE [0x00a712b4]
extern const char g_str_NotificationLog_00a712b4[];
// src: EXE [0x00a712c4]
extern const char g_str_NewEraPopup_00a712c4[];
// src: EXE [0x00a712d0]
extern const char g_str_TechAward_00a712d0[];
// src: EXE [0x00a712dc]
extern const char g_str_WhosWinning_00a712dc[];
// src: EXE [0x00a712e8]
extern const char g_str_GoodyHut_00a712e8[];
// src: EXE [0x00a712f4]
extern const char g_str_WonderPopup_00a712f4[];
// src: EXE [0x00a71300]
extern const char g_str_DiploOverview_00a71300[];
// src: EXE [0x00a71310]
extern const char g_str_MilitaryOverview_00a71310[];
// src: EXE [0x00a71324]
extern const char g_str_EconOverview_00a71324[];
// src: EXE [0x00a71334]
extern const char g_str_ProductionPopup_00a71334[];
// src: EXE [0x00a71344]
extern const char g_str_SocialPolicy_00a71344[];
// src: EXE [0x00a71354]
extern const char g_str_DiploVote_00a71354[];
// src: EXE [0x00a71360]
extern const char g_str_TechTree_00a71360[];
// src: EXE [0x00a7136c]
extern const char g_str_EndGameMenu_00a7136c[];
// src: EXE [0x00a71378]
extern const char g_str_VictoryProgress_00a71378[];
// src: EXE [0x00a71388]
extern const char g_str_Demographics_00a71388[];
// src: EXE [0x00a71398]
extern const char g_str_InGameMenu_00a71398[];
// src: EXE [0x00a713a4]
extern const char g_str_OptionsMenu_00a713a4[];
// src: EXE [0x00a713b0]
extern const char g_str_SaveMenu_00a713b0[];
// src: EXE [0x00a713bc]
extern const char g_str_LoadMenu_00a713bc[];
// src: EXE [0x00a713c8]
extern const char g_str_SaveMapMenu_00a713c8[];
// src: EXE [0x00a713d4]
extern const char g_str_HallOfFame_00a713d4[];
// src: EXE [0x00a713e0]
extern const char g_str_Leaderboard_00a713e0[];
// src: EXE [0x00a713ec]
extern const char g_str_LeaderDiscuss_00a713ec[];
// src: EXE [0x00a713fc]
extern const char g_str_LeaderTrade_00a713fc[];
// src: EXE [0x00a71408]
extern const char g_str_LeaderHeadPopup_00a71408[];
// src: EXE [0x00a71418]
extern const char g_str_PlayerChange_00a71418[];
// src: EXE [0x00a71428]
extern const char g_str_InGameUtmost_00a71428[];
// src: EXE [0x00a71438]
extern const char g_str_eUtmost_00a71438[];
// src: EXE [0x00a71440]
extern const char g_str_Current_00a71440[];
// src: EXE [0x00a71448]
extern const char g_str_Default_00a71448[];
// src: EXE [0x00a71450]
extern const char g_str_EndGameTypes_00a71450[];
// src: EXE [0x00a71460]
extern const char g_str_Technology_00a71460[];
// src: EXE [0x00a7146c]
extern const char g_str_Culture_00a7146c[];
// src: EXE [0x00a71474]
extern const char g_str_Domination_00a71474[];
// src: EXE [0x00a71480]
extern const char g_str_Diplomatic_00a71480[];
// src: EXE [0x00a7148c]
extern const char g_str_Time_00a7148c[];
// src: EXE [0x00a71494]
extern const char g_str_Tutorial1_00a71494[];
// src: EXE [0x00a714a0]
extern const char g_str_Tutorial2_00a714a0[];
// src: EXE [0x00a714ac]
extern const char g_str_Tutorial3_00a714ac[];
// src: EXE [0x00a714b8]
extern const char g_str_Tutorial4_00a714b8[];
// src: EXE [0x00a714c4]
extern const char g_str_Tutorial5_00a714c4[];
// src: EXE [0x00a714d0]
extern const char g_str_Loss_00a714d0[];
// src: EXE [0x00a714d8]
extern const char g_str_SystemUpdateUIType_00a714d8[];
// src: EXE [0x00a714ec]
extern const char g_str_ScreenResize_00a714ec[];
// src: EXE [0x00a714fc]
extern const char g_str_ReloadUI_00a714fc[];
// src: EXE [0x00a71508]
extern const char g_str_ReprocessAnchoring_00a71508[];
// src: EXE [0x00a7151c]
extern const char g_str_BulkHideUI_00a7151c[];
// src: EXE [0x00a71528]
extern const char g_str_BulkShowUI_00a71528[];
// src: EXE [0x00a71534]
extern const char g_str_UnloadUI_00a71534[];
// src: EXE [0x00a71540]
extern const char g_str_RestoreUI_00a71540[];
// src: EXE [0x00a7154c]
extern const char g_str_YieldDisplayTypes_00a7154c[];
// src: EXE [0x00a71560]
extern const char g_str_USER_ALL_ON_00a71560[];
// src: EXE [0x00a7156c]
extern const char g_str_USER_ALL_OFF_00a7156c[];
// src: EXE [0x00a7157c]
extern const char g_str_USER_ALL_RESOURCE_ON_00a7157c[];
// src: EXE [0x00a71594]
extern const char g_str_USER_ALL_RESOURCE_OFF_00a71594[];
// src: EXE [0x00a715ac]
extern const char g_str_EMPIRE_00a715ac[];
// src: EXE [0x00a715b4]
extern const char g_str_CITY_OWNED_00a715b4[];
// src: EXE [0x00a715c0]
extern const char g_str_CITY_WORKED_00a715c0[];
// src: EXE [0x00a715cc]
extern const char g_str_CITY_PURCHASABLE_00a715cc[];
// src: EXE [0x00a715e0]
extern const char g_str_AREA_00a715e0[];
// src: EXE [0x00a715e8]
extern const char g_str_ButtonStates_00a715e8[];
// src: EXE [0x00a715f8]
extern const char g_str_eNormal_00a715f8[];
// src: EXE [0x00a71600]
extern const char g_str_eMouseOver_00a71600[];
// src: EXE [0x00a7160c]
extern const char g_str_eMouseDown_00a7160c[];
// src: EXE [0x00a71618]
extern const char g_str_eDisabled_00a71618[];
// src: EXE [0x00a71624]
extern const char g_str_Mouse_00a71624[];
// src: EXE [0x00a7162c]
extern const char g_str_eLClick_00a7162c[];
// src: EXE [0x00a71634]
extern const char g_str_eLDblClick_00a71634[];
// src: EXE [0x00a71640]
extern const char g_str_eRClick_00a71640[];
// src: EXE [0x00a71648]
extern const char g_str_eMClick_00a71648[];
// src: EXE [0x00a71650]
extern const char g_str_eWheel_00a71650[];
// src: EXE [0x00a71658]
extern const char g_str_eMouseEnter_00a71658[];
// src: EXE [0x00a71664]
extern const char g_str_eMouseExit_00a71664[];
// src: EXE [0x00a71670]
extern const char g_str_KeyEvents_00a71670[];
// src: EXE [0x00a7167c]
extern const char g_str_WM_KEYDOWN_00a7167c[];
// src: EXE [0x00a71688]
extern const char g_str_KeyDown_00a71688[];
// src: EXE [0x00a71690]
extern const char g_str_WM_KEYUP_00a71690[];
// src: EXE [0x00a7169c]
extern const char g_str_KeyUp_00a7169c[];
// src: EXE [0x00a716a4]
extern const char g_str_MouseEvents_00a716a4[];
// src: EXE [0x00a716b0]
extern const char g_str_MouseFirst_00a716b0[];
// src: EXE [0x00a716bc]
extern const char g_str_MouseWheel_00a716bc[];
// src: EXE [0x00a716c8]
extern const char g_str_MouseMove_00a716c8[];
// src: EXE [0x00a716d4]
extern const char g_str_LButtonDown_00a716d4[];
// src: EXE [0x00a716e0]
extern const char g_str_LButtonUp_00a716e0[];
// src: EXE [0x00a716ec]
extern const char g_str_LButtonDoubleClick_00a716ec[];
// src: EXE [0x00a71700]
extern const char g_str_RButtonDown_00a71700[];
// src: EXE [0x00a7170c]
extern const char g_str_RButtonUp_00a7170c[];
// src: EXE [0x00a71718]
extern const char g_str_RButtonDoubleClick_00a71718[];
// src: EXE [0x00a7172c]
extern const char g_str_MButtonDown_00a7172c[];
// src: EXE [0x00a71738]
extern const char g_str_MButtonUp_00a71738[];
// src: EXE [0x00a71744]
extern const char g_str_MButtonDoubleClick_00a71744[];
// src: EXE [0x00a71758]
extern const char g_str_MouseWheel_00a71758[];
// src: EXE [0x00a71764]
extern const char g_str_XButtonDown_00a71764[];
// src: EXE [0x00a71770]
extern const char g_str_XButtonUp_00a71770[];
// src: EXE [0x00a7177c]
extern const char g_str_XButtonDoubleClick_00a7177c[];
// src: EXE [0x00a71790]
extern const char g_str_MouseLast_00a71790[];
// src: EXE [0x00a7179c]
extern const char g_str_PointerUp_00a7179c[];
// src: EXE [0x00a717a8]
extern const char g_str_PointerDown_00a717a8[];
// src: EXE [0x00a717b4]
extern const char g_str_PointerUpdate_00a717b4[];
// src: EXE [0x00a717c4]
extern const char g_str_PopupPriorities_00a717c4[];
// src: EXE [0x00a717d4]
extern const char g_str_ADVISOR_INFO_00a717d4[];
// src: EXE [0x00a717e4]
extern const char g_str_ADVISOR_INFO_00a717e4[];
// src: EXE [0x00a717f4]
extern const char g_str_ADVISOR_INFO_00a717f4[];
// src: EXE [0x00a71804]
extern const char g_str_ADVISOR_INFO_00a71804[];
// src: EXE [0x00a71814]
extern const char g_str_InfoCornerID_00a71814[];
// src: EXE [0x00a71824]
extern const char g_str_None_00a71824[];
// src: EXE [0x00a7182c]
extern const char g_str_Tech_00a7182c[];
// src: EXE [0x00a71834]
extern const char g_str_Units_00a71834[];
// src: EXE [0x00a7183c]
extern const char g_str_Cities_00a7183c[];
// src: EXE [0x00a71844]
extern const char g_str_Diplo_00a71844[];
// src: EXE [0x00a7184c]
extern const char g_str_Keys_00a7184c[];
// src: EXE [0x00a71854]
extern const char g_str_A_00a71854[];
// src: EXE [0x00a71858]
extern const char g_str_B_00a71858[];
// src: EXE [0x00a7185c]
extern const char g_str_C_00a7185c[];
// src: EXE [0x00a71860]
extern const char g_str_D_00a71860[];
// src: EXE [0x00a71864]
extern const char g_str_E_00a71864[];
// src: EXE [0x00a71868]
extern const char g_str_F_00a71868[];
// src: EXE [0x00a7186c]
extern const char g_str_G_00a7186c[];
// src: EXE [0x00a71870]
extern const char g_str_H_00a71870[];
// src: EXE [0x00a71874]
extern const char g_str_I_00a71874[];
// src: EXE [0x00a71878]
extern const char g_str_J_00a71878[];
// src: EXE [0x00a7187c]
extern const char g_str_K_00a7187c[];
// src: EXE [0x00a71880]
extern const char g_str_L_00a71880[];
// src: EXE [0x00a71884]
extern const char g_str_M_00a71884[];
// src: EXE [0x00a71888]
extern const char g_str_N_00a71888[];
// src: EXE [0x00a7188c]
extern const char g_str_O_00a7188c[];
// src: EXE [0x00a71890]
extern const char g_str_P_00a71890[];
// src: EXE [0x00a71894]
extern const char g_str_Q_00a71894[];
// src: EXE [0x00a71898]
extern const char g_str_R_00a71898[];
// src: EXE [0x00a7189c]
extern const char g_str_S_00a7189c[];
// src: EXE [0x00a718a0]
extern const char g_str_T_00a718a0[];
// src: EXE [0x00a718a4]
extern const char g_str_U_00a718a4[];
// src: EXE [0x00a718a8]
extern const char g_str_V_00a718a8[];
// src: EXE [0x00a718ac]
extern const char g_str_W_00a718ac[];
// src: EXE [0x00a718b0]
extern const char g_str_X_00a718b0[];
// src: EXE [0x00a718b4]
extern const char g_str_Y_00a718b4[];
// src: EXE [0x00a718b8]
extern const char g_str_Z_00a718b8[];
// src: EXE [0x00a718bc]
extern const char g_str_1_00a718bc[];
// src: EXE [0x00a718c0]
extern const char g_str_2_00a718c0[];
// src: EXE [0x00a718c4]
extern const char g_str_3_00a718c4[];
// src: EXE [0x00a718c8]
extern const char g_str_4_00a718c8[];
// src: EXE [0x00a718cc]
extern const char g_str_5_00a718cc[];
// src: EXE [0x00a718d0]
extern const char g_str_6_00a718d0[];
// src: EXE [0x00a718d4]
extern const char g_str_7_00a718d4[];
// src: EXE [0x00a718d8]
extern const char g_str_8_00a718d8[];
// src: EXE [0x00a718dc]
extern const char g_str_9_00a718dc[];
// src: EXE [0x00a718e0]
extern const char g_str_0_00a718e0[];
// src: EXE [0x00a718e4]
extern const char g_str_VK_SPACE_00a718e4[];
// src: EXE [0x00a718f0]
extern const char g_str_VK_BACK_00a718f0[];
// src: EXE [0x00a718f8]
extern const char g_str_VK_TAB_00a718f8[];
// src: EXE [0x00a71900]
extern const char g_str_VK_CLEAR_00a71900[];
// src: EXE [0x00a7190c]
extern const char g_str_VK_RETURN_00a7190c[];
// src: EXE [0x00a71918]
extern const char g_str_VK_SHIFT_00a71918[];
// src: EXE [0x00a71924]
extern const char g_str_VK_CONTROL_00a71924[];
// src: EXE [0x00a71930]
extern const char g_str_VK_MENU_00a71930[];
// src: EXE [0x00a71938]
extern const char g_str_VK_PAUSE_00a71938[];
// src: EXE [0x00a71944]
extern const char g_str_VK_CAPITAL_00a71944[];
// src: EXE [0x00a71950]
extern const char g_str_VK_KANA_00a71950[];
// src: EXE [0x00a71958]
extern const char g_str_VK_HANGEUL_00a71958[];
// src: EXE [0x00a71964]
extern const char g_str_VK_HANGUL_00a71964[];
// src: EXE [0x00a71970]
extern const char g_str_VK_JUNJA_00a71970[];
// src: EXE [0x00a7197c]
extern const char g_str_VK_FINAL_00a7197c[];
// src: EXE [0x00a71988]
extern const char g_str_VK_HANJA_00a71988[];
// src: EXE [0x00a71994]
extern const char g_str_VK_KANJI_00a71994[];
// src: EXE [0x00a719a0]
extern const char g_str_VK_ESCAPE_00a719a0[];
// src: EXE [0x00a719ac]
extern const char g_str_VK_CONVERT_00a719ac[];
// src: EXE [0x00a719b8]
extern const char g_str_VK_NONCONVERT_00a719b8[];
// src: EXE [0x00a719c8]
extern const char g_str_VK_ACCEPT_00a719c8[];
// src: EXE [0x00a719d4]
extern const char g_str_VK_MODECHANGE_00a719d4[];
// src: EXE [0x00a719e4]
extern const char g_str_VK_SPACE_00a719e4[];
// src: EXE [0x00a719f0]
extern const char g_str_VK_PRIOR_00a719f0[];
// src: EXE [0x00a719fc]
extern const char g_str_VK_NEXT_00a719fc[];
// src: EXE [0x00a71a04]
extern const char g_str_VK_END_00a71a04[];
// src: EXE [0x00a71a0c]
extern const char g_str_VK_HOME_00a71a0c[];
// src: EXE [0x00a71a14]
extern const char g_str_VK_LEFT_00a71a14[];
// src: EXE [0x00a71a1c]
extern const char g_str_VK_UP_00a71a1c[];
// src: EXE [0x00a71a24]
extern const char g_str_VK_RIGHT_00a71a24[];
// src: EXE [0x00a71a30]
extern const char g_str_VK_DOWN_00a71a30[];
// src: EXE [0x00a71a38]
extern const char g_str_VK_SELECT_00a71a38[];
// src: EXE [0x00a71a44]
extern const char g_str_VK_PRINT_00a71a44[];
// src: EXE [0x00a71a50]
extern const char g_str_VK_EXECUTE_00a71a50[];
// src: EXE [0x00a71a5c]
extern const char g_str_VK_SNAPSHOT_00a71a5c[];
// src: EXE [0x00a71a68]
extern const char g_str_VK_INSERT_00a71a68[];
// src: EXE [0x00a71a74]
extern const char g_str_VK_DELETE_00a71a74[];
// src: EXE [0x00a71a80]
extern const char g_str_VK_HELP_00a71a80[];
// src: EXE [0x00a71a88]
extern const char g_str_VK_LWIN_00a71a88[];
// src: EXE [0x00a71a90]
extern const char g_str_VK_RWIN_00a71a90[];
// src: EXE [0x00a71a98]
extern const char g_str_VK_APPS_00a71a98[];
// src: EXE [0x00a71aa0]
extern const char g_str_VK_SLEEP_00a71aa0[];
// src: EXE [0x00a71aac]
extern const char g_str_VK_NUMPAD0_00a71aac[];
// src: EXE [0x00a71ab8]
extern const char g_str_VK_NUMPAD1_00a71ab8[];
// src: EXE [0x00a71ac4]
extern const char g_str_VK_NUMPAD2_00a71ac4[];
// src: EXE [0x00a71ad0]
extern const char g_str_VK_NUMPAD3_00a71ad0[];
// src: EXE [0x00a71adc]
extern const char g_str_VK_NUMPAD4_00a71adc[];
// src: EXE [0x00a71ae8]
extern const char g_str_VK_NUMPAD5_00a71ae8[];
// src: EXE [0x00a71af4]
extern const char g_str_VK_NUMPAD6_00a71af4[];
// src: EXE [0x00a71b00]
extern const char g_str_VK_NUMPAD7_00a71b00[];
// src: EXE [0x00a71b0c]
extern const char g_str_VK_NUMPAD8_00a71b0c[];
// src: EXE [0x00a71b18]
extern const char g_str_VK_NUMPAD9_00a71b18[];
// src: EXE [0x00a71b24]
extern const char g_str_VK_MULTIPLY_00a71b24[];
// src: EXE [0x00a71b30]
extern const char g_str_VK_ADD_00a71b30[];
// src: EXE [0x00a71b38]
extern const char g_str_VK_SEPARATOR_00a71b38[];
// src: EXE [0x00a71b48]
extern const char g_str_VK_SUBTRACT_00a71b48[];
// src: EXE [0x00a71b54]
extern const char g_str_VK_DECIMAL_00a71b54[];
// src: EXE [0x00a71b60]
extern const char g_str_VK_DIVIDE_00a71b60[];
// src: EXE [0x00a71b6c]
extern const char g_str_VK_F1_00a71b6c[];
// src: EXE [0x00a71b74]
extern const char g_str_VK_F2_00a71b74[];
// src: EXE [0x00a71b7c]
extern const char g_str_VK_F3_00a71b7c[];
// src: EXE [0x00a71b84]
extern const char g_str_VK_F4_00a71b84[];
// src: EXE [0x00a71b8c]
extern const char g_str_VK_F5_00a71b8c[];
// src: EXE [0x00a71b94]
extern const char g_str_VK_F6_00a71b94[];
// src: EXE [0x00a71b9c]
extern const char g_str_VK_F7_00a71b9c[];
// src: EXE [0x00a71ba4]
extern const char g_str_VK_F8_00a71ba4[];
// src: EXE [0x00a71bac]
extern const char g_str_VK_F9_00a71bac[];
// src: EXE [0x00a71bb4]
extern const char g_str_VK_F10_00a71bb4[];
// src: EXE [0x00a71bbc]
extern const char g_str_VK_F11_00a71bbc[];
// src: EXE [0x00a71bc4]
extern const char g_str_VK_F12_00a71bc4[];
// src: EXE [0x00a71bcc]
extern const char g_str_VK_F13_00a71bcc[];
// src: EXE [0x00a71bd4]
extern const char g_str_VK_F14_00a71bd4[];
// src: EXE [0x00a71bdc]
extern const char g_str_VK_F15_00a71bdc[];
// src: EXE [0x00a71be4]
extern const char g_str_VK_F16_00a71be4[];
// src: EXE [0x00a71bec]
extern const char g_str_VK_F17_00a71bec[];
// src: EXE [0x00a71bf4]
extern const char g_str_VK_F18_00a71bf4[];
// src: EXE [0x00a71bfc]
extern const char g_str_VK_F19_00a71bfc[];
// src: EXE [0x00a71c04]
extern const char g_str_VK_F20_00a71c04[];
// src: EXE [0x00a71c0c]
extern const char g_str_VK_F21_00a71c0c[];
// src: EXE [0x00a71c14]
extern const char g_str_VK_F22_00a71c14[];
// src: EXE [0x00a71c1c]
extern const char g_str_VK_F23_00a71c1c[];
// src: EXE [0x00a71c24]
extern const char g_str_VK_F24_00a71c24[];
// src: EXE [0x00a71c2c]
extern const char g_str_VK_NUMLOCK_00a71c2c[];
// src: EXE [0x00a71c38]
extern const char g_str_VK_SCROLL_00a71c38[];
// src: EXE [0x00a71c44]
extern const char g_str_VK_OEM_NEC_EQUAL_00a71c44[];
// src: EXE [0x00a71c58]
extern const char g_str_VK_OEM_FJ_JISHO_00a71c58[];
// src: EXE [0x00a71c68]
extern const char g_str_VK_OEM_FJ_MASSHOU_00a71c68[];
// src: EXE [0x00a71c7c]
extern const char g_str_VK_OEM_FJ_TOUROKU_00a71c7c[];
// src: EXE [0x00a71c90]
extern const char g_str_VK_OEM_FJ_LOYA_00a71c90[];
// src: EXE [0x00a71ca0]
extern const char g_str_VK_OEM_FJ_ROYA_00a71ca0[];
// src: EXE [0x00a71cb0]
extern const char g_str_VK_LSHIFT_00a71cb0[];
// src: EXE [0x00a71cbc]
extern const char g_str_VK_RSHIFT_00a71cbc[];
// src: EXE [0x00a71cc8]
extern const char g_str_VK_LCONTROL_00a71cc8[];
// src: EXE [0x00a71cd4]
extern const char g_str_VK_RCONTROL_00a71cd4[];
// src: EXE [0x00a71ce0]
extern const char g_str_VK_LMENU_00a71ce0[];
// src: EXE [0x00a71cec]
extern const char g_str_VK_RMENU_00a71cec[];
// src: EXE [0x00a71cf8]
extern const char g_str_VK_BROWSER_BACK_00a71cf8[];
// src: EXE [0x00a71d08]
extern const char g_str_VK_BROWSER_FORWARD_00a71d08[];
// src: EXE [0x00a71d1c]
extern const char g_str_VK_BROWSER_REFRESH_00a71d1c[];
// src: EXE [0x00a71d30]
extern const char g_str_VK_BROWSER_STOP_00a71d30[];
// src: EXE [0x00a71d40]
extern const char g_str_VK_BROWSER_SEARCH_00a71d40[];
// src: EXE [0x00a71d54]
extern const char g_str_VK_BROWSER_FAVORITES_00a71d54[];
// src: EXE [0x00a71d6c]
extern const char g_str_VK_BROWSER_HOME_00a71d6c[];
// src: EXE [0x00a71d7c]
extern const char g_str_VK_VOLUME_MUTE_00a71d7c[];
// src: EXE [0x00a71d8c]
extern const char g_str_VK_VOLUME_DOWN_00a71d8c[];
// src: EXE [0x00a71d9c]
extern const char g_str_VK_VOLUME_UP_00a71d9c[];
// src: EXE [0x00a71dac]
extern const char g_str_VK_MEDIA_NEXT_TRACK_00a71dac[];
// src: EXE [0x00a71dc0]
extern const char g_str_VK_MEDIA_PREV_TRACK_00a71dc0[];
// src: EXE [0x00a71dd4]
extern const char g_str_VK_MEDIA_STOP_00a71dd4[];
// src: EXE [0x00a71de4]
extern const char g_str_VK_MEDIA_PLAY_PAUSE_00a71de4[];
// src: EXE [0x00a71df8]
extern const char g_str_VK_LAUNCH_MAIL_00a71df8[];
// src: EXE [0x00a71e08]
extern const char g_str_VK_LAUNCH_MEDIA_SELECT_00a71e08[];
// src: EXE [0x00a71e20]
extern const char g_str_VK_LAUNCH_APP1_00a71e20[];
// src: EXE [0x00a71e30]
extern const char g_str_VK_LAUNCH_APP2_00a71e30[];
// src: EXE [0x00a71e40]
extern const char g_str_VK_OEM_1_00a71e40[];
// src: EXE [0x00a71e4c]
extern const char g_str_VK_OEM_PLUS_00a71e4c[];
// src: EXE [0x00a71e58]
extern const char g_str_VK_OEM_COMMA_00a71e58[];
// src: EXE [0x00a71e68]
extern const char g_str_VK_OEM_MINUS_00a71e68[];
// src: EXE [0x00a71e78]
extern const char g_str_VK_OEM_PERIOD_00a71e78[];
// src: EXE [0x00a71e88]
extern const char g_str_VK_OEM_2_00a71e88[];
// src: EXE [0x00a71e94]
extern const char g_str_VK_OEM_3_00a71e94[];
// src: EXE [0x00a71ea0]
extern const char g_str_VK_OEM_4_00a71ea0[];
// src: EXE [0x00a71eac]
extern const char g_str_VK_OEM_5_00a71eac[];
// src: EXE [0x00a71eb8]
extern const char g_str_VK_OEM_6_00a71eb8[];
// src: EXE [0x00a71ec4]
extern const char g_str_VK_OEM_7_00a71ec4[];
// src: EXE [0x00a71ed0]
extern const char g_str_VK_OEM_8_00a71ed0[];
// src: EXE [0x00a71edc]
extern const char g_str_VK_OEM_AX_00a71edc[];
// src: EXE [0x00a71ee8]
extern const char g_str_VK_OEM_102_00a71ee8[];
// src: EXE [0x00a71ef4]
extern const char g_str_VK_ICO_HELP_00a71ef4[];
// src: EXE [0x00a71f00]
extern const char g_str_VK_ICO_00_00a71f00[];
// src: EXE [0x00a71f0c]
extern const char g_str_VK_PROCESSKEY_00a71f0c[];
// src: EXE [0x00a71f1c]
extern const char g_str_VK_ICO_CLEAR_00a71f1c[];
// src: EXE [0x00a71f2c]
extern const char g_str_VK_PACKET_00a71f2c[];
// src: EXE [0x00a71f38]
extern const char g_str_VK_OEM_RESET_00a71f38[];
// src: EXE [0x00a71f48]
extern const char g_str_VK_OEM_JUMP_00a71f48[];
// src: EXE [0x00a71f54]
extern const char g_str_VK_OEM_PA1_00a71f54[];
// src: EXE [0x00a71f60]
extern const char g_str_VK_OEM_PA2_00a71f60[];
// src: EXE [0x00a71f6c]
extern const char g_str_VK_OEM_PA3_00a71f6c[];
// src: EXE [0x00a71f78]
extern const char g_str_VK_OEM_WSCTRL_00a71f78[];
// src: EXE [0x00a71f88]
extern const char g_str_VK_OEM_CUSEL_00a71f88[];
// src: EXE [0x00a71f98]
extern const char g_str_VK_OEM_ATTN_00a71f98[];
// src: EXE [0x00a71fa4]
extern const char g_str_VK_OEM_FINISH_00a71fa4[];
// src: EXE [0x00a71fb4]
extern const char g_str_VK_OEM_COPY_00a71fb4[];
// src: EXE [0x00a71fc0]
extern const char g_str_VK_OEM_AUTO_00a71fc0[];
// src: EXE [0x00a71fcc]
extern const char g_str_VK_OEM_ENLW_00a71fcc[];
// src: EXE [0x00a71fd8]
extern const char g_str_VK_OEM_BACKTAB_00a71fd8[];
// src: EXE [0x00a71fe8]
extern const char g_str_VK_ATTN_00a71fe8[];
// src: EXE [0x00a71ff0]
extern const char g_str_VK_CRSEL_00a71ff0[];
// src: EXE [0x00a71ffc]
extern const char g_str_VK_EXSEL_00a71ffc[];
// src: EXE [0x00a72008]
extern const char g_str_VK_EREOF_00a72008[];
// src: EXE [0x00a72014]
extern const char g_str_VK_PLAY_00a72014[];
// src: EXE [0x00a7201c]
extern const char g_str_VK_ZOOM_00a7201c[];
// src: EXE [0x00a72024]
extern const char g_str_VK_NONAME_00a72024[];
// src: EXE [0x00a72030]
extern const char g_str_VK_PA1_00a72030[];
// src: EXE [0x00a72038]
extern const char g_str_VK_OEM_CLEAR_00a72038[];
// src: EXE [0x00a72048]
extern const char g_str_GameStateTypes_00a72048[];
// src: EXE [0x00a72058]
extern const char g_str_CIV5_GS_UNKNOWN_00a72058[];
// src: EXE [0x00a72068]
extern const char g_str_CIV5_GS_EXIT_00a72068[];
// src: EXE [0x00a72078]
extern const char g_str_CIV5_GS_OPENING_MOVIE_00a72078[];
// src: EXE [0x00a72090]
extern const char g_str_CIV5_GS_LOAD_GAME_00a72090[];
// src: EXE [0x00a720a4]
extern const char g_str_CIV5_GS_MAIN_MENU_00a720a4[];
// src: EXE [0x00a720b8]
extern const char g_str_CIV5_GS_MULTIPLAYER_MENU_00a720b8[];
// src: EXE [0x00a720d4]
extern const char g_str_CIV5_GS_LANLOBBY_00a720d4[];
// src: EXE [0x00a720e8]
extern const char g_str_CIV5_GS_INETLOBBY_00a720e8[];
// src: EXE [0x00a720fc]
extern const char g_str_CIV5_GS_STAGING_00a720fc[];
// src: EXE [0x00a7210c]
extern const char g_str_CIV5_GS_SCENARIOSETUP_00a7210c[];
// src: EXE [0x00a72124]
extern const char g_str_CIV5_GS_MAINGAMEVIEW_00a72124[];
// src: EXE [0x00a7213c]
extern const char g_str_CIV5_GS_UI_VIEWER_00a7213c[];
// src: EXE [0x00a72150]
extern const char g_str_CIV5_GS_LEADER_HEAD_BENCHMARK_00a72150[];
// src: EXE [0x00a72170]
extern const char g_str_CIV5_GS_LEADER_HEAD_VIEW_00a72170[];
// src: EXE [0x00a7218c]
extern const char g_str_CIV5_GS_NEXUS_00a7218c[];
// src: EXE [0x00a7219c]
extern const char g_str_CIV5_GS_WORLD_BUILDER_LOAD_00a7219c[];
// src: EXE [0x00a721b8]
extern const char g_str_CIV5_GS_CREDITS_00a721b8[];
// src: EXE [0x00a721c8]
extern const char g_str_SlotStatus_00a721c8[];
// src: EXE [0x00a721d4]
extern const char g_str_SS_OPEN_00a721d4[];
// src: EXE [0x00a721dc]
extern const char g_str_SS_COMPUTER_00a721dc[];
// src: EXE [0x00a721e8]
extern const char g_str_SS_CLOSED_00a721e8[];
// src: EXE [0x00a721f4]
extern const char g_str_SS_TAKEN_00a721f4[];
// src: EXE [0x00a72200]
extern const char g_str_SS_OBSERVER_00a72200[];
// src: EXE [0x00a7220c]
extern const char g_str_SS_MAX_SLOT_STATUS_00a7220c[];
// src: EXE [0x00a72220]
extern const char g_str_SlotClaim_00a72220[];
// src: EXE [0x00a7222c]
extern const char g_str_SLOTCLAIM_UNASSIGNED_00a7222c[];
// src: EXE [0x00a72244]
extern const char g_str_SLOTCLAIM_RESERVED_00a72244[];
// src: EXE [0x00a72258]
extern const char g_str_SLOTCLAIM_ASSIGNED_00a72258[];
// src: EXE [0x00a7226c]
extern const char g_str_NUM_SLOTCLAIMS_00a7226c[];
// src: EXE [0x00a7227c]
extern const char g_str_GameTypes_00a7227c[];
// src: EXE [0x00a72288]
extern const char g_str_GAME_TYPE_NONE_00a72288[];
// src: EXE [0x00a72298]
extern const char g_str_GAME_SINGLE_PLAYER_00a72298[];
// src: EXE [0x00a722ac]
extern const char g_str_GAME_NETWORK_MULTIPLAYER_00a722ac[];
// src: EXE [0x00a722c8]
extern const char g_str_GAME_HOTSEAT_MULTIPLAYER_00a722c8[];
// src: EXE [0x00a722e4]
extern const char g_str_GAME_EMAIL_MULTIPLAYER_00a722e4[];
// src: EXE [0x00a722fc]
extern const char g_str_NetErrors_00a722fc[];
// src: EXE [0x00a72308]
extern const char g_str_NO_ERROR_00a72308[];
// src: EXE [0x00a72314]
extern const char g_str_MISSING_REQUIRED_DATA_00a72314[];
// src: EXE [0x00a7232c]
extern const char g_str_ROOM_FULL_00a7232c[];
// src: EXE [0x00a72338]
extern const char g_str_NetKicked_00a72338[];
// src: EXE [0x00a72344]
extern const char g_str_NONE_00a72344[];
// src: EXE [0x00a7234c]
extern const char g_str_NO_HOST_00a7234c[];
// src: EXE [0x00a72354]
extern const char g_str_BY_HOST_00a72354[];
// src: EXE [0x00a7235c]
extern const char g_str_TIMEOUT_00a7235c[];
// src: EXE [0x00a72364]
extern const char g_str_UNRECOGNIZED_00a72364[];
// src: EXE [0x00a72374]
extern const char g_str_UNAUTHORIZED_00a72374[];
// src: EXE [0x00a72384]
extern const char g_str_NO_ROOM_00a72384[];
// src: EXE [0x00a7238c]
extern const char g_str_GameTypes_00a7238c[];
// src: EXE [0x00a72398]
extern const char g_str_GAME_SINGLE_PLAYER_00a72398[];
// src: EXE [0x00a723ac]
extern const char g_str_GAME_NETWORK_MULTIPLAYER_00a723ac[];
// src: EXE [0x00a723c8]
extern const char g_str_GAME_HOTSEAT_MULTIPLAYER_00a723c8[];
// src: EXE [0x00a723e4]
extern const char g_str_GAME_EMAIL_MULTIPLAYER_00a723e4[];
// src: EXE [0x00a723fc]
extern const char g_str_GameViewTypes_00a723fc[];
// src: EXE [0x00a7240c]
extern const char g_str_GAMEVIEW_NONE_00a7240c[];
// src: EXE [0x00a7241c]
extern const char g_str_GAMEVIEW_STANDARD_00a7241c[];
// src: EXE [0x00a72430]
extern const char g_str_GAMEVIEW_STRATEGIC_00a72430[];
// src: EXE [0x00a72444]
extern const char g_str_MultiplayerLobbyMode_00a72444[];
// src: EXE [0x00a7245c]
extern const char g_str_LOBBYMODE_STANDARD_INTERNET_00a7245c[];
// src: EXE [0x00a72478]
extern const char g_str_LOBBYMODE_STANDARD_LAN_00a72478[];
// src: EXE [0x00a72490]
extern const char g_str_LOBBYMODE_PITBOSS_INTERNET_00a72490[];
// src: EXE [0x00a724ac]
extern const char g_str_LOBBYMODE_PITBOSS_LAN_00a724ac[];

void RegisterUIEnums_0064fd80(lua_State* L) {
    lua_getfield(L, -1, g_str_PopupPriority_00a7100c);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_PopupPriority_00a7100c);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_MainMenu_00a70f04);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_LegalScreen_00a7101c);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_SinglePlayerScreen_00a71028);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_MultiplayerSelectScreen_00a7103c);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_ModsEULAScreen_00a71054);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_OtherMenu_00a71064);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_Credits_00a71070);
    lua_pushinteger(L, 7);
    lua_setfield(L, -2, g_str_GameSetupScreen_00a71078);
    lua_pushinteger(L, 16);
    lua_setfield(L, -2, g_str_LoadGameScreen_00a71088);
    lua_pushinteger(L, 8);
    lua_setfield(L, -2, g_str_LoadTutorial_00a71098);
    lua_pushinteger(L, 10);
    lua_setfield(L, -2, g_str_ModsMenuScreen_00a710a8);
    lua_pushinteger(L, 11);
    lua_setfield(L, -2, g_str_ModdingScenarioSetupScreen_00a710b8);
    lua_pushinteger(L, 12);
    lua_setfield(L, -2, g_str_ModdingSinglePlayer_00a710d4);
    lua_pushinteger(L, 13);
    lua_setfield(L, -2, g_str_ModMultiplayerSelectScreen_00a710e8);
    lua_pushinteger(L, 9);
    lua_setfield(L, -2, g_str_ModsBrowserScreen_00a71104);
    lua_pushinteger(L, 14);
    lua_setfield(L, -2, g_str_ModdingGameSetupScreen_00a71118);
    lua_pushinteger(L, 15);
    lua_setfield(L, -2, g_str_ModsCustom_00a71130);
    lua_pushinteger(L, 16);
    lua_setfield(L, -2, g_str_LoadGameScreen_00a7113c);
    lua_pushinteger(L, 17);
    lua_setfield(L, -2, g_str_AdvancedSetup_00a7114c);
    lua_pushinteger(L, 18);
    lua_setfield(L, -2, g_str_SelectCivilization_00a7115c);
    lua_pushinteger(L, 61);
    lua_setfield(L, -2, g_str_Civilopedia_00a71170);
    lua_pushinteger(L, 28);
    lua_setfield(L, -2, g_str_GenericPopup_00a7117c);
    lua_pushinteger(L, 29);
    lua_setfield(L, -2, g_str_TextPopup_00a7118c);
    lua_pushinteger(L, 63);
    lua_setfield(L, -2, g_str_LeaderHead_00a71198);
    lua_pushinteger(L, 19);
    lua_setfield(L, -2, g_str_CustomMod_00a711a4);
    lua_pushinteger(L, 20);
    lua_setfield(L, -2, g_str_LobbyScreen_00a711b0);
    lua_pushinteger(L, 22);
    lua_setfield(L, -2, g_str_MPLoadGameScreen_00a711bc);
    lua_pushinteger(L, 21);
    lua_setfield(L, -2, g_str_MPGameSetupScreen_00a711d0);
    lua_pushinteger(L, 23);
    lua_setfield(L, -2, g_str_JoiningScreen_00a711e4);
    lua_pushinteger(L, 24);
    lua_setfield(L, -2, g_str_StagingScreen_00a711f4);
    lua_pushinteger(L, 30);
    lua_setfield(L, -2, g_str_AdvisorCounsel_00a71204);
    lua_pushinteger(L, 31);
    lua_setfield(L, -2, g_str_AdvisorInfo_00a71214);
    lua_pushinteger(L, 32);
    lua_setfield(L, -2, g_str_AdvisorModal_00a71220);
    lua_pushinteger(L, 33);
    lua_setfield(L, -2, g_str_BarbarianCamp_00a71230);
    lua_pushinteger(L, 27);
    lua_setfield(L, -2, g_str_CityStateDiplo_00a71240);
    lua_pushinteger(L, 34);
    lua_setfield(L, -2, g_str_CityStateGreeting_00a71250);
    lua_pushinteger(L, 35);
    lua_setfield(L, -2, g_str_GoldenAge_00a71264);
    lua_pushinteger(L, 36);
    lua_setfield(L, -2, g_str_GreatPersonReward_00a71270);
    lua_pushinteger(L, 37);
    lua_setfield(L, -2, g_str_CityStateList_00a71284);
    lua_pushinteger(L, 38);
    lua_setfield(L, -2, g_str_NaturalWonderPopup_00a71294);
    lua_pushinteger(L, 53);
    lua_setfield(L, -2, g_str_VoteResults_00a712a8);
    lua_pushinteger(L, 39);
    lua_setfield(L, -2, g_str_NotificationLog_00a712b4);
    lua_pushinteger(L, 40);
    lua_setfield(L, -2, g_str_NewEraPopup_00a712c4);
    lua_pushinteger(L, 41);
    lua_setfield(L, -2, g_str_TechAward_00a712d0);
    lua_pushinteger(L, 42);
    lua_setfield(L, -2, g_str_WhosWinning_00a712dc);
    lua_pushinteger(L, 43);
    lua_setfield(L, -2, g_str_GoodyHut_00a712e8);
    lua_pushinteger(L, 44);
    lua_setfield(L, -2, g_str_WonderPopup_00a712f4);
    lua_pushinteger(L, 26);
    lua_setfield(L, -2, g_str_DiploOverview_00a71300);
    lua_pushinteger(L, 45);
    lua_setfield(L, -2, g_str_MilitaryOverview_00a71310);
    lua_pushinteger(L, 46);
    lua_setfield(L, -2, g_str_EconOverview_00a71324);
    lua_pushinteger(L, 47);
    lua_setfield(L, -2, g_str_ProductionPopup_00a71334);
    lua_pushinteger(L, 25);
    lua_setfield(L, -2, g_str_SocialPolicy_00a71344);
    lua_pushinteger(L, 48);
    lua_setfield(L, -2, g_str_DiploVote_00a71354);
    lua_pushinteger(L, 49);
    lua_setfield(L, -2, g_str_TechTree_00a71360);
    lua_pushinteger(L, 50);
    lua_setfield(L, -2, g_str_EndGameMenu_00a7136c);
    lua_pushinteger(L, 51);
    lua_setfield(L, -2, g_str_VictoryProgress_00a71378);
    lua_pushinteger(L, 52);
    lua_setfield(L, -2, g_str_Demographics_00a71388);
    lua_pushinteger(L, 54);
    lua_setfield(L, -2, g_str_InGameMenu_00a71398);
    lua_pushinteger(L, 55);
    lua_setfield(L, -2, g_str_OptionsMenu_00a713a4);
    lua_pushinteger(L, 56);
    lua_setfield(L, -2, g_str_SaveMenu_00a713b0);
    lua_pushinteger(L, 57);
    lua_setfield(L, -2, g_str_LoadMenu_00a713bc);
    lua_pushinteger(L, 58);
    lua_setfield(L, -2, g_str_SaveMapMenu_00a713c8);
    lua_pushinteger(L, 59);
    lua_setfield(L, -2, g_str_HallOfFame_00a713d4);
    lua_pushinteger(L, 60);
    lua_setfield(L, -2, g_str_Leaderboard_00a713e0);
    lua_pushinteger(L, 64);
    lua_setfield(L, -2, g_str_LeaderDiscuss_00a713ec);
    lua_pushinteger(L, 65);
    lua_setfield(L, -2, g_str_LeaderTrade_00a713fc);
    lua_pushinteger(L, 66);
    lua_setfield(L, -2, g_str_LeaderHeadPopup_00a71408);
    lua_pushinteger(L, 67);
    lua_setfield(L, -2, g_str_PlayerChange_00a71418);
    lua_pushinteger(L, 62);
    lua_setfield(L, -2, g_str_InGameUtmost_00a71428);
    lua_pushinteger(L, 68);
    lua_setfield(L, -2, g_str_eUtmost_00a71438);
    lua_pushinteger(L, 9999);
    lua_setfield(L, -2, g_str_Current_00a71440);
    lua_pushinteger(L, 10000);
    lua_setfield(L, -2, g_str_Default_00a71448);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_EndGameTypes_00a71450);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_EndGameTypes_00a71450);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_Technology_00a71460);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_Culture_00a7146c);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_Domination_00a71474);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_Diplomatic_00a71480);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_Time_00a7148c);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_Tutorial1_00a71494);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_Tutorial2_00a714a0);
    lua_pushinteger(L, 7);
    lua_setfield(L, -2, g_str_Tutorial3_00a714ac);
    lua_pushinteger(L, 8);
    lua_setfield(L, -2, g_str_Tutorial4_00a714b8);
    lua_pushinteger(L, 9);
    lua_setfield(L, -2, g_str_Tutorial5_00a714c4);
    lua_pushinteger(L, 10);
    lua_setfield(L, -2, g_str_Loss_00a714d0);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_SystemUpdateUIType_00a714d8);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_SystemUpdateUIType_00a714d8);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_ScreenResize_00a714ec);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_ReloadUI_00a714fc);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_ReprocessAnchoring_00a71508);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_BulkHideUI_00a7151c);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_BulkShowUI_00a71528);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_UnloadUI_00a71534);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_RestoreUI_00a71540);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_YieldDisplayTypes_00a7154c);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_YieldDisplayTypes_00a7154c);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_USER_ALL_ON_00a71560);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_USER_ALL_OFF_00a7156c);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_USER_ALL_RESOURCE_ON_00a7157c);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_USER_ALL_RESOURCE_OFF_00a71594);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_EMPIRE_00a715ac);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_CITY_OWNED_00a715b4);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_CITY_WORKED_00a715c0);
    lua_pushinteger(L, 7);
    lua_setfield(L, -2, g_str_CITY_PURCHASABLE_00a715cc);
    lua_pushinteger(L, 8);
    lua_setfield(L, -2, g_str_AREA_00a715e0);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_ButtonStates_00a715e8);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_ButtonStates_00a715e8);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_eNormal_00a715f8);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_eMouseOver_00a71600);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_eMouseDown_00a7160c);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_eDisabled_00a71618);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_Mouse_00a71624);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_Mouse_00a71624);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_eLClick_00a7162c);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_eLDblClick_00a71634);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_eRClick_00a71640);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_eMClick_00a71648);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_eWheel_00a71650);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_eMouseEnter_00a71658);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_eMouseExit_00a71664);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_KeyEvents_00a71670);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_KeyEvents_00a71670);
    }
    lua_pushinteger(L, 256);
    lua_setfield(L, -2, g_str_WM_KEYDOWN_00a7167c);
    lua_pushinteger(L, 256);
    lua_setfield(L, -2, g_str_KeyDown_00a71688);
    lua_pushinteger(L, 257);
    lua_setfield(L, -2, g_str_WM_KEYUP_00a71690);
    lua_pushinteger(L, 257);
    lua_setfield(L, -2, g_str_KeyUp_00a7169c);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_MouseEvents_00a716a4);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_MouseEvents_00a716a4);
    }
    lua_pushinteger(L, 512);
    lua_setfield(L, -2, g_str_MouseFirst_00a716b0);
    lua_pushinteger(L, 522);
    lua_setfield(L, -2, g_str_MouseWheel_00a716bc);
    lua_pushinteger(L, 512);
    lua_setfield(L, -2, g_str_MouseMove_00a716c8);
    lua_pushinteger(L, 513);
    lua_setfield(L, -2, g_str_LButtonDown_00a716d4);
    lua_pushinteger(L, 514);
    lua_setfield(L, -2, g_str_LButtonUp_00a716e0);
    lua_pushinteger(L, 515);
    lua_setfield(L, -2, g_str_LButtonDoubleClick_00a716ec);
    lua_pushinteger(L, 516);
    lua_setfield(L, -2, g_str_RButtonDown_00a71700);
    lua_pushinteger(L, 517);
    lua_setfield(L, -2, g_str_RButtonUp_00a7170c);
    lua_pushinteger(L, 518);
    lua_setfield(L, -2, g_str_RButtonDoubleClick_00a71718);
    lua_pushinteger(L, 519);
    lua_setfield(L, -2, g_str_MButtonDown_00a7172c);
    lua_pushinteger(L, 520);
    lua_setfield(L, -2, g_str_MButtonUp_00a71738);
    lua_pushinteger(L, 521);
    lua_setfield(L, -2, g_str_MButtonDoubleClick_00a71744);
    lua_pushinteger(L, 522);
    lua_setfield(L, -2, g_str_MouseWheel_00a71758);
    lua_pushinteger(L, 523);
    lua_setfield(L, -2, g_str_XButtonDown_00a71764);
    lua_pushinteger(L, 524);
    lua_setfield(L, -2, g_str_XButtonUp_00a71770);
    lua_pushinteger(L, 525);
    lua_setfield(L, -2, g_str_XButtonDoubleClick_00a7177c);
    lua_pushinteger(L, 526);
    lua_setfield(L, -2, g_str_MouseLast_00a71790);
    lua_pushinteger(L, 583);
    lua_setfield(L, -2, g_str_PointerUp_00a7179c);
    lua_pushinteger(L, 582);
    lua_setfield(L, -2, g_str_PointerDown_00a717a8);
    lua_pushinteger(L, 581);
    lua_setfield(L, -2, g_str_PointerUpdate_00a717b4);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_PopupPriorities_00a717c4);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_PopupPriorities_00a717c4);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_ADVISOR_INFO_00a717d4);
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_ADVISOR_INFO_00a717e4);
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_ADVISOR_INFO_00a717f4);
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_ADVISOR_INFO_00a71804);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_InfoCornerID_00a71814);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_InfoCornerID_00a71814);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_None_00a71824);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_Tech_00a7182c);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_Units_00a71834);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_Cities_00a7183c);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_Diplo_00a71844);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_Keys_00a7184c);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_Keys_00a7184c);
    }
    lua_pushinteger(L, 65);
    lua_setfield(L, -2, g_str_A_00a71854);
    lua_pushinteger(L, 66);
    lua_setfield(L, -2, g_str_B_00a71858);
    lua_pushinteger(L, 67);
    lua_setfield(L, -2, g_str_C_00a7185c);
    lua_pushinteger(L, 68);
    lua_setfield(L, -2, g_str_D_00a71860);
    lua_pushinteger(L, 69);
    lua_setfield(L, -2, g_str_E_00a71864);
    lua_pushinteger(L, 70);
    lua_setfield(L, -2, g_str_F_00a71868);
    lua_pushinteger(L, 71);
    lua_setfield(L, -2, g_str_G_00a7186c);
    lua_pushinteger(L, 72);
    lua_setfield(L, -2, g_str_H_00a71870);
    lua_pushinteger(L, 73);
    lua_setfield(L, -2, g_str_I_00a71874);
    lua_pushinteger(L, 74);
    lua_setfield(L, -2, g_str_J_00a71878);
    lua_pushinteger(L, 75);
    lua_setfield(L, -2, g_str_K_00a7187c);
    lua_pushinteger(L, 76);
    lua_setfield(L, -2, g_str_L_00a71880);
    lua_pushinteger(L, 77);
    lua_setfield(L, -2, g_str_M_00a71884);
    lua_pushinteger(L, 78);
    lua_setfield(L, -2, g_str_N_00a71888);
    lua_pushinteger(L, 79);
    lua_setfield(L, -2, g_str_O_00a7188c);
    lua_pushinteger(L, 80);
    lua_setfield(L, -2, g_str_P_00a71890);
    lua_pushinteger(L, 81);
    lua_setfield(L, -2, g_str_Q_00a71894);
    lua_pushinteger(L, 82);
    lua_setfield(L, -2, g_str_R_00a71898);
    lua_pushinteger(L, 83);
    lua_setfield(L, -2, g_str_S_00a7189c);
    lua_pushinteger(L, 84);
    lua_setfield(L, -2, g_str_T_00a718a0);
    lua_pushinteger(L, 85);
    lua_setfield(L, -2, g_str_U_00a718a4);
    lua_pushinteger(L, 86);
    lua_setfield(L, -2, g_str_V_00a718a8);
    lua_pushinteger(L, 87);
    lua_setfield(L, -2, g_str_W_00a718ac);
    lua_pushinteger(L, 88);
    lua_setfield(L, -2, g_str_X_00a718b0);
    lua_pushinteger(L, 89);
    lua_setfield(L, -2, g_str_Y_00a718b4);
    lua_pushinteger(L, 90);
    lua_setfield(L, -2, g_str_Z_00a718b8);
    lua_pushinteger(L, 49);
    lua_setfield(L, -2, g_str_1_00a718bc);
    lua_pushinteger(L, 50);
    lua_setfield(L, -2, g_str_2_00a718c0);
    lua_pushinteger(L, 51);
    lua_setfield(L, -2, g_str_3_00a718c4);
    lua_pushinteger(L, 52);
    lua_setfield(L, -2, g_str_4_00a718c8);
    lua_pushinteger(L, 53);
    lua_setfield(L, -2, g_str_5_00a718cc);
    lua_pushinteger(L, 54);
    lua_setfield(L, -2, g_str_6_00a718d0);
    lua_pushinteger(L, 55);
    lua_setfield(L, -2, g_str_7_00a718d4);
    lua_pushinteger(L, 56);
    lua_setfield(L, -2, g_str_8_00a718d8);
    lua_pushinteger(L, 57);
    lua_setfield(L, -2, g_str_9_00a718dc);
    lua_pushinteger(L, 48);
    lua_setfield(L, -2, g_str_0_00a718e0);
    lua_pushinteger(L, 32);
    lua_setfield(L, -2, g_str_VK_SPACE_00a718e4);
    lua_pushinteger(L, 8);
    lua_setfield(L, -2, g_str_VK_BACK_00a718f0);
    lua_pushinteger(L, 9);
    lua_setfield(L, -2, g_str_VK_TAB_00a718f8);
    lua_pushinteger(L, 12);
    lua_setfield(L, -2, g_str_VK_CLEAR_00a71900);
    lua_pushinteger(L, 13);
    lua_setfield(L, -2, g_str_VK_RETURN_00a7190c);
    lua_pushinteger(L, 16);
    lua_setfield(L, -2, g_str_VK_SHIFT_00a71918);
    lua_pushinteger(L, 17);
    lua_setfield(L, -2, g_str_VK_CONTROL_00a71924);
    lua_pushinteger(L, 18);
    lua_setfield(L, -2, g_str_VK_MENU_00a71930);
    lua_pushinteger(L, 19);
    lua_setfield(L, -2, g_str_VK_PAUSE_00a71938);
    lua_pushinteger(L, 20);
    lua_setfield(L, -2, g_str_VK_CAPITAL_00a71944);
    lua_pushinteger(L, 21);
    lua_setfield(L, -2, g_str_VK_KANA_00a71950);
    lua_pushinteger(L, 21);
    lua_setfield(L, -2, g_str_VK_HANGEUL_00a71958);
    lua_pushinteger(L, 21);
    lua_setfield(L, -2, g_str_VK_HANGUL_00a71964);
    lua_pushinteger(L, 23);
    lua_setfield(L, -2, g_str_VK_JUNJA_00a71970);
    lua_pushinteger(L, 24);
    lua_setfield(L, -2, g_str_VK_FINAL_00a7197c);
    lua_pushinteger(L, 25);
    lua_setfield(L, -2, g_str_VK_HANJA_00a71988);
    lua_pushinteger(L, 25);
    lua_setfield(L, -2, g_str_VK_KANJI_00a71994);
    lua_pushinteger(L, 27);
    lua_setfield(L, -2, g_str_VK_ESCAPE_00a719a0);
    lua_pushinteger(L, 28);
    lua_setfield(L, -2, g_str_VK_CONVERT_00a719ac);
    lua_pushinteger(L, 29);
    lua_setfield(L, -2, g_str_VK_NONCONVERT_00a719b8);
    lua_pushinteger(L, 30);
    lua_setfield(L, -2, g_str_VK_ACCEPT_00a719c8);
    lua_pushinteger(L, 31);
    lua_setfield(L, -2, g_str_VK_MODECHANGE_00a719d4);
    lua_pushinteger(L, 32);
    lua_setfield(L, -2, g_str_VK_SPACE_00a719e4);
    lua_pushinteger(L, 33);
    lua_setfield(L, -2, g_str_VK_PRIOR_00a719f0);
    lua_pushinteger(L, 34);
    lua_setfield(L, -2, g_str_VK_NEXT_00a719fc);
    lua_pushinteger(L, 35);
    lua_setfield(L, -2, g_str_VK_END_00a71a04);
    lua_pushinteger(L, 36);
    lua_setfield(L, -2, g_str_VK_HOME_00a71a0c);
    lua_pushinteger(L, 37);
    lua_setfield(L, -2, g_str_VK_LEFT_00a71a14);
    lua_pushinteger(L, 38);
    lua_setfield(L, -2, g_str_VK_UP_00a71a1c);
    lua_pushinteger(L, 39);
    lua_setfield(L, -2, g_str_VK_RIGHT_00a71a24);
    lua_pushinteger(L, 40);
    lua_setfield(L, -2, g_str_VK_DOWN_00a71a30);
    lua_pushinteger(L, 41);
    lua_setfield(L, -2, g_str_VK_SELECT_00a71a38);
    lua_pushinteger(L, 42);
    lua_setfield(L, -2, g_str_VK_PRINT_00a71a44);
    lua_pushinteger(L, 43);
    lua_setfield(L, -2, g_str_VK_EXECUTE_00a71a50);
    lua_pushinteger(L, 44);
    lua_setfield(L, -2, g_str_VK_SNAPSHOT_00a71a5c);
    lua_pushinteger(L, 45);
    lua_setfield(L, -2, g_str_VK_INSERT_00a71a68);
    lua_pushinteger(L, 46);
    lua_setfield(L, -2, g_str_VK_DELETE_00a71a74);
    lua_pushinteger(L, 47);
    lua_setfield(L, -2, g_str_VK_HELP_00a71a80);
    lua_pushinteger(L, 91);
    lua_setfield(L, -2, g_str_VK_LWIN_00a71a88);
    lua_pushinteger(L, 92);
    lua_setfield(L, -2, g_str_VK_RWIN_00a71a90);
    lua_pushinteger(L, 93);
    lua_setfield(L, -2, g_str_VK_APPS_00a71a98);
    lua_pushinteger(L, 95);
    lua_setfield(L, -2, g_str_VK_SLEEP_00a71aa0);
    lua_pushinteger(L, 96);
    lua_setfield(L, -2, g_str_VK_NUMPAD0_00a71aac);
    lua_pushinteger(L, 97);
    lua_setfield(L, -2, g_str_VK_NUMPAD1_00a71ab8);
    lua_pushinteger(L, 98);
    lua_setfield(L, -2, g_str_VK_NUMPAD2_00a71ac4);
    lua_pushinteger(L, 99);
    lua_setfield(L, -2, g_str_VK_NUMPAD3_00a71ad0);
    lua_pushinteger(L, 100);
    lua_setfield(L, -2, g_str_VK_NUMPAD4_00a71adc);
    lua_pushinteger(L, 101);
    lua_setfield(L, -2, g_str_VK_NUMPAD5_00a71ae8);
    lua_pushinteger(L, 102);
    lua_setfield(L, -2, g_str_VK_NUMPAD6_00a71af4);
    lua_pushinteger(L, 103);
    lua_setfield(L, -2, g_str_VK_NUMPAD7_00a71b00);
    lua_pushinteger(L, 104);
    lua_setfield(L, -2, g_str_VK_NUMPAD8_00a71b0c);
    lua_pushinteger(L, 105);
    lua_setfield(L, -2, g_str_VK_NUMPAD9_00a71b18);
    lua_pushinteger(L, 106);
    lua_setfield(L, -2, g_str_VK_MULTIPLY_00a71b24);
    lua_pushinteger(L, 107);
    lua_setfield(L, -2, g_str_VK_ADD_00a71b30);
    lua_pushinteger(L, 108);
    lua_setfield(L, -2, g_str_VK_SEPARATOR_00a71b38);
    lua_pushinteger(L, 109);
    lua_setfield(L, -2, g_str_VK_SUBTRACT_00a71b48);
    lua_pushinteger(L, 110);
    lua_setfield(L, -2, g_str_VK_DECIMAL_00a71b54);
    lua_pushinteger(L, 111);
    lua_setfield(L, -2, g_str_VK_DIVIDE_00a71b60);
    lua_pushinteger(L, 112);
    lua_setfield(L, -2, g_str_VK_F1_00a71b6c);
    lua_pushinteger(L, 113);
    lua_setfield(L, -2, g_str_VK_F2_00a71b74);
    lua_pushinteger(L, 114);
    lua_setfield(L, -2, g_str_VK_F3_00a71b7c);
    lua_pushinteger(L, 115);
    lua_setfield(L, -2, g_str_VK_F4_00a71b84);
    lua_pushinteger(L, 116);
    lua_setfield(L, -2, g_str_VK_F5_00a71b8c);
    lua_pushinteger(L, 117);
    lua_setfield(L, -2, g_str_VK_F6_00a71b94);
    lua_pushinteger(L, 118);
    lua_setfield(L, -2, g_str_VK_F7_00a71b9c);
    lua_pushinteger(L, 119);
    lua_setfield(L, -2, g_str_VK_F8_00a71ba4);
    lua_pushinteger(L, 120);
    lua_setfield(L, -2, g_str_VK_F9_00a71bac);
    lua_pushinteger(L, 121);
    lua_setfield(L, -2, g_str_VK_F10_00a71bb4);
    lua_pushinteger(L, 122);
    lua_setfield(L, -2, g_str_VK_F11_00a71bbc);
    lua_pushinteger(L, 123);
    lua_setfield(L, -2, g_str_VK_F12_00a71bc4);
    lua_pushinteger(L, 124);
    lua_setfield(L, -2, g_str_VK_F13_00a71bcc);
    lua_pushinteger(L, 125);
    lua_setfield(L, -2, g_str_VK_F14_00a71bd4);
    lua_pushinteger(L, 126);
    lua_setfield(L, -2, g_str_VK_F15_00a71bdc);
    lua_pushinteger(L, 127);
    lua_setfield(L, -2, g_str_VK_F16_00a71be4);
    lua_pushinteger(L, 128);
    lua_setfield(L, -2, g_str_VK_F17_00a71bec);
    lua_pushinteger(L, 129);
    lua_setfield(L, -2, g_str_VK_F18_00a71bf4);
    lua_pushinteger(L, 130);
    lua_setfield(L, -2, g_str_VK_F19_00a71bfc);
    lua_pushinteger(L, 131);
    lua_setfield(L, -2, g_str_VK_F20_00a71c04);
    lua_pushinteger(L, 132);
    lua_setfield(L, -2, g_str_VK_F21_00a71c0c);
    lua_pushinteger(L, 133);
    lua_setfield(L, -2, g_str_VK_F22_00a71c14);
    lua_pushinteger(L, 134);
    lua_setfield(L, -2, g_str_VK_F23_00a71c1c);
    lua_pushinteger(L, 135);
    lua_setfield(L, -2, g_str_VK_F24_00a71c24);
    lua_pushinteger(L, 144);
    lua_setfield(L, -2, g_str_VK_NUMLOCK_00a71c2c);
    lua_pushinteger(L, 145);
    lua_setfield(L, -2, g_str_VK_SCROLL_00a71c38);
    lua_pushinteger(L, 146);
    lua_setfield(L, -2, g_str_VK_OEM_NEC_EQUAL_00a71c44);
    lua_pushinteger(L, 146);
    lua_setfield(L, -2, g_str_VK_OEM_FJ_JISHO_00a71c58);
    lua_pushinteger(L, 147);
    lua_setfield(L, -2, g_str_VK_OEM_FJ_MASSHOU_00a71c68);
    lua_pushinteger(L, 148);
    lua_setfield(L, -2, g_str_VK_OEM_FJ_TOUROKU_00a71c7c);
    lua_pushinteger(L, 149);
    lua_setfield(L, -2, g_str_VK_OEM_FJ_LOYA_00a71c90);
    lua_pushinteger(L, 150);
    lua_setfield(L, -2, g_str_VK_OEM_FJ_ROYA_00a71ca0);
    lua_pushinteger(L, 160);
    lua_setfield(L, -2, g_str_VK_LSHIFT_00a71cb0);
    lua_pushinteger(L, 161);
    lua_setfield(L, -2, g_str_VK_RSHIFT_00a71cbc);
    lua_pushinteger(L, 162);
    lua_setfield(L, -2, g_str_VK_LCONTROL_00a71cc8);
    lua_pushinteger(L, 163);
    lua_setfield(L, -2, g_str_VK_RCONTROL_00a71cd4);
    lua_pushinteger(L, 164);
    lua_setfield(L, -2, g_str_VK_LMENU_00a71ce0);
    lua_pushinteger(L, 165);
    lua_setfield(L, -2, g_str_VK_RMENU_00a71cec);
    lua_pushinteger(L, 166);
    lua_setfield(L, -2, g_str_VK_BROWSER_BACK_00a71cf8);
    lua_pushinteger(L, 167);
    lua_setfield(L, -2, g_str_VK_BROWSER_FORWARD_00a71d08);
    lua_pushinteger(L, 168);
    lua_setfield(L, -2, g_str_VK_BROWSER_REFRESH_00a71d1c);
    lua_pushinteger(L, 169);
    lua_setfield(L, -2, g_str_VK_BROWSER_STOP_00a71d30);
    lua_pushinteger(L, 170);
    lua_setfield(L, -2, g_str_VK_BROWSER_SEARCH_00a71d40);
    lua_pushinteger(L, 171);
    lua_setfield(L, -2, g_str_VK_BROWSER_FAVORITES_00a71d54);
    lua_pushinteger(L, 172);
    lua_setfield(L, -2, g_str_VK_BROWSER_HOME_00a71d6c);
    lua_pushinteger(L, 173);
    lua_setfield(L, -2, g_str_VK_VOLUME_MUTE_00a71d7c);
    lua_pushinteger(L, 174);
    lua_setfield(L, -2, g_str_VK_VOLUME_DOWN_00a71d8c);
    lua_pushinteger(L, 175);
    lua_setfield(L, -2, g_str_VK_VOLUME_UP_00a71d9c);
    lua_pushinteger(L, 176);
    lua_setfield(L, -2, g_str_VK_MEDIA_NEXT_TRACK_00a71dac);
    lua_pushinteger(L, 177);
    lua_setfield(L, -2, g_str_VK_MEDIA_PREV_TRACK_00a71dc0);
    lua_pushinteger(L, 178);
    lua_setfield(L, -2, g_str_VK_MEDIA_STOP_00a71dd4);
    lua_pushinteger(L, 179);
    lua_setfield(L, -2, g_str_VK_MEDIA_PLAY_PAUSE_00a71de4);
    lua_pushinteger(L, 180);
    lua_setfield(L, -2, g_str_VK_LAUNCH_MAIL_00a71df8);
    lua_pushinteger(L, 181);
    lua_setfield(L, -2, g_str_VK_LAUNCH_MEDIA_SELECT_00a71e08);
    lua_pushinteger(L, 182);
    lua_setfield(L, -2, g_str_VK_LAUNCH_APP1_00a71e20);
    lua_pushinteger(L, 183);
    lua_setfield(L, -2, g_str_VK_LAUNCH_APP2_00a71e30);
    lua_pushinteger(L, 186);
    lua_setfield(L, -2, g_str_VK_OEM_1_00a71e40);
    lua_pushinteger(L, 187);
    lua_setfield(L, -2, g_str_VK_OEM_PLUS_00a71e4c);
    lua_pushinteger(L, 188);
    lua_setfield(L, -2, g_str_VK_OEM_COMMA_00a71e58);
    lua_pushinteger(L, 189);
    lua_setfield(L, -2, g_str_VK_OEM_MINUS_00a71e68);
    lua_pushinteger(L, 190);
    lua_setfield(L, -2, g_str_VK_OEM_PERIOD_00a71e78);
    lua_pushinteger(L, 191);
    lua_setfield(L, -2, g_str_VK_OEM_2_00a71e88);
    lua_pushinteger(L, 192);
    lua_setfield(L, -2, g_str_VK_OEM_3_00a71e94);
    lua_pushinteger(L, 219);
    lua_setfield(L, -2, g_str_VK_OEM_4_00a71ea0);
    lua_pushinteger(L, 220);
    lua_setfield(L, -2, g_str_VK_OEM_5_00a71eac);
    lua_pushinteger(L, 221);
    lua_setfield(L, -2, g_str_VK_OEM_6_00a71eb8);
    lua_pushinteger(L, 222);
    lua_setfield(L, -2, g_str_VK_OEM_7_00a71ec4);
    lua_pushinteger(L, 223);
    lua_setfield(L, -2, g_str_VK_OEM_8_00a71ed0);
    lua_pushinteger(L, 225);
    lua_setfield(L, -2, g_str_VK_OEM_AX_00a71edc);
    lua_pushinteger(L, 226);
    lua_setfield(L, -2, g_str_VK_OEM_102_00a71ee8);
    lua_pushinteger(L, 227);
    lua_setfield(L, -2, g_str_VK_ICO_HELP_00a71ef4);
    lua_pushinteger(L, 228);
    lua_setfield(L, -2, g_str_VK_ICO_00_00a71f00);
    lua_pushinteger(L, 229);
    lua_setfield(L, -2, g_str_VK_PROCESSKEY_00a71f0c);
    lua_pushinteger(L, 230);
    lua_setfield(L, -2, g_str_VK_ICO_CLEAR_00a71f1c);
    lua_pushinteger(L, 231);
    lua_setfield(L, -2, g_str_VK_PACKET_00a71f2c);
    lua_pushinteger(L, 233);
    lua_setfield(L, -2, g_str_VK_OEM_RESET_00a71f38);
    lua_pushinteger(L, 234);
    lua_setfield(L, -2, g_str_VK_OEM_JUMP_00a71f48);
    lua_pushinteger(L, 235);
    lua_setfield(L, -2, g_str_VK_OEM_PA1_00a71f54);
    lua_pushinteger(L, 236);
    lua_setfield(L, -2, g_str_VK_OEM_PA2_00a71f60);
    lua_pushinteger(L, 237);
    lua_setfield(L, -2, g_str_VK_OEM_PA3_00a71f6c);
    lua_pushinteger(L, 238);
    lua_setfield(L, -2, g_str_VK_OEM_WSCTRL_00a71f78);
    lua_pushinteger(L, 239);
    lua_setfield(L, -2, g_str_VK_OEM_CUSEL_00a71f88);
    lua_pushinteger(L, 240);
    lua_setfield(L, -2, g_str_VK_OEM_ATTN_00a71f98);
    lua_pushinteger(L, 241);
    lua_setfield(L, -2, g_str_VK_OEM_FINISH_00a71fa4);
    lua_pushinteger(L, 242);
    lua_setfield(L, -2, g_str_VK_OEM_COPY_00a71fb4);
    lua_pushinteger(L, 243);
    lua_setfield(L, -2, g_str_VK_OEM_AUTO_00a71fc0);
    lua_pushinteger(L, 244);
    lua_setfield(L, -2, g_str_VK_OEM_ENLW_00a71fcc);
    lua_pushinteger(L, 245);
    lua_setfield(L, -2, g_str_VK_OEM_BACKTAB_00a71fd8);
    lua_pushinteger(L, 246);
    lua_setfield(L, -2, g_str_VK_ATTN_00a71fe8);
    lua_pushinteger(L, 247);
    lua_setfield(L, -2, g_str_VK_CRSEL_00a71ff0);
    lua_pushinteger(L, 248);
    lua_setfield(L, -2, g_str_VK_EXSEL_00a71ffc);
    lua_pushinteger(L, 249);
    lua_setfield(L, -2, g_str_VK_EREOF_00a72008);
    lua_pushinteger(L, 250);
    lua_setfield(L, -2, g_str_VK_PLAY_00a72014);
    lua_pushinteger(L, 251);
    lua_setfield(L, -2, g_str_VK_ZOOM_00a7201c);
    lua_pushinteger(L, 252);
    lua_setfield(L, -2, g_str_VK_NONAME_00a72024);
    lua_pushinteger(L, 253);
    lua_setfield(L, -2, g_str_VK_PA1_00a72030);
    lua_pushinteger(L, 254);
    lua_setfield(L, -2, g_str_VK_OEM_CLEAR_00a72038);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_GameStateTypes_00a72048);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_GameStateTypes_00a72048);
    }
    lua_pushinteger(L, -1);
    lua_setfield(L, -2, g_str_CIV5_GS_UNKNOWN_00a72058);
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_CIV5_GS_EXIT_00a72068);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_CIV5_GS_OPENING_MOVIE_00a72078);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_CIV5_GS_LOAD_GAME_00a72090);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_CIV5_GS_MAIN_MENU_00a720a4);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_CIV5_GS_MULTIPLAYER_MENU_00a720b8);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_CIV5_GS_LANLOBBY_00a720d4);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_CIV5_GS_INETLOBBY_00a720e8);
    lua_pushinteger(L, 7);
    lua_setfield(L, -2, g_str_CIV5_GS_STAGING_00a720fc);
    lua_pushinteger(L, 8);
    lua_setfield(L, -2, g_str_CIV5_GS_SCENARIOSETUP_00a7210c);
    lua_pushinteger(L, 9);
    lua_setfield(L, -2, g_str_CIV5_GS_MAINGAMEVIEW_00a72124);
    lua_pushinteger(L, 10);
    lua_setfield(L, -2, g_str_CIV5_GS_UI_VIEWER_00a7213c);
    lua_pushinteger(L, 11);
    lua_setfield(L, -2, g_str_CIV5_GS_LEADER_HEAD_BENCHMARK_00a72150);
    lua_pushinteger(L, 12);
    lua_setfield(L, -2, g_str_CIV5_GS_LEADER_HEAD_VIEW_00a72170);
    lua_pushinteger(L, 13);
    lua_setfield(L, -2, g_str_CIV5_GS_NEXUS_00a7218c);
    lua_pushinteger(L, 14);
    lua_setfield(L, -2, g_str_CIV5_GS_WORLD_BUILDER_LOAD_00a7219c);
    lua_pushinteger(L, 15);
    lua_setfield(L, -2, g_str_CIV5_GS_CREDITS_00a721b8);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_SlotStatus_00a721c8);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_SlotStatus_00a721c8);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_SS_OPEN_00a721d4);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_SS_COMPUTER_00a721dc);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_SS_CLOSED_00a721e8);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_SS_TAKEN_00a721f4);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_SS_OBSERVER_00a72200);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_SS_MAX_SLOT_STATUS_00a7220c);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_SlotClaim_00a72220);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_SlotClaim_00a72220);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_SLOTCLAIM_UNASSIGNED_00a7222c);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_SLOTCLAIM_RESERVED_00a72244);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_SLOTCLAIM_ASSIGNED_00a72258);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_NUM_SLOTCLAIMS_00a7226c);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_GameTypes_00a7227c);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_GameTypes_00a7227c);
    }
    lua_pushinteger(L, -1);
    lua_setfield(L, -2, g_str_GAME_TYPE_NONE_00a72288);
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_GAME_SINGLE_PLAYER_00a72298);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_GAME_NETWORK_MULTIPLAYER_00a722ac);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_GAME_HOTSEAT_MULTIPLAYER_00a722c8);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_GAME_EMAIL_MULTIPLAYER_00a722e4);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_NetErrors_00a722fc);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_NetErrors_00a722fc);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_NO_ERROR_00a72308);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_MISSING_REQUIRED_DATA_00a72314);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_ROOM_FULL_00a7232c);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_NetKicked_00a72338);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_NetKicked_00a72338);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_NONE_00a72344);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_NO_HOST_00a7234c);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_BY_HOST_00a72354);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_TIMEOUT_00a7235c);
    lua_pushinteger(L, 4);
    lua_setfield(L, -2, g_str_UNRECOGNIZED_00a72364);
    lua_pushinteger(L, 5);
    lua_setfield(L, -2, g_str_UNAUTHORIZED_00a72374);
    lua_pushinteger(L, 6);
    lua_setfield(L, -2, g_str_NO_ROOM_00a72384);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_GameTypes_00a7238c);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_GameTypes_00a7238c);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_GAME_SINGLE_PLAYER_00a72398);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_GAME_NETWORK_MULTIPLAYER_00a723ac);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_GAME_HOTSEAT_MULTIPLAYER_00a723c8);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_GAME_EMAIL_MULTIPLAYER_00a723e4);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_GameViewTypes_00a723fc);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_GameViewTypes_00a723fc);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_GAMEVIEW_NONE_00a7240c);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_GAMEVIEW_STANDARD_00a7241c);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_GAMEVIEW_STRATEGIC_00a72430);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
    lua_getfield(L, -1, g_str_MultiplayerLobbyMode_00a72444);
    if (!lua_type(L, -1)) {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, g_str_MultiplayerLobbyMode_00a72444);
    }
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, g_str_LOBBYMODE_STANDARD_INTERNET_00a7245c);
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, g_str_LOBBYMODE_STANDARD_LAN_00a72478);
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, g_str_LOBBYMODE_PITBOSS_INTERNET_00a72490);
    lua_pushinteger(L, 3);
    lua_setfield(L, -2, g_str_LOBBYMODE_PITBOSS_LAN_00a724ac);
    lua_checkstack(L, 1);
    lua_settop(L, -2);
}
