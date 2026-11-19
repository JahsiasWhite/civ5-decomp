// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x00833780]
struct Comparable_00833780 {
    int m_val;
    bool Equal(const Comparable_00833780* other) const;
};

// src: GUESS (confidence: high) [0x00833780]
bool Comparable_00833780::Equal(const Comparable_00833780* other) const
{
    return m_val == other->m_val;
}
