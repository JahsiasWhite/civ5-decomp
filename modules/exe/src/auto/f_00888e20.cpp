// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_sample_loop_count(void*);

// src: LIB [0x00923220]
int __cdecl MSS_AIL_sample_loop_count(void* p) {
    return AIL_sample_loop_count(p);
}
