// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: high) [0x0089ebc0]
struct TargetObj_0089ebc0 {
    char m_pad[0x32c];
    int m_field;
};

// src: GUESS (confidence: high) [0x0089ebc0]
void ClearField_0089ebc0(TargetObj_0089ebc0* p)
{
    p->m_field = 0;
}
