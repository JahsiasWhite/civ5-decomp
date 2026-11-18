#include <cstdarg>
#include <cstdio>

// src: GUESS 0x10001b20 (confidence: high)
int FormatBuf_10001b20(char* dst, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int n = vsprintf_s(dst, 0x200, fmt, args);
    va_end(args);
    return n;
}
