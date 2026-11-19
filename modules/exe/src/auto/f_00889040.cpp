// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_set_stream_ms_position(void*, void*);
// src: LIB [0x00923440]
int __cdecl MSS_AIL_set_stream_ms_position(void* a, void* b) {
    return AIL_set_stream_ms_position(a, b);
}
