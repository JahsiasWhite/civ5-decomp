// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_distances(void* sample, float maxDist, float minDist, int autoVolume);

// src: GUESS 0x00923520 (confidence: high)
void MSS_SetSample3DDistances_00923520(void* sample, float minDist, float maxDist) {
    AIL_set_sample_3D_distances(sample, maxDist, minDist, 1);
}
