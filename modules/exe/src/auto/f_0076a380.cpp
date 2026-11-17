// c5d-model: Gemini 4 Hydrogen
#include <stdarg.h>

extern "C" __declspec(dllimport) int __cdecl vsprintf_s(char* buf, unsigned int sz, const char* fmt, va_list ap);

// src: GUESS (confidence: high) [0x0076a380]
void Format_0076a380(char* buf, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf_s(buf, 0x8, fmt, ap);
}
