// True when the point lies inside the grid.

// src: GUESS (confidence: low)
struct Point_0062f0d0
{
    int x;
    int y;
};

// src: GUESS (confidence: low)
class Grid_0062f0d0
{
public:
    // src: GUESS (confidence: low) [0x0062f0d0]
    bool Contains(const Point_0062f0d0* point) const;

    char m_pad0[0x94];
    // src: GUESS (confidence: low)
    int m_width;
    // src: GUESS (confidence: low)
    int m_height;
};

bool Grid_0062f0d0::Contains(const Point_0062f0d0* point) const
{
    if (point->x < 0 || point->x >= m_width)
        return false;
    if (point->y < 0 || point->y >= m_height)
        return false;
    return true;
}
