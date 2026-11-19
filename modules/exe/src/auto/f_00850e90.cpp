// True when any of the three lists has entries.

#include <vector>

// src: GUESS (confidence: low)
struct Block64_008eb230
{
    int m_data[16];
};

// src: GUESS (confidence: low)
class Lists_008eb230
{
public:
    // src: GUESS (confidence: low) [0x008eb230]
    bool HasEntries() const;

    char m_pad0[0x1c];
    // src: GUESS (confidence: low)
    std::vector<Block64_008eb230> m_blocks;
    char m_pad2c[0x60 - 0x2c];
    // src: GUESS (confidence: low)
    std::vector<int> m_first;
    // src: GUESS (confidence: low)
    std::vector<int> m_second;
};

bool Lists_008eb230::HasEntries() const
{
    return m_first.size() != 0 || m_second.size() != 0 || m_blocks.size() != 0;
}
