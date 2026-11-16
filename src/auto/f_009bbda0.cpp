// c5d-model: Gemini 4 Hydrogen
struct Inner_009bbda0 {
    char pad[8];
    int val;
};
struct Obj_009bbda0 {
    char pad[4];
    Inner_009bbda0* inner;
};
// src: GUESS (confidence: high) [0x009bbda0]
int __cdecl GetVal_009bbda0(Obj_009bbda0* p) {
    int res = 0;
    if (p->inner) res = p->inner->val;
    return res;
}
