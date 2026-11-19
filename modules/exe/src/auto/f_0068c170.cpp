// Sets both the current and the target 2D value to (0, y).

// src: GUESS (confidence: low)
struct Pair_00675780
{
    Pair_00675780(float x, float y) : m_x(x), m_y(y) {}

    // src: GUESS (confidence: low)
    float m_x;
    // src: GUESS (confidence: low)
    float m_y;
};

// src: GUESS (confidence: low)
struct Owner_00675780
{
    // src: GUESS (confidence: low) [0x00675780]
    void SetY(float y);

    char m_pad0[0xe0];
    // src: GUESS (confidence: low)
    Pair_00675780 m_target;
    char m_padE8[0x104 - 0xe8];
    // src: GUESS (confidence: low)
    Pair_00675780 m_current;
};

void Owner_00675780::SetY(float y)
{
    Pair_00675780 value(0.0f, y);
    m_current = value;
    m_target = value;
}
