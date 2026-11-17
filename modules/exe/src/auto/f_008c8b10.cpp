// c5d-model: Gemini 3.8 Flash

// src: EXE [0x05f54e84]
extern int g_iVarA_05f54e84;
// src: EXE [0x05f54e88]
extern int g_iVarB_05f54e88;

// src: GUESS (confidence: high) [0x008c8b10]
void SetTwoGlobals_008c8b10(int a, int b)
{
    g_iVarA_05f54e84 = a;
    g_iVarB_05f54e88 = b;
}
