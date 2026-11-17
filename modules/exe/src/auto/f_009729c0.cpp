// c5d-model: Gemini 3.8 Flash
struct Record_009729c0 {
    int m_f0;
    int m_f4;
    char pad[0x50];
    int m_f58;
    int m_f5c;
};

// src: GUESS (confidence: high) [0x009729c0]
void __cdecl InitRecord_009729c0(Record_009729c0* r) {
    r->m_f4 = 0x1e;
    r->m_f0 = 0;
    r->m_f58 = 0;
    r->m_f5c = 0;
}
