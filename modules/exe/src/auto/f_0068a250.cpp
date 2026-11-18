// c5d-cflags: +/Oy-
#include <stdarg.h>
#include <stdio.h>

// printf into a 512-byte buffer.
// src: GUESS (confidence: medium) [0x0068a250]
void FormatBuffer512_0068a250(char* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, 512, format, args);
}
