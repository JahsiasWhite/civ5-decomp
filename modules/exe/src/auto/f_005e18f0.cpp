#include <string.h>

// src: LIB [0x005e18f0]
char* __stdcall MoveChars_005e18f0(const char* first, const char* last, char* dst)
{
    size_t count = last - first;
    char* ret = dst + count;
    if (count)
        memmove_s(dst, count, first, count);
    return ret;
}
