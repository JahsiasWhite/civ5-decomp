// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Inner_0093b290 {
    char pad[0x0c];
    void* field_0c;
};
struct Outer_0093b290 {
    Inner_0093b290* inner;
};

// src: GUESS (confidence: high) [0x0093b290]
void* __cdecl Get_0093b290(Outer_0093b290* p) {
    return p->inner->field_0c;
}
