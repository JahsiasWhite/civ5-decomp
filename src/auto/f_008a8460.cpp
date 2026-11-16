// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: EXE [0x02de1ea0]
extern int g_iGlobalCounter_02de1ea0;

// src: GUESS (confidence: high) [0x008a8460]
void IncCounter_008a8460()
{
    g_iGlobalCounter_02de1ea0++;
}
