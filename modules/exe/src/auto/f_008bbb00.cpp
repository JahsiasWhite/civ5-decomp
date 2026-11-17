// c5d-model: Gemini 3.8 Flash

struct Entry_008bbb00 {
    int m_val;
    char m_pad[44];
};

// src: EXE [0x03074e20]
extern Entry_008bbb00 g_aEntries_03074e20[1];

// src: GUESS (confidence: high) [0x008bbb00]
int __stdcall GetEntryField_008bbb00(int index, int unused)
{
    return g_aEntries_03074e20[index].m_val;
}
