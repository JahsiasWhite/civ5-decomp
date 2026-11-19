// Returns the first word of record `index`, or 0 when out of range.

#include <vector>

// src: GUESS (confidence: low)
struct Record_008ed340
{
    // src: GUESS (confidence: low)
    int m_id;
    int m_data[0x41];
};

// src: GUESS (confidence: low)
class Records_008ed340
{
public:
    // src: GUESS (confidence: low) [0x008ed340]
    int GetId(unsigned int index) const;

    char m_pad0[0x50];
    // src: GUESS (confidence: low)
    std::vector<Record_008ed340> m_records;
};

int Records_008ed340::GetId(unsigned int index) const
{
    if (index < m_records.size())
        return m_records[index].m_id;
    return 0;
}
