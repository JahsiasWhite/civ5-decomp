// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/O2 -/Ob1 +/Od
struct Host_008a8590 {
    char pad[0x30];
    int m_a;
    int m_b;
};

// src: GUESS (confidence: high) [0x008a8590]
void __cdecl SetPair_008a8590(Host_008a8590* h, int b, int a) {
    h->m_a = a;
    h->m_b = b;
}
