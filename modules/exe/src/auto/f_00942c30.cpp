// c5d-model: Gemini 3.8 Flash
struct Obj_00942c30 {
    char pad[0x20];
    int val;
};

// src: GUESS (confidence: high) [0x00942c30]
void __cdecl SetField_00942c30(Obj_00942c30* p, int val) {
    p->val = val;
}
