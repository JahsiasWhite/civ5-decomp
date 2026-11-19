// True when the GUID is all zeros.

#include <windows.h>

// src: GUESS (confidence: low) [0x008304d0]
bool IsNullGuid_008304d0(const GUID* guid)
{
    return guid->Data1 == 0 && guid->Data2 == 0 && guid->Data3 == 0
        && ((const unsigned long*)guid->Data4)[0] == 0 && ((const unsigned long*)guid->Data4)[1] == 0;
}
