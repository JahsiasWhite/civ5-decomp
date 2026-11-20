// src: GUESS (confidence: low) [0x02ea1430]
extern int g_flagA_004b5060;
// src: GUESS (confidence: low) [0x02cdad9c]
extern int g_valB_004b5060;
// src: GUESS (confidence: low) [0x00c16499]
extern bool g_flagC_004b5060;

// src: GUESS (confidence: high) [0x004b5060]
bool CheckGlobals_004b5060()
{
    if (g_flagA_004b5060)
        return (g_valB_004b5060 >= 10 && g_flagC_004b5060);
    return g_flagC_004b5060;
}
