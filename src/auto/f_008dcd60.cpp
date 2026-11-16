// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: high) [0x008dcd60]
class Timer_008dcd60 {
public:
    virtual void D0(); virtual void D1(); virtual void D2(); virtual void D3(); virtual void D4();
    virtual double GetTime();
    int m_pad[3];
    double m_start;
    double m_elapsed;
    void Update();
};

// src: GUESS (confidence: high) [0x008dcd60]
void Timer_008dcd60::Update()
{
    m_start = GetTime() - m_elapsed;
}
