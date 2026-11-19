// Stores five settings and clears the done flag.

// src: GUESS (confidence: low)
struct Settings_0055b2f0
{
    // src: GUESS (confidence: low) [0x0055b2f0]
    void Set(int a, int b, int c, int d, int e);

    char m_pad0[0x13dc];
    // src: GUESS (confidence: low)
    int m_13dc;
    char m_pad13e0[0x1404 - 0x13e0];
    // src: GUESS (confidence: low)
    int m_1404;
    // src: GUESS (confidence: low)
    int m_1408;
    // src: GUESS (confidence: low)
    int m_140c;
    // src: GUESS (confidence: low)
    int m_1410;
    // src: GUESS (confidence: low)
    bool m_done;
};

void Settings_0055b2f0::Set(int a, int b, int c, int d, int e)
{
    m_1408 = a;
    m_140c = c;
    m_1410 = d;
    m_13dc = e;
    m_1404 = b;
    m_done = false;
}
