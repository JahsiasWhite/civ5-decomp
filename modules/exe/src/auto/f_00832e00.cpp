// src: GUESS (confidence: low)
struct Entry32_008ccd80 {
    int m_00;
    int m_04;
    short m_08;
    short m_0a;
    int m_0c;
    int m_10;
    int m_14;
    unsigned short m_18;
    unsigned short m_1a;
    int m_1c;
};

// src: GUESS (confidence: low) [0x008ccd80]
struct CmdQueue_008ccd80 {
    int m_00;
    int m_04;
    int m_08;
    int m_count;
    int m_10;
    Entry32_008ccd80* m_entries;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_dataPtr;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    unsigned short m_dataLen;

    // src: GUESS (confidence: low) [0x008ccd80]
    void PushEntry(int a0, int a1, short a2);
};

// src: GUESS (confidence: low) [0x008ccd80]
void CmdQueue_008ccd80::PushEntry(int a0, int a1, short a2) {
    m_entries[m_count].m_04 = -1;
    m_entries[m_count].m_00 = a0;
    m_entries[m_count].m_08 = a2;
    m_entries[m_count].m_0c = 0;
    m_entries[m_count].m_14 = m_dataPtr;
    m_entries[m_count].m_18 = m_dataLen;
    m_entries[m_count].m_10 = a1;
    ++m_count;
}
