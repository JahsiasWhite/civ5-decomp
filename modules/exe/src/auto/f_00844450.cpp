// Copy-constructs [first, last) of intrusive reference-counted pointers
// into raw storage at dest; returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct RefObject_008de3a0
{
    int m_00;
    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low)
struct RefPtr_008de3a0
{
    RefPtr_008de3a0(const RefPtr_008de3a0& other)
        : m_object(other.m_object)
    {
        if (m_object)
            ++m_object->m_refCount;
    }

    // src: GUESS (confidence: low)
    RefObject_008de3a0* m_object;
};

// src: GUESS (confidence: low) [0x008de3a0]
RefPtr_008de3a0* __stdcall UninitializedCopy_008de3a0(const RefPtr_008de3a0* first, const RefPtr_008de3a0* last, RefPtr_008de3a0* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
