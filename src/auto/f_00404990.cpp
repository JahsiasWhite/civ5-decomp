// Clears the fields at offsets 4 and 0x10.

// src: GUESS (confidence: low)
class PairReset_00404990
{
public:
    // src: GUESS (confidence: low) [0x00404990]
    void Reset();

    int m_00;
    // src: GUESS (confidence: low)
    int m_04;
    int m_08;
    int m_0c;
    // src: GUESS (confidence: low)
    int m_10;
};

void PairReset_00404990::Reset()
{
    m_04 = 0;
    m_10 = 0;
}
