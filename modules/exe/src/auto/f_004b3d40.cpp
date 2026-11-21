// src: GUESS (confidence: low) [0x00c16534]
extern int g_srcA_00c16534;
// src: GUESS (confidence: low) [0x00c16538]
extern char g_srcB_00c16538;
// src: GUESS (confidence: low) [0x00c1653c]
extern int g_srcC_00c1653c;
// src: GUESS (confidence: low) [0x00c27220]
extern int g_srcD_00c27220;
// src: GUESS (confidence: low) [0x00c27224]
extern int g_srcE_00c27224;

// src: GUESS (confidence: low) [0x00b4f47c]
extern int g_dstA_00b4f47c;
// src: GUESS (confidence: low) [0x00b4f478]
extern char g_dstB_00b4f478;
// src: GUESS (confidence: low) [0x00b4f474]
extern int g_dstC_00b4f474;
// src: EXE [0x00b4f544]
extern int g_valA_0076fb50;
// src: EXE [0x00b4f548]
extern int g_valB_0076fb50;

// src: GUESS (confidence: medium) [0x004b3d40]
void SyncGlobals_004b3d40()
{
    g_dstA_00b4f47c = g_srcA_00c16534;
    g_dstB_00b4f478 = g_srcB_00c16538;
    g_dstC_00b4f474 = g_srcC_00c1653c;
    g_valA_0076fb50 = g_srcD_00c27220;
    g_valB_0076fb50 = g_srcE_00c27224;
}
