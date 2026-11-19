// c5d-cflags: +/Od
// Returns flag 0x100 of the flags word at 0x108.

// src: GUESS (confidence: low)
struct State_008a31a0
{
    char m_pad0[0x108];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

// src: GUESS (confidence: low) [0x008a31a0]
int GetFlag100_008a31a0(void* handle)
{
    int flag = 0;
    State_008a31a0* s = (State_008a31a0*)handle;
    flag = s->m_flags & 0x100;
    return flag;
}
