// c5d-model: Gemini 3.8 Flash
struct Obj_0093aa50 {
    char pad[0x14];
    int mask;
};

// src: GUESS (confidence: high) [0x0093aa50]
int __cdecl MaskField_0093aa50(Obj_0093aa50* p, int mask) {
    return p->mask & mask;
}
