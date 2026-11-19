// Destroys [first, last) of intrusive reference-counted pointers.

// src: GUESS (confidence: low)
class RefObject_008dd4d0
{
public:
    virtual ~RefObject_008dd4d0();

    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low)
struct RefPtr_008dd4d0
{
    ~RefPtr_008dd4d0()
    {
        RefObject_008dd4d0* object = m_object;
        if (object && --object->m_refCount <= 0)
            delete object;
    }

    // src: GUESS (confidence: low)
    RefObject_008dd4d0* m_object;
};

// src: GUESS (confidence: low) [0x008dd4d0]
void DestroyRefPtrs_008dd4d0(RefPtr_008dd4d0* first, RefPtr_008dd4d0* last)
{
    for (; first != last; ++first)
        first->~RefPtr_008dd4d0();
}
