// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bc200 {
    char pad[0x24];
    void* field_24;
};

// src: GUESS (confidence: high) [0x009bc200]
void* __cdecl GetField24_009bc200(Unk_009bc200* p) {
    return p->field_24;
}
