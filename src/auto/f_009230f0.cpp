// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_start_stream(void*);

// src: LIB [0x009230f0]
int __cdecl MSS_AIL_start_stream(void* p) {
    return AIL_start_stream(p);
}
