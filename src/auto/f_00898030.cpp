// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/O2 -/Ob1 +/Od
struct Host_00898030 {
    char pad[0x100];
    int a;
    int b;
};

// src: GUESS (confidence: high) [0x00898030]
int __cdecl GetSpan_00898030(const Host_00898030* h) {
    return h->a - h->b;
}
