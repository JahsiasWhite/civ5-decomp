// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_register_EOS_callback(void*, void*);
// src: LIB [0x009231a0]
int __cdecl MSS_AIL_register_EOS_callback(void* a, void* b) {
    return AIL_register_EOS_callback(a, b);
}
