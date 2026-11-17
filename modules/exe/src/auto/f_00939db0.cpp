// c5d-model: Gemini 4 Hydrogen
#include <windows.h>
typedef DWORD (__stdcall *GetThreadIdFn)();
extern GetThreadIdFn g_fn_0606cf94;
// src: GUESS (confidence: high) [0x00939db0]
DWORD __cdecl GetThreadId_00939db0() {
    if (!g_fn_0606cf94) return GetCurrentThreadId();
    return g_fn_0606cf94();
}
