// src: GUESS (confidence: low)
struct Elem20 {
    int f0;
    int f4;
    int f8;
    int f12;
    int id;
};

// src: GUESS (confidence: medium)
int* __cdecl f_005647c0(int* out, Elem20* begin, Elem20* end, int val) {
    for (Elem20* p = begin; p != end; ++p) {
        if (p->id == val) {
            p->id = 0;
        }
    }
    *out = val;
    return out;
}
