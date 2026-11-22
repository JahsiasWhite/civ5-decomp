// src: GUESS (confidence: low) [0x007bdca0]
extern int g_val_00b29dac;

void SetClamped_007bdca0(int val)
{
    if (val < 0)
        val = -1;
    g_val_00b29dac = val;
}
