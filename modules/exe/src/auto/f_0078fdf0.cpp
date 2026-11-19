// Reports the current entry's value; 0 and false when there's no current
// entry.

#include <vector>

// src: GUESS (confidence: low)
struct Entry_007a0d30
{
    int m_key;
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low)
class Cursor_007a0d30
{
public:
    // src: GUESS (confidence: low) [0x007a0d30]
    bool GetCurrent(int* value) const;

    // src: GUESS (confidence: low)
    std::vector<Entry_007a0d30> m_entries;
    // src: GUESS (confidence: low)
    int m_current;
};

bool Cursor_007a0d30::GetCurrent(int* value) const
{
    if (m_current >= 0 && m_current < (int)m_entries.size())
    {
        *value = m_entries[m_current].m_value;
        return true;
    }
    *value = 0;
    return false;
}
