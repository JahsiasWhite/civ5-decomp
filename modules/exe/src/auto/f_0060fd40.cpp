// src: GUESS (confidence: low)
struct BitStruct_0060fd40 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    unsigned int m_bits : 31;
    unsigned int m_flag : 1;
    int m_18;

    BitStruct_0060fd40& operator=(const BitStruct_0060fd40& src);
};

// src: GUESS (confidence: medium) [0x0060fd40]
BitStruct_0060fd40& BitStruct_0060fd40::operator=(const BitStruct_0060fd40& src) {
    m_00 = src.m_00;
    m_04 = src.m_04;
    m_08 = src.m_08;
    m_0c = src.m_0c;
    m_10 = src.m_10;
    m_bits = src.m_bits;
    m_flag = src.m_flag;
    m_18 = src.m_18;
    return *this;
}
