#include <string.h>

// strlen that treats a null pointer as an empty string.
// src: GUESS (confidence: high) [0x005d7380]
unsigned int SafeStrlen_005d7380(const char* text)
{
    if (text)
        return strlen(text);
    return 0;
}
