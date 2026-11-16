// c5d-model: Gemini 3.8 Flash
struct Obj_009bbf80 {
    char pad[0x18];
    int val;
};

// src: GUESS (confidence: high) [0x009bbf80]
char __cdecl CheckField_009bbf80(Obj_009bbf80* p) {
    return p->val < 3;
}
