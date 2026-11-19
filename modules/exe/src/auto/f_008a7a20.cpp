// Empties an int buffer: zeroes its storage (if any) and resets the counts.

#include <string.h>

// src: GUESS (confidence: low)
struct IntBuffer_00944640
{
    // src: GUESS (confidence: low)
    int* m_data;
    // src: GUESS (confidence: low)
    int m_used;
    // src: GUESS (confidence: low)
    int m_capacity;
    // src: GUESS (confidence: low)
    int m_count;
};

// src: GUESS (confidence: low) [0x00944640]
void ClearIntBuffer(IntBuffer_00944640* buffer)
{
    if (buffer->m_data)
        memset(buffer->m_data, 0, buffer->m_capacity * sizeof(int));
    buffer->m_used = 0;
    buffer->m_count = 0;
}
