// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bbf70 {
    char pad[0x18];
    void* field_18;
};

// src: GUESS (confidence: high) [0x009bbf70]
void* __cdecl GetField18_009bbf70(Unk_009bbf70* p) {
    return p->field_18;
}
