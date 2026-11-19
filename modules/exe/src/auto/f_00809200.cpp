// c5d-cflags: +/Od
// Returns the low byte of the flags word at 0x108.

// src: GUESS (confidence: low)
struct State_008a3170
{
    char m_pad0[0x108];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

// src: GUESS (confidence: low) [0x008a3170]
int GetLowFlags_008a3170(void* handle)
{
    int result = 0;
    State_008a3170* state = (State_008a3170*)handle;
    result = state->m_flags & 0xff;
    return result;
}
