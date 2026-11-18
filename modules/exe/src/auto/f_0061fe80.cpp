// Destroys [first, last) of intrusive reference-counted pointers.

// src: GUESS (confidence: low)
class RefObject_0061fe80
{
public:
    virtual ~RefObject_0061fe80();

    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low)
struct RefPtr_0061fe80
{
    ~RefPtr_0061fe80()
    {
        RefObject_0061fe80* object = m_object;
        if (object && --object->m_refCount <= 0)
            delete object;
    }

    // src: GUESS (confidence: low)
    RefObject_0061fe80* m_object;
};

// src: GUESS (confidence: low) [0x0061fe80]
void DestroyRefPtrs_0061fe80(RefPtr_0061fe80* first, RefPtr_0061fe80* last)
{
    for (; first != last; ++first)
        first->~RefPtr_0061fe80();
}
