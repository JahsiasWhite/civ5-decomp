// c5d-cflags: -/O2 -/Ob1 +/Od
// src: GUESS (confidence: low)
extern "C" const char* __cdecl f_00889f7c(const char* s, int c);

struct F007fdc50Arg {
    int f0;
    char f4[1];
};

const char* __cdecl f_007fdc50(const F007fdc50Arg* arg) {
    const char* p = 0;
    p = f_00889f7c(arg->f4, '\\');
    if (p != 0) {
        p = p + 1;
        return p;
    }
    p = f_00889f7c(arg->f4, '/');
    if (p != 0) {
        p = p + 1;
        return p;
    }
    return arg->f4;
}
