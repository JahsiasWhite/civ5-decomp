// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: medium) [0x008d4cc0]
struct Struct36 {
    int m_data[9];
};

// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: medium) [0x008d4cc0]
extern "C" Struct36* __cdecl LookupStruct36(int id);

// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: medium) [0x008d4cc0]
Struct36* __cdecl CopyStruct36ById(int id, Struct36* pOut) {
    Struct36* pFound = LookupStruct36(id);
    if (!pFound) {
        return 0;
    }
    *pOut = *pFound;
    return pOut;
}
