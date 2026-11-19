// Asks the item in slot `index` for its id (virtual slot 7); -1 when the
// index is out of range or the slot is empty.

#include <vector>

// src: GUESS (confidence: low)
class Item_008e7cc0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    // src: GUESS (confidence: low)
    virtual int GetId();
};

// src: GUESS (confidence: low)
class ItemTable_008e7cc0
{
public:
    // src: GUESS (confidence: low) [0x008e7cc0]
    int GetItemId(unsigned int index) const;

    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Item_008e7cc0*> m_items;
};

int ItemTable_008e7cc0::GetItemId(unsigned int index) const
{
    if (index < m_items.size())
    {
        Item_008e7cc0* item = m_items[index];
        if (item)
            return item->GetId();
    }
    return -1;
}
