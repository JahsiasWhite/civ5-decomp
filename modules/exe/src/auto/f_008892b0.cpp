// src: LIB [0x009d6ddc]
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_reverb_levels(void* sample, float dry, float wet);

// src: GUESS (confidence: medium) [0x009236b0]
void __cdecl MSS_SetSampleReverbLevels(void* sample, float dry, float wet)
{
    AIL_set_sample_reverb_levels(sample, dry, wet);
}
