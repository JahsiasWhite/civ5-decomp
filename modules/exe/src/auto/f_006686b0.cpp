// Owning pointer assignment (by reference): takes the other pointer's object,
// releasing the one held before if it's a different object.

// src: GUESS (confidence: low)
class Releasable_00606d90
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void __stdcall Release();
};

// src: GUESS (confidence: low)
class OwnedPtr_00606d90
{
public:
    ~OwnedPtr_00606d90()
    {
        if (m_ptr)
            m_ptr->Release();
    }

    // src: GUESS (confidence: low) [0x00606d90]
    OwnedPtr_00606d90& operator=(OwnedPtr_00606d90& other);

    // src: GUESS (confidence: low)
    Releasable_00606d90* m_ptr;
};

OwnedPtr_00606d90& OwnedPtr_00606d90::operator=(OwnedPtr_00606d90& other)
{
    Releasable_00606d90* ptr = other.m_ptr;
    other.m_ptr = 0;
    if (ptr != m_ptr && m_ptr)
        m_ptr->Release();
    m_ptr = ptr;
    return *this;
}
