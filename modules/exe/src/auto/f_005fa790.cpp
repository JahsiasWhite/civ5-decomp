// src: GUESS (confidence: low)
struct Entry_005fa790 {
    int m_pad00;
    unsigned char m_key;
    char m_pad05[0x43];
};

// src: GUESS (confidence: low)
class Table_005fa790 {
public:
    // src: GUESS (confidence: low) [0x005fa790]
    Entry_005fa790* FindEntry(unsigned int key);

private:
    char m_pad[0x1c];
    Entry_005fa790* m_pEntries;
    unsigned int m_nCount;
};

Entry_005fa790* Table_005fa790::FindEntry(unsigned int key)
{
    for (unsigned int i = 0; i < m_nCount; ++i) {
        if ((unsigned int)m_pEntries[i].m_key == key) {
            return &m_pEntries[i];
        }
    }
    return m_pEntries;
}
