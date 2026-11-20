#include <string.h>

// src: LIB [0x0044b900]
char* MoveBackwardBytes_0044b900(const char* first, const char* last, char* dest)
{
    int n = (int)(last - first);
    char* d = dest - n;
    if (n > 0)
        memmove_s(d, n, first, n);
    return d;
}
