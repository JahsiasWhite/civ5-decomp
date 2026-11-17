// c5d-model: Gemini 3.8 Flash
extern "C" __declspec(dllimport) int __stdcall AIL_pause_stream(void*, int);

// src: LIB [0x00923110]
int __cdecl MSS_AIL_pause_stream(void* p) {
    return AIL_pause_stream(p, 1);
}
