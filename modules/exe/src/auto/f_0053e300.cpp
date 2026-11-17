// Clears the fields at offsets 0x14 and 8.

// src: GUESS (confidence: low)
class PairReset_0053e300
{
public:
    // src: GUESS (confidence: low) [0x0053e300]
    void Reset();

    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    int m_08;
    int m_0c;
    int m_10;
    // src: GUESS (confidence: low)
    int m_14;
};

void PairReset_0053e300::Reset()
{
    m_14 = 0;
    m_08 = 0;
}
