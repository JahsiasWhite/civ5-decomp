// src: GUESS (confidence: medium)
struct Coord_004b68e0 {
    Coord_004b68e0() {}
    Coord_004b68e0(const Coord_004b68e0& o) : m_x(o.m_x), m_y(o.m_y) {}
    int m_x;
    int m_y;
};

// src: GUESS (confidence: medium) [0x004b68e0]
struct MapGrid_004b68e0 {
    int m_pad0[0x25];
    // src: GUESS (confidence: high)
    int m_width;
    int m_pad98;
    // src: GUESS (confidence: high)
    bool m_wrapX;

    // src: GUESS (confidence: medium) [0x004b68e0]
    Coord_004b68e0 WrapCoord(int x, int y) const;
};

// src: GUESS (confidence: medium) [0x004b68e0]
Coord_004b68e0 MapGrid_004b68e0::WrapCoord(int x, int y) const {
    if (m_wrapX) {
        while (x < 0) {
            x += m_width;
        }
        x %= m_width;
    }
    Coord_004b68e0 c;
    c.m_x = x;
    c.m_y = y;
    return c;
}
