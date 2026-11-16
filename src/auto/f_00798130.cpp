// Resolves a self-relative pointer: the global holds an offset from its own address.

// src: GUESS (confidence: low)
extern int g_selfRelOffset_00a03458;

// src: GUESS (confidence: low) [0x00798130]
void* GetSelfRelPtr_00a03458()
{
    return reinterpret_cast<char*>(&g_selfRelOffset_00a03458) + g_selfRelOffset_00a03458;
}
