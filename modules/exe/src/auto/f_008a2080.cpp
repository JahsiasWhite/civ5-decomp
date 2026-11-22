// src: GUESS (confidence: low)
struct StreamVT;

// src: GUESS (confidence: low)
struct Stream8a {
    StreamVT* vt;
    int a4;
    int a8;
    int a12;
    int a16;
};

// src: GUESS (confidence: low)
struct StreamVT {
    void* f0;
    void* f4;
    void* f8;
    void* f12;
    int (__cdecl* fn1)(Stream8a*, int, int, int, int);
    int (__cdecl* fn2)(Stream8a*, int, int, int, int);
};

// src: GUESS (confidence: medium)
int __cdecl f_008a2080(Stream8a* s, int p1, int p2, int p3, int p4) {
    if (!s->vt->fn2) {
        return -1;
    }
    int r = s->vt->fn2(s, p1, p2, p3, p4);
    if (r > 0) {
        s->a12 += p4;
        s->a16 += r;
    }
    return r;
}
