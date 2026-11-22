extern "C" {
// src: LIB
__declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* Addend, long Value);
}

// src: GUESS (confidence: low)
struct TraceEntry_004baef0 {
    int m_size;
    int m_type;
    int m_08;
    int m_0c;
};

// src: GUESS (confidence: low)
struct TraceRing_004baef0 {
    struct Bank {
        volatile long m_offset;
        char m_pad[0x7c];
        char m_data[0x400000];
    } m_banks[2];
    int m_active;
    char m_pad800104[0x7c];
};

// src: GUESS (confidence: low) [0x01893980]
extern int g_currentHandler_004baef0;
// src: GUESS (confidence: low) [0x01894600]
extern TraceRing_004baef0 g_traceRings_004baef0[];

// src: GUESS (confidence: medium) [0x004baef0]
void Trace_004baef0() {
    TraceRing_004baef0* ring = &g_traceRings_004baef0[g_currentHandler_004baef0];
    TraceRing_004baef0::Bank* bank = &ring->m_banks[ring->m_active & 1];
    long off = InterlockedExchangeAdd(&bank->m_offset, 0x80);
    TraceEntry_004baef0* entry = (TraceEntry_004baef0*)(bank->m_data + off);
    if (entry != 0) {
        entry->m_size = 0x80;
        entry->m_type = 0x27;
        entry->m_08 = 0;
        entry->m_0c = 0;
    }
}
