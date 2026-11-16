// c5d-model: Gemini 4 Hydrogen
struct Inner_009bbdc0 {
    char pad[4];
    int val;
};
struct Obj_009bbdc0 {
    char pad[4];
    Inner_009bbdc0* inner;
};
// src: GUESS (confidence: high) [0x009bbdc0]
int __cdecl GetVal_009bbdc0(Obj_009bbdc0* p) {
    int res = 0;
    if (p->inner) res = p->inner->val;
    return res;
}
