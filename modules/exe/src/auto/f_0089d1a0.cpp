// src: GUESS (confidence: low) [0x0606cf80]
extern void (__cdecl* g_negHandler_0606cf80)(int a, int b);
// src: GUESS (confidence: low) [0x0606cf84]
extern void (__cdecl* g_nonNegHandler_0606cf84)(int a, int b);

// src: GUESS (confidence: medium) [0x00939dd0]
void DispatchBySign_00939dd0(int a, int b) {
    if (b < 0) {
        if (g_negHandler_0606cf80) {
            g_negHandler_0606cf80(a, b);
        }
    } else {
        if (g_nonNegHandler_0606cf84) {
            g_nonNegHandler_0606cf84(a, b);
        }
    }
}
