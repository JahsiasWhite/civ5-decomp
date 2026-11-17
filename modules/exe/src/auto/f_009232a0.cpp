// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_sample_volume_pan(void* s, int* vol, int* pan);

// src: LIB [0x009232a0]
void __cdecl SetSampleVolume_009232a0(void* s, int* vol) {
    int pan;
    AIL_sample_volume_pan(s, vol, &pan);
}
