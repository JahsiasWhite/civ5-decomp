// src: EXE [0x10071580]
#include <string.h>

// src: GUESS (confidence: low)
int __stdcall ClassifyNumberString_10071580(const char* szStr, unsigned int uiLen) {
    bool bHasDigit = false;
    bool bHasDot = false;
    if (szStr == 0 || uiLen <= 0 || strncmp(szStr, "NULL", 4) == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < uiLen; ++i) {
        char c = szStr[i];
        if (i == 0 && c == '-') {
            return 1;
        }
        if ((unsigned char)(c - '0') <= 9) {
            bHasDigit = true;
        } else {
            if (c != '.' || bHasDot || i >= uiLen || szStr[i + 1] < '0' || szStr[i + 1] > '9') {
                return 1;
            }
            bHasDot = true;
        }
    }
    if (bHasDot) {
        return 3;
    }
    if (bHasDigit) {
        return 2;
    }
    return -1;
}
