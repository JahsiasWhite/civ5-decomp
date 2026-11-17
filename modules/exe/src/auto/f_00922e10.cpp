// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_close_filter(void*);

// src: LIB [0x00922e10]
int __cdecl MSS_AIL_close_filter(void* p) {
    return AIL_close_filter(p);
}
