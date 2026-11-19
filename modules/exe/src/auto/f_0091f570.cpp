// c5d-model: Gemini 3.8 Flash

struct Object_009bc190 {
    char m_pad[0x40];
    int m_flags;
    char m_pad2[0x60 - 0x44];
    float m_val;
};

// src: GUESS (confidence: high) [0x009bc190]
void SetObjectFloat_009bc190(Object_009bc190* obj, float val)
{
    obj->m_flags |= 2;
    obj->m_val = val;
}
