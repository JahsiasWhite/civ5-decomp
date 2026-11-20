#include <string.h>

// src: LIB [0x0044b860]
char* CopyChars_0044b860(const char* first, const char* last, char* dst)
{
    int count = last - first;
    char* ret = dst + count;
    if (count > 0)
        memmove_s(dst, count, first, count);
    return ret;
}
