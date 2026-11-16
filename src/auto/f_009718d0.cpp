// c5d-model: Gemini 4 Hydrogen
struct Node_009718d0 {
    int f0;
    int f4;
    int f8;
    void* a;
    void* b;
    int flags;
};

// src: GUESS (confidence: high) [0x009718d0]
void* __cdecl GetPtr_009718d0(const Node_009718d0* n) {
    if (!n) {
        return 0;
    }
    if (n->flags & 2) {
        return n->a;
    }
    return n->b;
}
