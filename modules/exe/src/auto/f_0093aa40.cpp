// c5d-model: Gemini 3.8 Flash
struct Obj_0093aa40 {
    char pad[0x14];
    int mask;
};
// src: GUESS (confidence: high) [0x0093aa40]
void __cdecl ClearMask_0093aa40(Obj_0093aa40* p, int mask) {
    p->mask &= ~mask;
}
