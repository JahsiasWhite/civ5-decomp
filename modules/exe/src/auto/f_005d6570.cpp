// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Guid_005d6570 {
    unsigned int d0;
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
};

// src: GUESS (confidence: low)
struct Obj_005d6570 {
    virtual void* __stdcall Query(Guid_005d6570 guid) = 0;
};

// src: EXE [0x00964aa8]
extern const Guid_005d6570 g_guid_00964aa8;

// src: GUESS (confidence: low)
void* __stdcall GetInterface_005d6570(Obj_005d6570* obj) {
    return obj->Query(g_guid_00964aa8);
}
