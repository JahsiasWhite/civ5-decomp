// Returns the file-name part of a path (after the last separator). The
// second search passes '//', a two-character literal, as in the original
// code.

#include <string.h>

// src: GUESS (confidence: low) [0x008fb000]
const char* GetFileName_008fb000(const char* path)
{
    if (path)
    {
        const char* separator = strrchr(path, '\\');
        if (separator)
            return separator + 1;
        separator = strrchr(path, '//');
        if (separator)
            return separator + 1;
    }
    return path;
}
