// c5d-model: Gemini 3.8 Flash
struct Obj_00946b00 {
    char pad[0x34];
    int val;
};

// src: GUESS (confidence: high) [0x00946b00]
void __cdecl SetField_00946b00(Obj_00946b00* p, int val) {
    p->val = val;
}
