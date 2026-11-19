// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_service_stream(void*, void*);
// src: LIB [0x009230c0]
int __cdecl MSS_AIL_service_stream(void* a, void* b) {
    return AIL_service_stream(a, b);
}
