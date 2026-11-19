// src: GUESS (confidence: low) [0x00944a10]
struct Obj_00944a10 {
    char pad[4];
    int unk4;
    char pad2[4];
    int unkc;
};

// src: GUESS (confidence: low) [0x00944a10]
void SetFlag_00944a10(Obj_00944a10* obj, int flag) {
    if (flag != 0 && obj->unk4 != 0) {
        obj->unkc = 1;
    } else {
        obj->unkc = 0;
    }
}
