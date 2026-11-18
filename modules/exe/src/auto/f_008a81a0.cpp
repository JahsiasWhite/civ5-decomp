// c5d-cflags: +/Od
// Sets or clears bit 0 of the object's state flags.

// src: GUESS (confidence: low)
struct State_008a81a0
{
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

// src: GUESS (confidence: low)
struct Object_008a81a0
{
    char m_pad0[0x318];
    // src: GUESS (confidence: low)
    State_008a81a0* m_state;
};

// src: GUESS (confidence: low) [0x008a81a0]
void SetFlag_008a81a0(Object_008a81a0* object, int on)
{
    State_008a81a0* state = object->m_state;
    if (on)
        state->m_flags |= 1;
    else
        state->m_flags &= ~1u;
}
