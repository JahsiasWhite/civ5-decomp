// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low) [0x005d6570]
struct Guid16_005d6570 {
    int a, b, c, d;
};

// src: GUESS (confidence: low) [0x005d6570]
extern const Guid16_005d6570 g_guid_005d6570;

// src: GUESS (confidence: low) [0x005d6570]
struct Obj_005d6570 {
    struct Vtbl {
        int (__stdcall *fn0)(Obj_005d6570*, Guid16_005d6570);
    };
    Vtbl* vtbl;
};

// src: GUESS (confidence: low) [0x005d6570]
int __stdcall CallWithGuid_005d6570(Obj_005d6570* p) {
    return p->vtbl->fn0(p, g_guid_005d6570);
}
