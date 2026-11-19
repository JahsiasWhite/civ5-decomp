// Constructs the object around a reference-counted target (taking a
// reference) and a value; everything else starts cleared.

// src: GUESS (confidence: low)
struct RefObject_008f3ed0
{
    int m_00;
    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low) [0x00a9b4dc]
class Binding_008f3ed0
{
public:
    // src: GUESS (confidence: low) [0x008f3ed0]
    Binding_008f3ed0(RefObject_008f3ed0* target, int value);

    virtual void v00();

    // src: GUESS (confidence: low)
    RefObject_008f3ed0* m_target;
    // src: GUESS (confidence: low)
    int m_value;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    bool m_20;
    bool m_21;
    bool m_22;
};

Binding_008f3ed0::Binding_008f3ed0(RefObject_008f3ed0* target, int value)
    : m_target(target)
{
    if (m_target)
        ++m_target->m_refCount;
    m_value = value;
    m_0c = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = false;
    m_21 = false;
    m_22 = false;
}
