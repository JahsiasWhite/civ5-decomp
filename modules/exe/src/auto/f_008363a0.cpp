// src: GUESS (confidence: low) [0x008363a0]
struct Unk_008363a0
{
    unsigned int m_arr[8];  // +0x00
    int m_f20;              // +0x20
    int m_f24;              // +0x24
    int m_f28;              // +0x28

    // src: GUESS (confidence: high) [0x008363a0]
    Unk_008363a0();
};

// src: GUESS (confidence: high) [0x008363a0]
Unk_008363a0::Unk_008363a0()
{
    m_f20 = 0;
    m_f24 = 0;
    m_f28 = 0;
    for (int i = 0; i < 8; ++i)
        m_arr[i] = 0x01010101;
}
