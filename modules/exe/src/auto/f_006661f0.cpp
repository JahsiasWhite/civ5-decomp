// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low) [0x006661f0]
struct Guid16_006661f0 {
    int a, b, c, d;
};

// src: GUESS (confidence: low) [0x006661f0]
extern const Guid16_006661f0 g_guid_006661f0;

// src: GUESS (confidence: low) [0x006661f0]
struct Obj_006661f0 {
    struct Vtbl {
        int (__stdcall *fn0)(Obj_006661f0*, Guid16_006661f0);
    };
    Vtbl* vtbl;
};

// src: GUESS (confidence: low) [0x006661f0]
int __stdcall CallWithGuid_006661f0(Obj_006661f0* p) {
    return p->vtbl->fn0(p, g_guid_006661f0);
}
