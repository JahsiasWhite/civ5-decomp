// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bc020 {
    char pad[4];
    void* field_4;
};

// src: GUESS (confidence: high) [0x009bc020]
void* __cdecl GetField4_009bc020(Unk_009bc020* p) {
    return p->field_4;
}
