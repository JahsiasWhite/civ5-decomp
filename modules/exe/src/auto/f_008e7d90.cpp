// c5d-cflags: -/arch:SSE2
// Passes a key and value to the item in slot `index` (virtual slot 16), if
// the index is in range and the slot isn't empty.

#include <vector>

// src: GUESS (confidence: low)
class Item_008e7d90
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    // src: GUESS (confidence: low)
    virtual void SetValue(int key, float value);
};

// src: GUESS (confidence: low)
class ItemTable_008e7d90
{
public:
    // src: GUESS (confidence: low) [0x008e7d90]
    void SetItemValue(unsigned int index, int key, float value);

    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Item_008e7d90*> m_items;
};

void ItemTable_008e7d90::SetItemValue(unsigned int index, int key, float value)
{
    if (index < m_items.size())
    {
        Item_008e7d90* item = m_items[index];
        if (item)
            item->SetValue(key, value);
    }
}
