// c5d-cflags: +/Od
// Returns the value at 0x13c when the flag at 0x138 is set, otherwise 0.

// src: GUESS (confidence: low)
struct State_00897420
{
    char m_pad0[0x138];
    // src: GUESS (confidence: low)
    int m_hasValue;
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x00897420]
int GetValue_00897420(const State_00897420* state)
{
    return state->m_hasValue ? state->m_value : 0;
}
