// src: GUESS (confidence: low) [0x00d90fbc]
extern int g_wrapMode_00d90fbc;

// src: GUESS (confidence: medium)
struct Coord_00548980 {
    Coord_00548980(int x, int y) : m_x(x), m_y(y) {}
    Coord_00548980(const Coord_00548980& o) : m_x(o.m_x), m_y(o.m_y) {}
    int m_x;
    int m_y;
};

// src: GUESS (confidence: medium) [0x00548980]
struct MapGrid_00548980 {
    int m_pad[0x28];
    // src: GUESS (confidence: high)
    int m_width;

    // src: GUESS (confidence: medium) [0x00548980]
    Coord_00548980 WrapCoord(int x, int y) const;
};

// src: GUESS (confidence: medium) [0x00548980]
Coord_00548980 MapGrid_00548980::WrapCoord(int x, int y) const {
    if (g_wrapMode_00d90fbc == 1) {
        x = (x + m_width * 100) % m_width;
    }
    return Coord_00548980(x, y);
}
