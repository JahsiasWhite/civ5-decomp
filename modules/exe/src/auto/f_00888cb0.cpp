// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_close_stream(void*);

// src: LIB [0x009230b0]
int __cdecl MSS_AIL_close_stream(void* p) {
    return AIL_close_stream(p);
}
