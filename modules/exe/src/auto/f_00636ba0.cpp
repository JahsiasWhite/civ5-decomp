// Returns the opposing layer for side 0 or 1; any other side gets layer 0.

// src: GUESS (confidence: low)
struct Layer_00520230
{
    char m_data[0x2d60];
};

// src: GUESS (confidence: low)
class Layers_00520230
{
public:
    // src: GUESS (confidence: low) [0x00520230]
    Layer_00520230* GetOpponentLayer(int side);

    char m_pad0[0x270];
    // src: GUESS (confidence: low)
    Layer_00520230 m_layers[2];
};

Layer_00520230* Layers_00520230::GetOpponentLayer(int side)
{
    int index = (side < 2) ? (side ^ 1) : 0;
    return &m_layers[index];
}
