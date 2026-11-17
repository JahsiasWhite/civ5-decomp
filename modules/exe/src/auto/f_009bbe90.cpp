extern "C" {
    extern int g_val_0606fc00;
    extern int g_val_0606fc04;
}

// src: GUESS (confidence: high) [0x009bbe90]
void __cdecl SetGlobals_009bbe90(const int* src) {
    g_val_0606fc00 = src[0];
    g_val_0606fc04 = src[1];
}
