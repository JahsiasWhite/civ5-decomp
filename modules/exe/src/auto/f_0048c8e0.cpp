// Returns element `index` of the pointer vector, or null when the vector is
// empty or the index is out of range.

#include <vector>

// src: GUESS (confidence: low)
class PtrList_0048c8e0
{
public:
    // src: GUESS (confidence: low) [0x0048c8e0]
    void* Get(int index) const;

    char m_pad0[0x3c];
    // src: GUESS (confidence: low)
    std::vector<void*> m_items;
};

void* PtrList_0048c8e0::Get(int index) const
{
    if (m_items.size() == 0)
        return 0;
    if (index < 0 || index >= (int)m_items.size())
        return 0;
    return m_items[index];
}
