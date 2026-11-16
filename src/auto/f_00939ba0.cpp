// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x00939ba0]
struct Node_00939ba0 {
    char m_pad[8];
    int m_field;
};

// src: GUESS (confidence: high) [0x00939ba0]
int GetNodeValue_00939ba0(const Node_00939ba0* node)
{
    if (!node)
        return 1;
    return node->m_field;
}
