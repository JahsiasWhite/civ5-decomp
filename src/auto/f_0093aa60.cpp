// c5d-model: Gemini 3.8 Flash
struct Obj_0093aa60 {
    char pad[0x14];
    int mask;
};

// src: GUESS (confidence: high) [0x0093aa60]
void __cdecl OrField_0093aa60(Obj_0093aa60* p, int mask) {
    p->mask |= mask;
}
