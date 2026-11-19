// c5d-model: Gemini 4 Hydrogen
struct Obj_009bbe00 {
    char pad[0x10];
    int* ptr;
};
// src: GUESS (confidence: high) [0x009bbe00]
int __cdecl Deref10_009bbe00(Obj_009bbe00* p) {
    int res = 0;
    if (p->ptr) res = *p->ptr;
    return res;
}
