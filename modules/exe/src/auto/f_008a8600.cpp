// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Od
struct Inner_008a8600 {
    char pad[0x54];
    void* val;
};
struct Outer_008a8600 {
    char pad[0x318];
    Inner_008a8600* inner;
};
// src: GUESS (confidence: low) [0x008a8600]
void* __cdecl GetField_008a8600(Outer_008a8600* p) {
    return p->inner->val;
}
