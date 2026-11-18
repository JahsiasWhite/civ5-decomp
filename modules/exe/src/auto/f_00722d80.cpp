// Fills the rest of the preallocated array with copies of `value`.

#include <new>

// src: GUESS (confidence: low)
struct Record_00722d80
{
    int m_data[0x20];
};

// src: GUESS (confidence: low)
class RecordArray_00722d80
{
public:
    // src: GUESS (confidence: low) [0x00722d80]
    void FillRemaining(const Record_00722d80& value);

    // src: GUESS (confidence: low)
    Record_00722d80* m_data;
    // src: GUESS (confidence: low)
    unsigned int m_capacity;
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

void RecordArray_00722d80::FillRemaining(const Record_00722d80& value)
{
    for (; m_count < m_capacity; ++m_count)
        new (&m_data[m_count]) Record_00722d80(value);
}
