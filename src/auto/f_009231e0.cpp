// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_set_sample_playback_rate(void*, void*);
// src: LIB [0x009231e0]
int __cdecl MSS_AIL_set_sample_playback_rate(void* a, void* b) {
    return AIL_set_sample_playback_rate(a, b);
}
