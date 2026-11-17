// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x0091f9a0]
float __stdcall CalcRatio_0091f9a0(int unused1, float a, float b, float c, int unused2) {
    return c / ((a - c) * b + c);
}
