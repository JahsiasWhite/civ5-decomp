// c5d-cflags: -/arch:SSE2
// Passes a key and value to the item in slot `index` (virtual slot 4), if
// the index is in range and the slot isn't empty.

#include <vector>

// src: GUESS (confidence: low)
class Item_008e7d20
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    // src: GUESS (confidence: low)
    virtual void SetValue(int key, float value);
};

// src: GUESS (confidence: low)
class ItemTable_008e7d20
{
public:
    // src: GUESS (confidence: low) [0x008e7d20]
    void SetItemValue(unsigned int index, int key, float value);

    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Item_008e7d20*> m_items;
};

void ItemTable_008e7d20::SetItemValue(unsigned int index, int key, float value)
{
    if (index < m_items.size())
    {
        Item_008e7d20* item = m_items[index];
        if (item)
            item->SetValue(key, value);
    }
}
