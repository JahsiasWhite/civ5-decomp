// Returns a field of the item in slot `index`, or true when the index is out
// of range or the slot is empty.

#include <vector>

// src: GUESS (confidence: low)
struct Item_008e7ec0
{
    char m_pad0[0x94];
    // src: GUESS (confidence: low)
    bool m_flag94;
};

// src: GUESS (confidence: low)
class ItemTable_008e7ec0
{
public:
    // src: GUESS (confidence: low) [0x008e7ec0]
    bool IsFlag94(unsigned int index) const;

    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Item_008e7ec0*> m_items;
};

bool ItemTable_008e7ec0::IsFlag94(unsigned int index) const
{
    if (index < m_items.size())
    {
        Item_008e7ec0* item = m_items[index];
        if (item)
            return item->m_flag94;
    }
    return true;
}
