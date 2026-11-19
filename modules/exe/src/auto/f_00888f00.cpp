// src: LIB [0x009d6db0]
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_volume_pan(void* sample, float volume, float pan);

// src: GUESS (confidence: medium) [0x00923300]
void __cdecl MSS_SetSampleVolumePan(void* sample, float volume, float pan)
{
    AIL_set_sample_volume_pan(sample, volume, pan);
}
