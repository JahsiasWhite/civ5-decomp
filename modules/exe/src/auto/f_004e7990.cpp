// Copy-constructs a buffer's 0xb0-byte records from another buffer into this one's storage.

#include <new>

// src: GUESS (confidence: low)
struct RecordB0_0069bc10
{
    // src: GUESS (confidence: low)
    int m_words[0x2c];
};

// src: GUESS (confidence: low)
struct RecordBuffer_0069bc10
{
    // src: GUESS (confidence: low) [0x0069bc10]
    void CopyRecords(const RecordBuffer_0069bc10& other);

    // src: GUESS (confidence: low)
    RecordB0_0069bc10* m_data;
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

void RecordBuffer_0069bc10::CopyRecords(const RecordBuffer_0069bc10& other)
{
    m_count = other.m_count;
    for (unsigned int i = 0; i < m_count; ++i)
    {
        new (&m_data[i]) RecordB0_0069bc10(other.m_data[i]);
    }
}
