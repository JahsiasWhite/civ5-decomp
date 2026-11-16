// c5d-model: Gemini 3.8 Flash
struct Obj_009bbfb0 {
    char pad[0x5c];
    int val;
};

// src: GUESS (confidence: high) [0x009bbfb0]
void __cdecl SetField_009bbfb0(Obj_009bbfb0* p, int val) {
    p->val = val;
}
