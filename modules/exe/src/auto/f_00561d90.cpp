// Advances to the next step, staying put when stepping is off or the limit
// is reached; resets the step's progress.

// src: GUESS (confidence: low)
class Stepper_006d4750
{
public:
    // src: GUESS (confidence: low) [0x006d4750]
    void Next(int unused);

    char m_pad0[0x13c4];
    // src: GUESS (confidence: low)
    unsigned int m_step;
    // src: GUESS (confidence: low)
    int m_progress;
    char m_pad13cc[0x13d4 - 0x13cc];
    // src: GUESS (confidence: low)
    int m_enabled;
    // src: GUESS (confidence: low)
    unsigned int* m_limit;
};

void Stepper_006d4750::Next(int unused)
{
    ++m_step;
    if (!m_enabled || !m_limit || m_step > *m_limit)
        --m_step;
    m_progress = 0;
}
