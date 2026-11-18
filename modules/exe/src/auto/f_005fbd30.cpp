// Returns the cell at the coordinate, or the shared "none" cell when the
// coordinate is off the grid.

// src: GUESS (confidence: low)
struct Cell_005fbd30
{
    char m_data[0x188];
};

// src: GUESS (confidence: low)
struct Coord_005fbd30
{
    unsigned int x;
    unsigned int y;
};

// src: GUESS (confidence: low)
class Grid_005fbd30
{
public:
    // src: GUESS (confidence: low) [0x005fbd30]
    Cell_005fbd30* GetCell(const Coord_005fbd30* coord);

    char m_pad0[0x44];
    // src: GUESS (confidence: low)
    unsigned int m_width;
    // src: GUESS (confidence: low)
    unsigned int m_height;
    // src: GUESS (confidence: low)
    Cell_005fbd30 m_cells[0x2000];
    char m_pad[0xc40268 - 0x4c - 0x2000 * 0x188];
    // src: GUESS (confidence: low)
    Cell_005fbd30 m_none;
};

Cell_005fbd30* Grid_005fbd30::GetCell(const Coord_005fbd30* coord)
{
    if (coord->x < m_width && coord->y < m_height)
        return &m_cells[coord->y * m_width + coord->x];
    return &m_none;
}
