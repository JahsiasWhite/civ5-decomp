// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Guid_006661f0 {
    unsigned int d0;
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
};

// src: GUESS (confidence: low)
struct Obj_006661f0 {
    virtual void* __stdcall Query(Guid_006661f0 guid) = 0;
};

// src: EXE [0x0096ef80]
extern const Guid_006661f0 g_guid_0096ef80;

// src: GUESS (confidence: low)
void* __stdcall GetInterface_006661f0(Obj_006661f0* obj) {
    return obj->Query(g_guid_0096ef80);
}
