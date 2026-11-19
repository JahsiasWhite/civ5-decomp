// src: GUESS (confidence: low) [0x00905cd0]
struct Out_00905cd0 {
    void* self;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
};

// src: GUESS (confidence: low) [0x00905cd0]
struct Class_00905cd0 {
    void InitOut(Out_00905cd0* out);
};

void Class_00905cd0::InitOut(Out_00905cd0* out) {
    out->unk4 = 0;
    out->unk8 = -2;
    out->unkc = 0;
    out->unk10 = -2;
    out->self = this;
}
