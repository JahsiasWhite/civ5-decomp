// Owning pointer assignment from a transfer handle passed by value: takes
// the handle's object, releasing the one held before if it's different.

// src: GUESS (confidence: low)
class Releasable_005d4da0
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void __stdcall Release();
};

// src: GUESS (confidence: low)
struct OwnedPtrRef_005d4da0
{
    // src: GUESS (confidence: low)
    Releasable_005d4da0* m_ptr;
};

// src: GUESS (confidence: low)
class OwnedPtr_005d4da0
{
public:
    // src: GUESS (confidence: low) [0x005d4da0]
    OwnedPtr_005d4da0& operator=(OwnedPtrRef_005d4da0 other);

    // src: GUESS (confidence: low)
    Releasable_005d4da0* m_ptr;
};

OwnedPtr_005d4da0& OwnedPtr_005d4da0::operator=(OwnedPtrRef_005d4da0 other)
{
    Releasable_005d4da0* ptr = other.m_ptr;
    other.m_ptr = 0;
    if (ptr != m_ptr && m_ptr)
        m_ptr->Release();
    m_ptr = ptr;
    return *this;
}
