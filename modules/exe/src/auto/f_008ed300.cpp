// Returns element `index` of the record vector, or null when out of range.

#include <vector>

// src: GUESS (confidence: low)
struct Record_008ed300
{
    int m_data[0x42];
};

// src: GUESS (confidence: low)
class Records_008ed300
{
public:
    // src: GUESS (confidence: low) [0x008ed300]
    Record_008ed300* Get(unsigned int index);

    char m_pad0[0x50];
    // src: GUESS (confidence: low)
    std::vector<Record_008ed300> m_records;
};

Record_008ed300* Records_008ed300::Get(unsigned int index)
{
    if (index < m_records.size())
        return &m_records[index];
    return 0;
}
