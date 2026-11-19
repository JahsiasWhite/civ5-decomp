// Resets the settings to their defaults (a 60000 ms timeout and a 1000 limit).

// src: GUESS (confidence: low)
class Settings_0053ab50
{
public:
    // src: GUESS (confidence: low) [0x0053ab50]
    void Reset();

    // src: GUESS (confidence: low)
    int m_timeoutMs;
    int m_04;
    int m_08;
    int m_0c;
    // src: GUESS (confidence: low)
    int m_index;
    // src: GUESS (confidence: low)
    int m_limit;
    int m_18;
    int m_1c;
    int m_20;
};

void Settings_0053ab50::Reset()
{
    m_timeoutMs = 60000;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_index = -1;
    m_limit = 1000;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
}
