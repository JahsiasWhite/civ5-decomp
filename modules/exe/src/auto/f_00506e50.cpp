// Appends raw bytes to the 512 KB buffer when they fit; otherwise drops them.

#include <string.h>

// src: GUESS (confidence: low)
class ByteBuffer_00506e50
{
public:
    // src: GUESS (confidence: low) [0x00506e50]
    void Append(const void* data, unsigned int size);

    // src: GUESS (confidence: low)
    unsigned int m_length;
    int m_04;
    // src: GUESS (confidence: low)
    char m_data[0x80000];
};

void ByteBuffer_00506e50::Append(const void* data, unsigned int size)
{
    unsigned int newLength = m_length + size;
    if (newLength <= 0x80000)
    {
        memcpy(m_data + m_length, data, size);
        m_length = newLength;
    }
}
