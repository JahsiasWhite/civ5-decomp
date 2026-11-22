// src: GUESS (confidence: low) [0x008854f0]
float __stdcall interp8854F0(int a1, float x, int a3, float a, float b) {
    if (x > b) {
        return 0.0f;
    }
    if (a >= x) {
        return 1.0f;
    }
    return 1.0f - (x - a) / (b - a);
}
