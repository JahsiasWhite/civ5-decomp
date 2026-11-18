// Sets the two scale factors, leaving either unchanged when given 0.

// src: GUESS (confidence: low)
class Scaled_008e4960
{
public:
    // src: GUESS (confidence: low) [0x008e4960]
    void SetScale(float x, float y);

    char m_pad0[0xd0];
    // src: GUESS (confidence: low)
    float m_scaleX;
    // src: GUESS (confidence: low)
    float m_scaleY;
};

void Scaled_008e4960::SetScale(float x, float y)
{
    if (x != 0.0f)
        m_scaleX = x;
    if (y != 0.0f)
        m_scaleY = y;
}
