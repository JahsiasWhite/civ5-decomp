// c5d-model: Orchestrator (Argon)
// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2

#define COPY16(d, s) \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s);

// src: GUESS (confidence: medium) [0x008967e0]
void __cdecl SetMatrix_008967e0(void* obj, const float* mat) {
    float* a1;
    const float* a2;
    float* a3;
    const float* a4;
    if ((*(int*)(*(char**)((char*)obj + 0x164) + 0x68) & 0x200) == 0) {
        a1 = (float*)((char*)obj + 0x2c4);
        a4 = (const float*)((char*)obj + 0x110);
        COPY16(a1, a4);
    }
    a3 = (float*)((char*)obj + 0x110);
    a2 = mat;
    COPY16(a3, a2);
}
