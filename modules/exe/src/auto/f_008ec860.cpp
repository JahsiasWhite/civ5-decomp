// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x008ec860]
struct Item_008ec860 {
    int m_type;
    char m_pad[0x72];
    short m_val;
    bool Check() const;
};

// src: GUESS (confidence: high) [0x008ec860]
bool Item_008ec860::Check() const
{
    if (m_type == 4)
        return m_val != 0;
    return false;
}
