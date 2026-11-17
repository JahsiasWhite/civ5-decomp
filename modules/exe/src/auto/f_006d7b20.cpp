// Returns whether a global one-byte flag is clear.

// src: GUESS (confidence: low)
extern bool g_bFlag_02dd2f5e;

// src: GUESS (confidence: low) [0x006d7b20]
bool IsFlagClear_02dd2f5e()
{
    return !g_bFlag_02dd2f5e;
}
