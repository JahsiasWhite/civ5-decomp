// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_stream_ms_position(void* s, int total, int* cur);

// src: LIB [0x00923400]
int __cdecl GetStreamMsPos_00923400(void* s) {
    int pos;
    AIL_stream_ms_position(s, 0, &pos);
    return pos;
}
