#include <cstdarg>
#include <cstdio>

// src: GUESS 0x10071b10 (confidence: high)
int FormatBuf_10071b10(char* dst, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int n = vsprintf_s(dst, 0x1000, fmt, args);
    va_end(args);
    return n;
}
