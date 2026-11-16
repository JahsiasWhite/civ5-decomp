// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/O2 -/Ob1 +/Od
struct Node_00897f70 {
    int f0;
    int f4;
    int f8;
    int fc;
};

// src: GUESS (confidence: high) [0x00897f70]
int __cdecl AddOffset_00897f70(const Node_00897f70* n) {
    const Node_00897f70* p = n;
    return (int)n + p->fc;
}
