// Resolves a self-relative pointer: the global holds an offset from its own address.

// src: GUESS (confidence: low)
extern int g_selfRelOffset_009fbbbc;

// src: GUESS (confidence: low) [0x0047dfb0]
void* GetSelfRelPtr_009fbbbc()
{
    return reinterpret_cast<char*>(&g_selfRelOffset_009fbbbc) + g_selfRelOffset_009fbbbc;
}
