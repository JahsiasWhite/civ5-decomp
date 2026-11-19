// c5d-model: Gemini 4 Hydrogen
struct Sub_0093af40 {
    char pad[0x14];
    int flags;
    int val;
};

struct Obj_0093af40 {
    char pad0[0x14];
    int flags;
    int val;
    char pad1[0x8];
    Sub_0093af40* sub;
};

// src: GUESS (confidence: high) [0x0093af40]
void __cdecl CopyState_0093af40(Obj_0093af40* o) {
    o->flags |= o->sub->flags & 0xf;
    o->val = o->sub->val;
}
