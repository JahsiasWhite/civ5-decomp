// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Od
struct Inner_008a8560 {
    char pad[4];
    void* val;
};
struct Outer_008a8560 {
    char pad[0x318];
    Inner_008a8560* inner;
};
// src: GUESS (confidence: low) [0x008a8560]
void* __cdecl GetField_008a8560(Outer_008a8560* p) {
    return p->inner->val;
}
