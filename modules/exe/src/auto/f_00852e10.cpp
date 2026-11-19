// Returns element `index` of the record vector, or null when out of range.

#include <vector>

// src: GUESS (confidence: low)
struct Record_008ed380
{
    int m_data[0x12];
};

// src: GUESS (confidence: low)
class Records_008ed380
{
public:
    // src: GUESS (confidence: low) [0x008ed380]
    Record_008ed380* Get(unsigned int index);

    char m_pad0[0x60];
    // src: GUESS (confidence: low)
    std::vector<Record_008ed380> m_records;
};

Record_008ed380* Records_008ed380::Get(unsigned int index)
{
    if (index < m_records.size())
        return &m_records[index];
    return 0;
}
