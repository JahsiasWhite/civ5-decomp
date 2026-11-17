// c5d-model: Gemini 4 Hydrogen
#include <stdarg.h>

extern "C" __declspec(dllimport) int __cdecl vsprintf_s(char* buf, unsigned int sz, const char* fmt, va_list ap);

// src: GUESS (confidence: high) [0x007747f0]
void Format_007747f0(char* buf, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf_s(buf, 0x40, fmt, ap);
}
