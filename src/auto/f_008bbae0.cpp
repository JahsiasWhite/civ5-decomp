// c5d-model: Gemini 3.8 Flash

struct Entry_008bbae0 {
    int m_val;
    char m_pad[44];
};

// src: EXE [0x03020860]
extern Entry_008bbae0 g_aEntries_03020860[1];

// src: GUESS (confidence: high) [0x008bbae0]
int __stdcall GetEntryField_008bbae0(int index, int unused)
{
    return g_aEntries_03020860[index].m_val;
}
