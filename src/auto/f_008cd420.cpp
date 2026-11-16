// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x008cd420]
struct ArrayHost_008cd420 {
    char* m_base;
    int m_index;
    void SetElementValue(int val);
};

// src: GUESS (confidence: high) [0x008cd420]
void ArrayHost_008cd420::SetElementValue(int val)
{
    *(int*)(m_base + (m_index << 7) + 0x74) = val;
}
