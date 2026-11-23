// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Guid_006661b0 {
    unsigned int d0;
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
};

// src: GUESS (confidence: low)
struct Obj_006661b0 {
    virtual void* __stdcall Query(Guid_006661b0 guid) = 0;
};

// src: EXE [0x0096efb0]
extern const Guid_006661b0 g_guid_0096efb0;

// src: GUESS (confidence: low)
void* __stdcall GetInterface_006661b0(Obj_006661b0* obj) {
    return obj->Query(g_guid_0096efb0);
}
