// Returns the cell at a (column, layer) coordinate: the layer is the low
// byte of the second component.

// src: GUESS (confidence: low)
struct Coord_00787ff0
{
    // src: GUESS (confidence: low)
    short m_column;
    // src: GUESS (confidence: low)
    short m_layer;
};

// src: GUESS (confidence: low)
struct Cell_00787ff0
{
    char m_data[0x158];
};

// src: GUESS (confidence: low)
struct Layer_00787ff0
{
    // src: GUESS (confidence: low)
    Cell_00787ff0 m_cells[33];
    char m_pad[0x2d60 - 33 * 0x158];
};

// src: GUESS (confidence: low)
class Grid_00787ff0
{
public:
    // src: GUESS (confidence: low) [0x00787ff0]
    Cell_00787ff0* GetCell(const Coord_00787ff0* coord);

    char m_pad0[0x2c4];
    // src: GUESS (confidence: low)
    Layer_00787ff0 m_layers[1];
};

Cell_00787ff0* Grid_00787ff0::GetCell(const Coord_00787ff0* coord)
{
    return &m_layers[coord->m_layer & 0xff].m_cells[coord->m_column];
}
