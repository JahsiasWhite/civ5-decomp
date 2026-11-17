// c5d-model: Gemini 3.8 Flash

struct Node_0094f2f0 {
    char m_pad[4];
    int m_val;
};

// src: GUESS (confidence: high) [0x0094f2f0]
int CheckNodeValue_0094f2f0(const Node_0094f2f0* node)
{
    if (!node)
        return 0;
    return node->m_val > 0;
}
