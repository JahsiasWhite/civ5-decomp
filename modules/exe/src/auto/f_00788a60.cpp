// c5d-cflags: -/arch:SSE2
// While in mode 2 and enabled, takes the given position.

// src: GUESS (confidence: low)
struct Vec3i_00788a60
{
    int x;
    int y;
    int z;
};

// src: GUESS (confidence: low)
class Mover_00788a60
{
public:
    // src: GUESS (confidence: low) [0x00788a60]
    void SetPosition(const Vec3i_00788a60* position);

    char m_pad0[0x94];
    // src: GUESS (confidence: low)
    Vec3i_00788a60 m_position;
    // src: GUESS (confidence: low)
    int m_mode;
    // src: GUESS (confidence: low)
    bool m_enabled;
};

void Mover_00788a60::SetPosition(const Vec3i_00788a60* position)
{
    if (m_mode == 2 && m_enabled)
        m_position = *position;
}
