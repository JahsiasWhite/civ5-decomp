// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Oy-
struct Obj_007d3e40 {
    char pad[0x14];
    int val;
};
// src: GUESS (confidence: high) [0x007d3e40]
int __cdecl AddVal_007d3e40(Obj_007d3e40* p, int delta) {
    p->val += delta;
    return 0;
}
