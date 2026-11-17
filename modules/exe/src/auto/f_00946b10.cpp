// c5d-model: Gemini 3.8 Flash
struct Obj_00946b10 {
    char pad[0x38];
    int val;
};

// src: GUESS (confidence: high) [0x00946b10]
void __cdecl SetField_00946b10(Obj_00946b10* p, int val) {
    p->val = val;
}
