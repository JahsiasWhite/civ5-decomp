// src: GUESS (confidence: low) [0x007b3f80]
extern unsigned int g_Mask_007b3f80;
extern unsigned int g_Table1_007b3f80[];
extern unsigned int g_Table2_007b3f80[];

// src: GUESS (confidence: low) [0x007b3f80]
unsigned int Blend_007b3f80(unsigned int idx1, unsigned int idx2) {
    unsigned int m = g_Mask_007b3f80;
    return (g_Table1_007b3f80[idx1] & ~m) | (g_Table2_007b3f80[idx2] & m);
}
