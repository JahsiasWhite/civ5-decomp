// True when the count that goes with the object's type is positive: the
// short at 0x7a for type 4, the int at 0x78 for type 3, otherwise the short
// at 0x76.

// src: GUESS (confidence: low)
struct Counted_008ec7d0
{
    // src: GUESS (confidence: low) [0x008ec7d0]
    bool HasCount() const;

    // src: GUESS (confidence: low)
    int m_type;
    char m_pad4[0x76 - 4];
    // src: GUESS (confidence: low)
    short m_count16;
    union
    {
        // src: GUESS (confidence: low)
        int m_count32;
        struct
        {
            short m_lowPart;
            // src: GUESS (confidence: low)
            short m_altCount16;
        };
    };
};

bool Counted_008ec7d0::HasCount() const
{
    switch (m_type)
    {
    case 2:
        return m_count16 > 0;
    case 3:
        return m_count32 > 0;
    case 4:
        return m_altCount16 > 0;
    default:
        return m_count16 > 0;
    }
}
