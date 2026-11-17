// c5d-model: Gemini 3.8 Flash
extern "C" __declspec(dllimport) int __stdcall AIL_set_redist_directory(void*);

// src: LIB [0x009237e0]
int __cdecl MSS_AIL_set_redist_directory(void** p) {
    p = (void**)*p;
    return AIL_set_redist_directory(p);
}
