// c5d-model: Gemini 4 Hydrogen
typedef int (__cdecl *Fn_0093bbf0)();
extern Fn_0093bbf0 g_fn_0606cfbc;
// src: GUESS (confidence: high) [0x0093bbf0]
int __cdecl CallOrOne_0093bbf0() {
    if (g_fn_0606cfbc) return g_fn_0606cfbc();
    return 1;
}
