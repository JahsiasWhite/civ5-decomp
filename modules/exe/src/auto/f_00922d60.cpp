// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_register_falloff_function_callback(void*, void*);
// src: LIB [0x00922d60]
int __cdecl MSS_AIL_register_falloff_function_callback(void* a, void* b) {
    return AIL_register_falloff_function_callback(a, b);
}
