// c5d-model: Gemini 3.8 Flash

extern "C" __declspec(dllimport) int __stdcall AIL_mem_use_free(void*);

// src: LIB [0x00922e30]
int __cdecl MSS_AIL_mem_use_free(void* p) {
    return AIL_mem_use_free(p);
}
