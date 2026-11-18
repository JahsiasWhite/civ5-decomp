// Constructs the settings with their defaults.

// src: GUESS (confidence: low)
struct Settings_004cca80
{
    // src: GUESS (confidence: low) [0x004cca80]
    Settings_004cca80();

    int m_00;
    // src: GUESS (confidence: low)
    int m_index;
    // src: GUESS (confidence: low)
    unsigned char m_mode;
    // src: GUESS (confidence: low)
    int m_limit;
    char m_pad10[0x450 - 0x10];
    float m_x;
    float m_y;
    int m_458;
};

Settings_004cca80::Settings_004cca80()
    : m_00(0)
    , m_index(-1)
    , m_mode(7)
    , m_limit(5)
    , m_x(0.0f)
    , m_y(0.0f)
    , m_458(0)
{
}
