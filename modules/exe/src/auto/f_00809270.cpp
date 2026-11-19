// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/O2 -/Ob1 +/Od
struct Host_008a31e0 {
    char pad[0x100];
    int a;
    int b;
};

// src: GUESS (confidence: high) [0x008a31e0]
int __cdecl GetSpan_008a31e0(const Host_008a31e0* h) {
    return h->a - h->b;
}
