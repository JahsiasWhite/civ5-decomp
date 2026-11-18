// Returns a field of the item in slot `index`, or 0 when the index is out
// of range or the slot is empty.

#include <vector>

// src: GUESS (confidence: low)
struct Item_008e7e00
{
    char m_pad0[0xa4];
    // src: GUESS (confidence: low)
    int m_valueA4;
};

// src: GUESS (confidence: low)
class ItemTable_008e7e00
{
public:
    // src: GUESS (confidence: low) [0x008e7e00]
    int GetValueA4(unsigned int index) const;

    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Item_008e7e00*> m_items;
};

int ItemTable_008e7e00::GetValueA4(unsigned int index) const
{
    if (index < m_items.size())
    {
        Item_008e7e00* item = m_items[index];
        if (item)
            return item->m_valueA4;
    }
    return 0;
}
