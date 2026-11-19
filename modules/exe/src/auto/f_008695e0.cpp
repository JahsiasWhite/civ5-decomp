// Sets up the record from its five parts; fails without an owner.

// src: GUESS (confidence: low)
class Record_00903820
{
public:
    // src: GUESS (confidence: low) [0x00903820]
    bool Init(void* owner, int a, int b, int c, bool flag);

    // src: GUESS (confidence: low)
    void* m_owner;
    int m_a;
    int m_b;
    int m_c;
    bool m_flag;
};

bool Record_00903820::Init(void* owner, int a, int b, int c, bool flag)
{
    if (!owner)
        return false;
    m_owner = owner;
    m_a = a;
    m_b = b;
    m_c = c;
    m_flag = flag;
    return true;
}
