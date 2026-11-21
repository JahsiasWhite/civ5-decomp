// c5d-cflags: -/O2 -/Ob1 +/Od
// src: GUESS (confidence: low)
struct UnkFlagsObj_007fcd50
{
    char m_pad[0x100];
    unsigned int m_flags;
};

// src: GUESS (confidence: medium) [0x007fcd50]
void SetFlags_007fcd50(UnkFlagsObj_007fcd50* obj, unsigned int mask, int enable)
{
    if (enable)
        obj->m_flags |= mask;
    else
        obj->m_flags &= ~mask;
}
