// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Guid_004b5090 {
    unsigned int d0;
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
};

// src: GUESS (confidence: low)
struct Obj_004b5090 {
    virtual void* __stdcall Query(Guid_004b5090 guid) = 0;
};

// src: EXE [0x0094a49c]
extern const Guid_004b5090 g_guid_0094a49c;

// src: GUESS (confidence: low)
void* __stdcall GetInterface_004b5090(Obj_004b5090* obj) {
    return obj->Query(g_guid_0094a49c);
}
