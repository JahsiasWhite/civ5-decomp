// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_mem_use_malloc(void*);

// src: LIB [0x00922e20]
int __cdecl MSS_AIL_mem_use_malloc(void* p) {
    return AIL_mem_use_malloc(p);
}
