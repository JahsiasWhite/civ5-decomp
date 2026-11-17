// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bbee0 {
    char pad[0x0c];
    int offset;
};

// src: GUESS (confidence: high) [0x009bbee0]
char* __cdecl CalcPtr_009bbee0(Unk_009bbee0* p) {
    return (char*)p + p->offset;
}
