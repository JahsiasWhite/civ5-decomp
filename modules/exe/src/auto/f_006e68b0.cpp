// Stores the value only when it's greater than the minimum held in a global
// (0 in the shipped exe).

// src: GUESS (confidence: low) [0x00a0b4ec]
extern float g_minPositive_00a0b4ec;

// src: GUESS (confidence: low)
class Owner_006e68b0
{
public:
    // src: GUESS (confidence: low) [0x006e68b0]
    void SetIfAboveMin(float value);

    char m_pad0[0xf4];
    // src: GUESS (confidence: low)
    float m_value;
};

void Owner_006e68b0::SetIfAboveMin(float value)
{
    if (value > g_minPositive_00a0b4ec)
        m_value = value;
}
