// Constructs a pair of packed cells, each a value plus a word split into
// 20-, 4- and 8-bit fields, all cleared.

// src: GUESS (confidence: low)
struct PackedCell_00673070
{
    PackedCell_00673070()
    {
        m_mid = 0;
        m_high = 0;
        m_value = 0;
        m_low = 0;
    }

    // src: GUESS (confidence: low)
    int m_value;
    // src: GUESS (confidence: low)
    unsigned int m_low : 20;
    // src: GUESS (confidence: low)
    unsigned int m_mid : 4;
    // src: GUESS (confidence: low)
    unsigned int m_high : 8;
};

// src: GUESS (confidence: low)
struct PackedCellPair_00673070
{
    // src: GUESS (confidence: low) [0x00673070]
    PackedCellPair_00673070();

    // src: GUESS (confidence: low)
    PackedCell_00673070 m_first;
    // src: GUESS (confidence: low)
    PackedCell_00673070 m_second;
};

PackedCellPair_00673070::PackedCellPair_00673070()
{
}
