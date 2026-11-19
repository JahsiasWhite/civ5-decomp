// Copy-constructs a buffer's 5-byte records from another buffer into this one's storage.

#include <new>

// src: GUESS (confidence: low)
struct Record5_004a1a30
{
    // src: GUESS (confidence: low)
    unsigned char m_bytes[5];
};

// src: GUESS (confidence: low)
struct RecordBuffer_004a1a30
{
    // src: GUESS (confidence: low) [0x004a1a30]
    void CopyRecords(const RecordBuffer_004a1a30& other);

    // src: GUESS (confidence: low)
    Record5_004a1a30* m_data;
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

void RecordBuffer_004a1a30::CopyRecords(const RecordBuffer_004a1a30& other)
{
    m_count = other.m_count;
    for (unsigned int i = 0; i < m_count; ++i)
    {
        new (&m_data[i]) Record5_004a1a30(other.m_data[i]);
    }
}
