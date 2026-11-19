// Adds the same amount to both components of a 2-float field.

// src: GUESS (confidence: low)
class Owner_0042c510
{
public:
    // src: GUESS (confidence: low) [0x0042c510]
    void AddToBoth(float amount);

    char m_pad0[0x5e88];
    // src: GUESS (confidence: low)
    float m_x;
    // src: GUESS (confidence: low)
    float m_y;
};

void Owner_0042c510::AddToBoth(float amount)
{
    m_x += amount;
    m_y += amount;
}
