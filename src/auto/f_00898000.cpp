// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: high) [0x00898000]
int GetByteField_00898000(const char* base)
{
    return *(int*)(base + 0x108) & 0xff;
}
