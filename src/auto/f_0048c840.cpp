// Resolves a self-relative pointer: the global holds an offset from its own address.

// src: GUESS (confidence: low)
extern int g_selfRelOffset_009ef94c;

// src: GUESS (confidence: low) [0x0048c840]
void* GetSelfRelPtr_009ef94c()
{
    return reinterpret_cast<char*>(&g_selfRelOffset_009ef94c) + g_selfRelOffset_009ef94c;
}
