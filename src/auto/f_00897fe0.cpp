// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: high) [0x00897fe0]
char* GetPtr_00897fe0(char* base)
{
    return base + *(int*)(base + 0x104);
}
