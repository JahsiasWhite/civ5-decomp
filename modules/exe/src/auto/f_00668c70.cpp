extern "C" {
// src: LIB
__declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* Addend, long Value);
}

// src: GUESS (confidence: low)
struct TraceEntry_00668c70 {
    int m_size;
    int m_type;
    int m_08;
    int m_0c;
};

// src: GUESS (confidence: low)
struct TraceRing_00668c70 {
    struct Bank {
        volatile long m_offset;
        char m_pad[0x7c];
        char m_data[0x400000];
    } m_banks[2];
    int m_active;
    char m_pad800104[0x7c];
};

// src: GUESS (confidence: low) [0x01893980]
extern int g_currentHandler_00668c70;
// src: GUESS (confidence: low) [0x01894600]
extern TraceRing_00668c70 g_traceRings_00668c70[];

// src: GUESS (confidence: medium) [0x00668c70]
void Trace_00668c70() {
    TraceRing_00668c70* ring = &g_traceRings_00668c70[g_currentHandler_00668c70];
    TraceRing_00668c70::Bank* bank = &ring->m_banks[ring->m_active & 1];
    long off = InterlockedExchangeAdd(&bank->m_offset, 0x80);
    TraceEntry_00668c70* entry = (TraceEntry_00668c70*)(bank->m_data + off);
    if (entry != 0) {
        entry->m_size = 0x80;
        entry->m_type = 0x7b;
        entry->m_08 = 0;
        entry->m_0c = 0;
    }
}
