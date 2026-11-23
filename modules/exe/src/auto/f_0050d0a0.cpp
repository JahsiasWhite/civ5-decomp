// src: GUESS (confidence: low)
struct Vec2_0050d0a0 {
    float x;
    float y;
    Vec2_0050d0a0& operator=(const Vec2_0050d0a0& o) { x = o.x; y = o.y; return *this; }
};

// src: GUESS (confidence: low)
class Transform_0050d0a0 {
public:
    // src: GUESS (confidence: low) [0x0050d0a0]
    Vec2_0050d0a0 Apply(const Vec2_0050d0a0& in);

private:
    char m_pad[0xa8];
    float m_scaleX;
    float m_scaleY;
    float m_padB0;
    float m_offsetX;
    float m_offsetY;
};

Vec2_0050d0a0 Transform_0050d0a0::Apply(const Vec2_0050d0a0& in)
{
    Vec2_0050d0a0 out;
    out.x = m_scaleX * in.x - m_offsetX;
    out.y = m_scaleY * in.y - m_offsetY;
    return out;
}
