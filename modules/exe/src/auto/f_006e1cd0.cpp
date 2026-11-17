// True when the 16-bit id at offset 2 is set (not -1) and bit 0x100 is
// set.

// src: GUESS (confidence: low)
class Record_006e1cd0
{
public:
    // src: GUESS (confidence: low) [0x006e1cd0]
    int IsSetAndFlagSet() const;

    short m_pad0;
    // src: GUESS (confidence: low)
    short m_id;
};

int Record_006e1cd0::IsSetAndFlagSet() const
{
    if (m_id != -1 && (m_id & 0x100))
        return 1;
    return 0;
}
