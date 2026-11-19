// Returns the target's value: for kind 0x5aa, its override value unless
// that's at the minimum (0), otherwise its base value.

// src: GUESS (confidence: low)
struct Target_0067cf40
{
    char m_pad0[0x14];
    // src: GUESS (confidence: low)
    float m_base;
    // src: GUESS (confidence: low)
    float m_override;
};

// src: GUESS (confidence: low)
extern float g_minPositive_00a0b4ec;

// src: GUESS (confidence: low)
class Holder_0067cf40
{
public:
    // src: GUESS (confidence: low) [0x0067cf40]
    float GetValue() const;

    char m_pad0[0x5c];
    // src: GUESS (confidence: low)
    Target_0067cf40* m_target;
    char m_pad60[0x74 - 0x60];
    // src: GUESS (confidence: low)
    int m_kind;
};

float Holder_0067cf40::GetValue() const
{
    if (m_kind == 0x5aa)
    {
        return (m_target->m_override != g_minPositive_00a0b4ec) ? m_target->m_override : m_target->m_base;
    }
    return m_target->m_base;
}
