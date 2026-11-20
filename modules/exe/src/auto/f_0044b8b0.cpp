#include <string.h>

// src: LIB [0x0044b8b0]
char* __stdcall MoveChars_0044b8b0(const char* first, const char* last, char* dst)
{
    size_t count = last - first;
    char* ret = dst + count;
    if (count)
        memmove_s(dst, count, first, count);
    return ret;
}
