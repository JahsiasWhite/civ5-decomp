// c5d-model: Gemini 4 Hydrogen
struct Inner_00944290 {
    char pad[0x24];
    void* val;
};
struct Obj_00944290 {
    char pad[8];
    Inner_00944290* inner;
};
// src: GUESS (confidence: high) [0x00944290]
void* __cdecl GetVal_00944290(Obj_00944290* p) {
    if (!p) return p;
    return p->inner->val;
}
