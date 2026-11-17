// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_sample_ms_position(void* s, int* total, int* cur);

// src: LIB [0x009233a0]
int __cdecl GetSampleTotalMs_009233a0(void* s) {
    int total;
    AIL_sample_ms_position(s, &total, 0);
    return total;
}
