// c5d-model: Gemini 4 Hydrogen
struct Off_00969d30 {
    int offset;
};
struct Base_00969d30 {
    int pad;
    char* base;
};
// src: GUESS (confidence: high) [0x00969d30]
int __cdecl ReadAt_00969d30(Off_00969d30* a, Base_00969d30* b) {
    return *(int*)(b->base + a->offset);
}
