// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Inner_0093b2a0 {
    char pad[0x14];
    void* field_14;
};
struct Outer_0093b2a0 {
    Inner_0093b2a0* inner;
};

// src: GUESS (confidence: high) [0x0093b2a0]
void* __cdecl Get_0093b2a0(Outer_0093b2a0* p) {
    return p->inner->field_14;
}
