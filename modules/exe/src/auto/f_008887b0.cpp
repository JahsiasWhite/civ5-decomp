// Constructs the record: no id, all six floats zero, no flags.

// src: GUESS (confidence: low)
struct Record_00922bb0
{
    // src: GUESS (confidence: low) [0x00922bb0]
    Record_00922bb0();

    int m_id;
    float m_values[6];
    int m_flags;
};

Record_00922bb0::Record_00922bb0()
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
