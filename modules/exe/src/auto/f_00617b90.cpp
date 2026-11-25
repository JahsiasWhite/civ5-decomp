// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct F00617b90 {
    unsigned char pad0[0x5b4];
    float f5b4;

    float __thiscall f_00617b90(int mode);
};

float __thiscall F00617b90::f_00617b90(int mode) {
    switch (mode) {
    case 0:
        return f5b4 + 0.0f;
    case 1:
        return f5b4 - 0.0f;
    case 2:
        return f5b4 - 4.0f;
    case 3:
        return f5b4 - 7.0f;
    case 4:
        return f5b4 + 40.0f;
    case 5:
        return f5b4 + 15.0f;
    case 6:
        return f5b4 + 35.0f;
    default:
        return f5b4;
    }
}
