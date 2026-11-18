// Sets the two ids and clears the match flag; it's set when the mode is 1
// and the id matches the expected one.

// src: GUESS (confidence: low)
class Matcher_008f4450
{
public:
    // src: GUESS (confidence: low) [0x008f4450]
    void Set(int id, int mode);

    char m_pad0[0xa4];
    // src: GUESS (confidence: low)
    int m_expectedId;
    // src: GUESS (confidence: low)
    int m_mode;
    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    int m_matched;
};

void Matcher_008f4450::Set(int id, int mode)
{
    m_mode = mode;
    m_id = id;
    m_matched = 0;
    if (mode == 1 && m_expectedId == id)
        m_matched = mode;
}
