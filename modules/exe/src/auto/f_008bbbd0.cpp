// c5d-model: Gemini 3.8 Flash

// src: EXE [0x02e49f68]
extern int g_aInts_02e49f68[1];

// src: GUESS (confidence: high) [0x008bbbd0]
int __stdcall CalcScaledValue_008bbbd0(int index, int factor, int unused)
{
    return g_aInts_02e49f68[index] * factor;
}
