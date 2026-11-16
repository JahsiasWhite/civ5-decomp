// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_set_sample_loop_count(void*, void*);
// src: LIB [0x00923240]
int __cdecl MSS_AIL_set_sample_loop_count(void* a, void* b) {
    return AIL_set_sample_loop_count(a, b);
}
