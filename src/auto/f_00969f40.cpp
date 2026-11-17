// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct FlagsRec_00969f40 {
    unsigned int m_flags;
    int m_pad4;
    int m_offset;
};

// src: GUESS (confidence: high) [0x00969f40]
int* ResolvePtr_00969f40(int* basePtr, const FlagsRec_00969f40* rec) {
    if ((rec->m_flags & 0x400) != 0) {
        return basePtr;
    }
    return (int*)(rec->m_offset + *basePtr);
}
