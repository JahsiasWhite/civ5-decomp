// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Inner_0093b2b0 {
    char pad[4];
    void* field_04;
};
struct Outer_0093b2b0 {
    Inner_0093b2b0* inner;
};

// src: GUESS (confidence: high) [0x0093b2b0]
void* __cdecl Get_0093b2b0(Outer_0093b2b0* p) {
    return p->inner->field_04;
}
