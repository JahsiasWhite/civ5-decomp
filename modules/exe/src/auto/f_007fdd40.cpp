// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: EXE [0x02de1e20]
extern int g_iGlobal_02de1e20;

// src: GUESS (confidence: high) [0x00897cb0]
void SetGlobalFromHost_00897cb0(const char* base)
{
    g_iGlobal_02de1e20 = *(int*)(base + 0x120);
}
