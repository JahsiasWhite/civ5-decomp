// Resets the record: no id, all six floats zero, no flags.

// src: GUESS (confidence: low)
class Record_00922a90
{
public:
    // src: GUESS (confidence: low) [0x00922a90]
    void Reset();

    int m_id;
    float m_values[6];
    int m_flags;
};

void Record_00922a90::Reset()
{
    m_id = 0;
    m_values[0] = 0.0f;
    m_values[1] = 0.0f;
    m_values[2] = 0.0f;
    m_values[3] = 0.0f;
    m_values[4] = 0.0f;
    m_values[5] = 0.0f;
    m_flags = 0;
}
