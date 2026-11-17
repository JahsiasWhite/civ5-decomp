// c5d-review: g_pDefaultDurationRef only takes the global's address so LTCG
// can't prove it doesn't alias the object and hoist its load above the bool
// store. Remove it once the real code that takes the address is decompiled.
// Resets a state flag and restores a duration field to its default, read
// from a global (75 in the shipped exe).

// src: GUESS (confidence: low) [0x00a30674]
extern float g_defaultDuration;
// src: GUESS (confidence: low)
float* g_pDefaultDurationRef = &g_defaultDuration;

// src: GUESS (confidence: low) [0x005eea30]
class StateBlock_005eea30
{
public:
    // src: GUESS (confidence: low) [0x005eea30]
    void Reset();

    char m_pad0[0x69c0];
    // src: GUESS (confidence: low)
    bool m_active;
    char m_pad69c1[0x69f8 - 0x69c1];
    // src: GUESS (confidence: low)
    float m_duration;
};

void StateBlock_005eea30::Reset()
{
    m_active = false;
    m_duration = g_defaultDuration;
}
