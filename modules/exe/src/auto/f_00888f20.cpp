// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_volume_pan(void* sample, float volume, float pan);

// src: GUESS 0x00923320 (confidence: high)
void MSS_SetSampleVolume_00923320(void* sample, float volume) {
    AIL_set_sample_volume_pan(sample, volume, 0.5f);
}
