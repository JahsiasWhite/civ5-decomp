// Assigns a new object to the reference-counted pointer: takes a reference
// on it and drops the one on the old object (deleting it at zero).

// src: GUESS (confidence: low)
class RefObject_008dcef0
{
public:
    virtual ~RefObject_008dcef0();

    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low)
class RefPtr_008dcef0
{
public:
    // src: GUESS (confidence: low) [0x008dcef0]
    RefPtr_008dcef0& operator=(RefObject_008dcef0* object);

    // src: GUESS (confidence: low)
    RefObject_008dcef0* m_object;
};

RefPtr_008dcef0& RefPtr_008dcef0::operator=(RefObject_008dcef0* object)
{
    if (m_object != object)
    {
        if (object)
            ++object->m_refCount;
        RefObject_008dcef0* old = m_object;
        if (old && --old->m_refCount <= 0)
            delete old;
        m_object = object;
    }
    return *this;
}
