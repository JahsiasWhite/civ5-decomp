// Asks the item in slot `index` for a float (virtual slot 17); 0 when the
// index is out of range or the slot is empty.

#include <vector>

// src: GUESS (confidence: low)
class Item_008e7dd0
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
    virtual void v16();
    // src: GUESS (confidence: low)
    virtual float GetValue(int key);
};

// src: GUESS (confidence: low)
class ItemTable_008e7dd0
{
public:
    // src: GUESS (confidence: low) [0x008e7dd0]
    float GetItemValue(unsigned int index, int key) const;

    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Item_008e7dd0*> m_items;
};

float ItemTable_008e7dd0::GetItemValue(unsigned int index, int key) const
{
    if (index < m_items.size())
    {
        Item_008e7dd0* item = m_items[index];
        if (item)
            return item->GetValue(key);
    }
    return 0.0f;
}
