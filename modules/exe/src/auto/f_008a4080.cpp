// c5d-model: Orchestrator (Argon)
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: medium) [0x008a3590]
extern int __cdecl GetGlobal_008a3590();
// src: GUESS (confidence: medium) [0x00c9ed28]
extern int g_00c9ed28;
// src: GUESS (confidence: medium) [0x00c9ed2c]
extern int g_00c9ed2c;
// src: GUESS (confidence: medium) [0x00c9ed30]
extern int g_00c9ed30;
// src: GUESS (confidence: medium) [0x00c9ed38]
extern int g_00c9ed38;
// src: GUESS (confidence: medium) [0x00c9ed3c]
extern int g_00c9ed3c;
// src: GUESS (confidence: medium) [0x00c9ed40]
extern int g_00c9ed40;
// src: GUESS (confidence: medium) [0x00c9ed44]
extern int g_00c9ed44;

#define ALIGN_UP(sz, a) (((sz) % (a)) ? ((sz) + ((a) - ((sz) % (a)))) : (sz))

// src: GUESS (confidence: medium) [0x008a4080]
void __cdecl CalcSizes_008a4080(int p1, int p2, int p3, int p4, int p5, int* outTotal) {
    int a1;
    int a2;
    int a3;
    unsigned int a4;
    int a5;
    a5 = 0;
    a3 = p1 + p2 * 2 + p4;
    a2 = p2 + p1 * 2 + p4;
    a1 = 8;
    a4 = GetGlobal_008a3590();
    a5 += ALIGN_UP(0x30, a4);
    a5 += ALIGN_UP(0x134, a4) * a3;
    a5 += ALIGN_UP(0x138, a4) * a2;
    a5 += ALIGN_UP(0x20, a4) * a1;
    a5 += (ALIGN_UP(0x10, a4) + ALIGN_UP(0x10, a4)) * (p1 + p2 + p3 + a2 + a3);
    a5 += ALIGN_UP(0x84, a4) * p3;
    a5 += ALIGN_UP(0x360, a4) * p2;
    a5 += ALIGN_UP(0x98, a4) * p1;
    a5 += ALIGN_UP(4, a4) * p2;
    a5 += ALIGN_UP(4, a4) * p3;
    a5 += ALIGN_UP(0x150, a4) * p4;
    a5 += ALIGN_UP(0x20c, a4) * p5;
    a5 += ALIGN_UP(0x320, a4) * (p2 / 2);
    a5 += (a1 + a2) * 32;
    a5 += p2 * 4;
    a5 += p3 * 4;
    a5 += 0x8000;
    g_00c9ed28 = p1;
    g_00c9ed2c = p2;
    g_00c9ed30 = p3;
    g_00c9ed38 = p4;
    g_00c9ed3c = p5;
    g_00c9ed40 = a3;
    g_00c9ed44 = a2;
    if (outTotal) {
        *outTotal = a5;
    }
}
