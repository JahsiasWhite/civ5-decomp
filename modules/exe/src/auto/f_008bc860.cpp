// c5d-model: Gemini 3.8 Flash

struct Block_008bc860 {
    int m_val;
    char m_pad[0x394];
};

// src: EXE [0x04170f14]
extern Block_008bc860 g_aBlocks_04170f14[1];

// src: GUESS (confidence: high) [0x008bc860]
int __stdcall GetBlockVal_008bc860(int index)
{
    return g_aBlocks_04170f14[index].m_val;
}
