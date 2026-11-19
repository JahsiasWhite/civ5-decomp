// Reports whether the pointer held at offset 0 is set.

// src: GUESS (confidence: low)
class PtrHolder_0071ea90
{
public:
    // src: GUESS (confidence: low) [0x0071ea90]
    bool HasPtr() const;

    // src: GUESS (confidence: low)
    void* m_ptr;
};

bool PtrHolder_0071ea90::HasPtr() const
{
    return m_ptr != 0;
}
