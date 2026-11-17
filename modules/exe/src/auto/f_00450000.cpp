// Constructor that clears the field at offset 4 and leaves the first one unset.

// src: GUESS (confidence: low)
class SecondFieldZero_00450000
{
public:
    // src: GUESS (confidence: low) [0x00450000]
    SecondFieldZero_00450000();

    // src: GUESS (confidence: low)
    int m_first;
    // src: GUESS (confidence: low)
    int m_second;
};

SecondFieldZero_00450000::SecondFieldZero_00450000()
    : m_second(0)
{
}
