// Sets the target: null clears it; otherwise it's taken only when it has
// flag 0x4000 and no target is set yet.

// src: GUESS (confidence: low)
struct Target_00799230
{
    char m_pad0[0x40];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

// src: GUESS (confidence: low)
class Tracker_00799230
{
public:
    // src: GUESS (confidence: low) [0x00799230]
    void SetTarget(Target_00799230* target);

    char m_pad0[0x5a0];
    // src: GUESS (confidence: low)
    Target_00799230* m_target;
};

void Tracker_00799230::SetTarget(Target_00799230* target)
{
    if (target)
    {
        if ((target->m_flags & 0x4000) && !m_target)
            m_target = target;
    }
    else
    {
        m_target = 0;
    }
}
