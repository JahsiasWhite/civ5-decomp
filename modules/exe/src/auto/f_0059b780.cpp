// Clears the "outside" flag when the box overlaps this one.

// src: GUESS (confidence: low)
struct Box_005962a0
{
    float minX;
    float minY;
    float maxX;
    float maxY;
};

// src: GUESS (confidence: low)
class Region_005962a0
{
public:
    // src: GUESS (confidence: low) [0x005962a0]
    void TestOverlap(const Box_005962a0* box);

    // src: GUESS (confidence: low)
    bool m_outside;
    // src: GUESS (confidence: low)
    Box_005962a0 m_box;
};

void Region_005962a0::TestOverlap(const Box_005962a0* box)
{
    if (box->maxX >= m_box.minX && m_box.maxX >= box->minX
        && box->maxY >= m_box.minY && m_box.maxY >= box->minY)
        m_outside = false;
}
