// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void* __stdcall AIL_open_stream(void* driver, const char* filename, int flags);

// src: LIB [0x009237f0]
void* __cdecl OpenStream_009237f0(void* driver, const char* const* pFilename, int flags) {
    const char* name = *pFilename;
    return AIL_open_stream(driver, name, flags);
}
