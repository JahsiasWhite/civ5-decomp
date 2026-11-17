// c5d-model: Gemini 4 Hydrogen
#include <windows.h>
// src: GUESS (confidence: high) [0x00831490]
BOOL __cdecl GetCompName_00831490(LPSTR buf, LPDWORD sz) {
    return GetComputerNameA(buf, sz);
}
