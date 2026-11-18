// src: GUESS (confidence: medium) [0x00829ca0]
struct MemoryRange_00829ca0 {
    // src: GUESS (confidence: low)
    int m_reserved[4];
    // src: GUESS (confidence: medium)
    unsigned int m_base;
    // src: GUESS (confidence: low)
    int m_pad14;
    // src: GUESS (confidence: medium)
    unsigned int m_size;

    // src: GUESS (confidence: medium) [0x00829ca0]
    int Contains(unsigned int addr) const;
};

// src: GUESS (confidence: medium) [0x00829ca0]
int MemoryRange_00829ca0::Contains(unsigned int addr) const {
    if (m_base != 0 && addr >= m_base && m_size + m_base > addr) {
        return 1;
    }
    return 0;
}
