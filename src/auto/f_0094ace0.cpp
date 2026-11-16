// c5d-model: Gemini 3.8 Flash

// src: EXE [0x00b53f48]
extern int g_aTable30_00b53f48[31];

// src: GUESS (confidence: high) [0x0094ace0]
int LookupTableEntry_0094ace0(unsigned int idx)
{
    if (idx <= 30)
        return g_aTable30_00b53f48[idx];
    return 0;
}
