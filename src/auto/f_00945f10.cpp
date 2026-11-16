// c5d-model: Gemini 3.8 Flash
struct Obj_00945f10 {
    char pad[8];
    int mask;
};

// src: GUESS (confidence: high) [0x00945f10]
void __cdecl OrField_00945f10(Obj_00945f10* p, int mask) {
    p->mask |= mask;
}
