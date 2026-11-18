// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// One-shot callback: when the reply's id pair matches the pending one,
// clears it and calls the stored member function with the two values.

// src: GUESS (confidence: low)
struct Target_007d2c30
{
    int m_unused;
};

// src: GUESS (confidence: low) [0x00b8579c]
class PendingReply_007d2c30
{
public:
    // src: GUESS (confidence: low) [0x007d2c30]
    virtual void OnReply(int a, int b, int id1, int id2);

    char m_pad4[0x10 - 4];
    // src: GUESS (confidence: low)
    int m_id1;
    // src: GUESS (confidence: low)
    int m_id2;
    // src: GUESS (confidence: low)
    Target_007d2c30* m_target;
    // src: GUESS (confidence: low)
    void (Target_007d2c30::*m_callback)(int a, int b);
};

void PendingReply_007d2c30::OnReply(int a, int b, int id1, int id2)
{
    if (id1 == m_id1 && id2 == m_id2)
    {
        m_id1 = 0;
        m_id2 = 0;
        (m_target->*m_callback)(a, b);
    }
}
