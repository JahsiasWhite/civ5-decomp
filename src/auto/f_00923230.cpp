// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_stream_loop_count(void*);

// src: LIB [0x00923230]
int __cdecl MSS_AIL_stream_loop_count(void* p) {
    return AIL_stream_loop_count(p);
}
