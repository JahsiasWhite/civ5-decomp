// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bc040 {
    char pad[0x14];
    void* field_14;
};

// src: GUESS (confidence: high) [0x009bc040]
void* __cdecl GetField14_009bc040(Unk_009bc040* p) {
    return p->field_14;
}
