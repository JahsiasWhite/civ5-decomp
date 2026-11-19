// True when the 16-bit id at offset 2 is set (not -1) and bit 0x100 is
// clear.

// src: GUESS (confidence: low)
class Record_006d9a50
{
public:
    // src: GUESS (confidence: low) [0x006d9a50]
    int IsSetAndFlagClear() const;

    short m_pad0;
    // src: GUESS (confidence: low)
    short m_id;
};

int Record_006d9a50::IsSetAndFlagClear() const
{
    if (m_id != -1 && !(m_id & 0x100))
        return 1;
    return 0;
}
