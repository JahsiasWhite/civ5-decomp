// Copies another int array's contents (both use preallocated storage).

#include <new>

// src: GUESS (confidence: low)
class IntArray_006bcc80
{
public:
    // src: GUESS (confidence: low) [0x006bcc80]
    void CopyFrom(const IntArray_006bcc80& other);

    // src: GUESS (confidence: low)
    int* m_data;
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

void IntArray_006bcc80::CopyFrom(const IntArray_006bcc80& other)
{
    m_count = other.m_count;
    for (unsigned int i = 0; i < m_count; ++i)
        new (&m_data[i]) int(other.m_data[i]);
}
