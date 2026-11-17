// c5d-model: Gemini 4 Hydrogen
typedef int (__cdecl *Fn_0093bbd0)();
extern Fn_0093bbd0 g_fn_0606cfb8;
// src: GUESS (confidence: high) [0x0093bbd0]
int __cdecl CallOrOne_0093bbd0() {
    if (g_fn_0606cfb8) return g_fn_0606cfb8();
    return 1;
}
