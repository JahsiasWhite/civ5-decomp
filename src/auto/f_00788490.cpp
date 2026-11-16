#include <stdio.h>
#include <stdarg.h>

// Formats into a caller-supplied 256-byte buffer.
void FormatBuffer256(char *buffer, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, 0x100, format, args);
    va_end(args);
}
