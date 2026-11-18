// c5d-cflags: +/Oy-
#include <stdarg.h>
#include <stdio.h>

// printf into a 128-byte buffer.
// src: GUESS (confidence: medium) [0x0062b610]
void FormatBuffer128_0062b610(char* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, 128, format, args);
}
