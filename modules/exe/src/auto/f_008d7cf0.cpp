// Replaces the attached reference-counted object (virtual slot 5).

// src: GUESS (confidence: low)
class RefObject_008d7cf0
{
public:
    virtual ~RefObject_008d7cf0();

    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low) [0x00a98e94]
class Holder_008d7cf0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    // src: GUESS (confidence: low) [0x008d7cf0]
    virtual void SetObject(RefObject_008d7cf0* object);

    char m_pad4[0x18 - 4];
    // src: GUESS (confidence: low)
    RefObject_008d7cf0* m_object;
};

void Holder_008d7cf0::SetObject(RefObject_008d7cf0* object)
{
    if (m_object != object)
    {
        if (object)
            ++object->m_refCount;
        RefObject_008d7cf0* old = m_object;
        if (old && --old->m_refCount <= 0)
            delete old;
        m_object = object;
    }
}
