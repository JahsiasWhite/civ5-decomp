// Returns one of four values by index (0, 2, 1, 3 map to fields in order
// 0x20, 0x24, 0x28, 0x2c); 0 for any other index.

// src: GUESS (confidence: low)
class Values_0091f7a0
{
public:
    // src: GUESS (confidence: low) [0x0091f7a0]
    int Get(int index) const;

    char m_pad0[0x20];
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
};

int Values_0091f7a0::Get(int index) const
{
    switch (index)
    {
    case 0:
        return m_20;
    case 1:
        return m_28;
    case 2:
        return m_24;
    case 3:
        return m_2c;
    default:
        return 0;
    }
}
