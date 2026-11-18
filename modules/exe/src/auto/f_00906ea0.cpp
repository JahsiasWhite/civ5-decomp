// Copy-assigns a reference-counted pointer: takes a reference on the new
// object and drops the one on the old (deleting it at zero).

// src: GUESS (confidence: low)
class RefObject_00906ea0
{
public:
    virtual ~RefObject_00906ea0();

    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low)
class RefPtr_00906ea0
{
public:
    // src: GUESS (confidence: low) [0x00906ea0]
    RefPtr_00906ea0& operator=(const RefPtr_00906ea0& other);

    // src: GUESS (confidence: low)
    RefObject_00906ea0* m_object;
};

RefPtr_00906ea0& RefPtr_00906ea0::operator=(const RefPtr_00906ea0& other)
{
    if (m_object != other.m_object)
    {
        if (other.m_object)
            ++other.m_object->m_refCount;
        RefObject_00906ea0* old = m_object;
        if (old && --old->m_refCount <= 0)
            delete old;
        m_object = other.m_object;
    }
    return *this;
}
