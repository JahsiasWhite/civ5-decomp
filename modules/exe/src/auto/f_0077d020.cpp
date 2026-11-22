// src: GUESS (confidence: high) [0x0077d020]
#include <stdarg.h>
#include <stdio.h>

struct Sub77d020 {
    int pos;
    int pad;
    char buf[0x80000];
};

struct LogBuf77d020 {
    unsigned char pad[0x8dc];
    Sub77d020 sub;
};

void __cdecl f_0077d020(LogBuf77d020** p, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    Sub77d020* s = &(*p)->sub;
    int n = vsprintf_s(s->buf + s->pos, 0x80000 - s->pos, fmt, args);
    s->pos += n + 1;
    va_end(args);
}
