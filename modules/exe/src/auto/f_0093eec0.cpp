// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Inner_0093eec0 {
    char pad[0x10];
    void* field_10;
};
struct Outer_0093eec0 {
    Inner_0093eec0* inner;
};

// src: GUESS (confidence: high) [0x0093eec0]
void* __cdecl Get_0093eec0(Outer_0093eec0* p) {
    return p->inner->field_10;
}
