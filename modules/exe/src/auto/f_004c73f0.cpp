extern "C" {
// src: LIB
__declspec(dllimport) int __cdecl memmove_s(void* dst, unsigned int numberOfElements, const void* src, unsigned int count);
}

// src: GUESS (confidence: low)
struct CmdHeader_0062c580 {
    int m_stride;
    int m_04;
    int m_08;
    int m_0c;
    int m_obj;
    void (__thiscall* m_dtor)(void*, void*);
    int m_18;
    int m_1c;
};

// src: GUESS (confidence: low) [0x0062c580]
struct CmdList_0062c580 {
    int m_00;
    char* m_begin;
    char* m_end;
    int m_0c;
    unsigned int m_flags;

    inline void Erase(char* first, char* last) {
        if (first != last) {
            int rem = m_end - last;
            char* newEnd = first + rem;
            if (rem > 0) {
                memmove_s(first, rem, last, rem);
            }
            m_end = newEnd;
        }
    }

    // src: GUESS (confidence: medium) [0x0062c580]
    void Clear();
};

// src: GUESS (confidence: medium) [0x0062c580]
void CmdList_0062c580::Clear() {
    char* end = m_end;
    char* cur = m_begin;
    if (end - cur == 0) {
        return;
    }
    m_flags &= ~1u;
    while (cur != end) {
        CmdHeader_0062c580* hdr = (CmdHeader_0062c580*)cur;
        hdr->m_dtor((void*)hdr->m_obj, cur + 0x20);
        cur += hdr->m_stride;
    }
    Erase(m_begin, m_end);
    m_flags |= 1u;
}
