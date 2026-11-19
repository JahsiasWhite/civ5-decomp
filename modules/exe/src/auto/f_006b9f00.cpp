// True when the value is one of the bytes in the global list.

// src: GUESS (confidence: low) [0x02dd1e80]
extern signed char* g_values_02dd1e80;
// src: GUESS (confidence: low) [0x02dd1e84]
extern unsigned int g_valueCount_02dd1e84;

// src: GUESS (confidence: low) [0x0047a450]
bool __stdcall ContainsValue_0047a450(int value)
{
    for (unsigned int i = 0; i < g_valueCount_02dd1e84; ++i)
    {
        if (value == g_values_02dd1e80[i])
            return true;
    }
    return false;
}
