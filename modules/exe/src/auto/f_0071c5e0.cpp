// True when both readiness flags of the player's layer are set.

// src: GUESS (confidence: low)
struct Layer_0071c5e0
{
    char m_pad0[0x2d3c];
    // src: GUESS (confidence: low)
    bool m_ready;
    // src: GUESS (confidence: low)
    bool m_active;
    char m_pad2d3e[0x2d60 - 0x2d3e];
};

// src: GUESS (confidence: low)
class Layers_0071c5e0
{
public:
    // src: GUESS (confidence: low) [0x0071c5e0]
    int IsReady(int player) const;

    char m_pad0[0x270];
    // src: GUESS (confidence: low)
    Layer_0071c5e0 m_layers[1];
};

int Layers_0071c5e0::IsReady(int player) const
{
    const Layer_0071c5e0& layer = m_layers[player];
    if (layer.m_active && layer.m_ready)
        return 1;
    return 0;
}
