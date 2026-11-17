// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Oy-
struct Obj_007ca610 {
    char pad[0x3d];
    char flag;
};
// src: GUESS (confidence: high) [0x007ca610]
void __cdecl SetFlag_007ca610(Obj_007ca610* p) {
    if (p) {
        p->flag = 1;
    }
}
