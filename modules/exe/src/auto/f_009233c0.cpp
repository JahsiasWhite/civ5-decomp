// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_stream_ms_position(void* s, int* total, int* cur);

// src: LIB [0x009233c0]
int __cdecl GetStreamTotalMs_009233c0(void* s) {
    int total;
    AIL_stream_ms_position(s, &total, 0);
    return total;
}
