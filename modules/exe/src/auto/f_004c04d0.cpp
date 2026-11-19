// True when the point is on the map; the x range isn't checked when the map
// wraps horizontally.

// src: GUESS (confidence: low)
struct Point_006d0d20
{
    int x;
    int y;
};

// src: GUESS (confidence: low)
class Map_006d0d20
{
public:
    // src: GUESS (confidence: low) [0x006d0d20]
    bool Contains(const Point_006d0d20* point) const;

    char m_pad0[0x94];
    // src: GUESS (confidence: low)
    int m_width;
    // src: GUESS (confidence: low)
    int m_height;
    // src: GUESS (confidence: low)
    bool m_wrapX;
};

bool Map_006d0d20::Contains(const Point_006d0d20* point) const
{
    if (!m_wrapX && (point->x < 0 || point->x >= m_width))
        return false;
    if (point->y < 0 || point->y >= m_height)
        return false;
    return true;
}
