// When enabled, checks the target's flags: fails if bit 0 is set or bit 4 is
// clear; otherwise marks the target and succeeds.

// src: GUESS (confidence: low)
struct Target_0092cbd0
{
    // src: GUESS (confidence: low)
    unsigned int m_flags;
    char m_pad4[0x1a8 - 4];
    // src: GUESS (confidence: low)
    int m_marked;
};

// src: GUESS (confidence: low)
struct Context_0092cbd0
{
    char m_pad0[0x20];
    // src: GUESS (confidence: low)
    int m_enabled;
    char m_pad24[0x58 - 0x24];
    // src: GUESS (confidence: low)
    Target_0092cbd0* m_target;
};

// src: GUESS (confidence: low) [0x0092cbd0]
int MarkTarget_0092cbd0(Context_0092cbd0* context)
{
    if (context->m_enabled)
    {
        Target_0092cbd0* target = context->m_target;
        if (target->m_flags & 1)
            return 0;
        if (!(target->m_flags & 0x10))
            return 0;
        target->m_marked = 1;
    }
    return 1;
}
