// Starts a request: stores its id and target, marks it pending and clears
// its progress.

// src: GUESS (confidence: low)
class Request_006ca2d0
{
public:
    // src: GUESS (confidence: low) [0x006ca2d0]
    void Start(int id, int target);

    char m_pad0[0x13dc];
    // src: GUESS (confidence: low)
    int m_progress;
    char m_pad13e0[0x1404 - 0x13e0];
    // src: GUESS (confidence: low)
    int m_target;
    int m_1408;
    // src: GUESS (confidence: low)
    int m_id;
    int m_1410;
    // src: GUESS (confidence: low)
    bool m_pending;
};

void Request_006ca2d0::Start(int id, int target)
{
    m_id = id;
    m_pending = true;
    m_1410 = 0;
    m_progress = 0;
    m_1408 = 0;
    m_target = target;
}
