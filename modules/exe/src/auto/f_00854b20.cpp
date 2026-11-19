// Fills raw storage with `count` copies of a reference-counted handle.

#include <new>

// src: GUESS (confidence: low)
struct RefCounted_008ef070
{
    int m_00;
    // src: GUESS (confidence: low)
    int m_refCount;
};

// src: GUESS (confidence: low)
struct Handle_008ef070
{
    Handle_008ef070(const Handle_008ef070& other)
        : m_object(other.m_object)
    {
        if (m_object)
            ++m_object->m_refCount;
        m_extra = other.m_extra;
    }

    // src: GUESS (confidence: low)
    RefCounted_008ef070* m_object;
    // src: GUESS (confidence: low)
    int m_extra;
};

// src: GUESS (confidence: low) [0x008ef070]
void UninitializedFill_008ef070(Handle_008ef070* dest, unsigned int count, const Handle_008ef070& value)
{
    for (; 0 < count; --count, ++dest)
        new (dest) Handle_008ef070(value);
}
