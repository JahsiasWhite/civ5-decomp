// c5d-cflags: +/Oy-
#include <stdarg.h>
#include <stdio.h>

// printf into a 260-byte buffer.
// src: GUESS (confidence: medium) [0x005fe110]
void FormatBuffer260_005fe110(char* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, 260, format, args);
}
