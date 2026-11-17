// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x005e3c20]
struct State_005e3c20 {
    char m_pad[0x97cc];
    char m_flag;
    char SetFlag(char val);
};

// src: GUESS (confidence: high) [0x005e3c20]
char State_005e3c20::SetFlag(char val)
{
    char old = m_flag;
    m_flag = val;
    return old;
}
