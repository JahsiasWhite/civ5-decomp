// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_sample_ms_position(void* s, int total, int* cur);

// src: LIB [0x009233e0]
int __cdecl GetSampleMsPos_009233e0(void* s) {
    int pos;
    AIL_sample_ms_position(s, 0, &pos);
    return pos;
}
