extern "C" {
// src: LIB
__declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* Addend, long Value);
}

// src: GUESS (confidence: low)
struct TraceEntry_00845d00 {
    int m_size;
    int m_type;
    int m_08;
    int m_0c;
};

// src: GUESS (confidence: low)
struct TraceRing_00845d00 {
    struct Bank {
        volatile long m_offset;
        char m_pad[0x7c];
        char m_data[0x400000];
    } m_banks[2];
    int m_active;
    char m_pad800104[0x7c];
};

// src: GUESS (confidence: low) [0x01a0e400]
extern int g_currentHandler_01a0e400;
// src: GUESS (confidence: low) [0x01a0f080]
extern TraceRing_00845d00 g_traceRings_01a0f080[];

// src: GUESS (confidence: medium) [0x00845d00]
void* AllocTrace_00845d00() {
    TraceRing_00845d00* ring = &g_traceRings_01a0f080[g_currentHandler_01a0e400];
    TraceRing_00845d00::Bank* bank = &ring->m_banks[ring->m_active & 1];
    long off = InterlockedExchangeAdd(&bank->m_offset, 0x80);
    TraceEntry_00845d00* entry = (TraceEntry_00845d00*)(bank->m_data + off);
    if (entry != 0) {
        entry->m_size = 0x80;
        entry->m_type = 0x82;
        entry->m_08 = 0;
        entry->m_0c = 0;
    }
    return entry + 1;
}
