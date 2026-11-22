// Returns the one-byte flag stored in a global at 0x00b41b2d. What the flag
// means isn't known yet.

// src: GUESS (confidence: low) [0x00b41b2d]
extern unsigned char g_flag_00b41b2d;

// src: GUESS (confidence: low) [0x0046ff10]
unsigned char GetFlag_0046ff10()
{
    return g_flag_00b41b2d;
}
