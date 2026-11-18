// src: LIB [0x009d6d54]
extern "C" __declspec(dllimport) void __stdcall AIL_set_digital_master_reverb_levels(void* driver, float dry, float wet);

// src: GUESS (confidence: medium) [0x00923040]
void __cdecl MSS_SetMasterReverbLevels(void* driver, float dry, float wet)
{
    AIL_set_digital_master_reverb_levels(driver, dry, wet);
}
