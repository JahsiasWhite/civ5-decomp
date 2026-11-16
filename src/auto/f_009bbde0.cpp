// c5d-model: Gemini 4 Hydrogen
struct Inner_009bbde0 {
    char pad[4];
    int val;
};
struct Obj_009bbde0 {
    char pad[0x10];
    Inner_009bbde0* inner;
};
// src: GUESS (confidence: high) [0x009bbde0]
int __cdecl GetVal_009bbde0(Obj_009bbde0* p) {
    int res = 0;
    if (p->inner) res = p->inner->val;
    return res;
}
