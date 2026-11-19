// c5d-model: Gemini 3.8 Flash

// src: EXE [0x00cb3824]
extern int g_iGlobalA_00cb3824;
// src: EXE [0x00cb38b4]
extern int g_iGlobalB_00cb38b4;

// src: GUESS (confidence: high) [0x009bbe70]
void SetTwoGlobals_009bbe70(int a, int b)
{
    g_iGlobalA_00cb3824 = a;
    g_iGlobalB_00cb38b4 = b;
}
