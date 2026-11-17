// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bbce0 {
    char pad[0x14];
    void* field_14;
};

// src: GUESS (confidence: high) [0x009bbce0]
void* __cdecl GetField14_009bbce0(Unk_009bbce0* p) {
    return p->field_14;
}
