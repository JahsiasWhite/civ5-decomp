// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x006b02f0]
struct QueueContainer_006b02f0 {
    int m_pad0;
    int m_pad1;
    char* m_start;
    char* m_end;
    bool HasItems() const;
};

// src: GUESS (confidence: high) [0x006b02f0]
bool QueueContainer_006b02f0::HasItems() const
{
    int count = (m_end - m_start);
    return (unsigned int)(count >> 2) > 0;
}
