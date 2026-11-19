// Finds the first item whose id (virtual slot 5) equals the predicate's id;
// this is std::find_if with a by-value predicate.

#include <vector>

// src: GUESS (confidence: low)
class Item_00901ab0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    // src: GUESS (confidence: low)
    virtual int GetId();
};

// src: GUESS (confidence: low)
struct HasId_00901ab0
{
    bool operator()(Item_00901ab0* item) const { return item->GetId() == m_id; }

    // src: GUESS (confidence: low)
    int m_id;
};

typedef std::vector<Item_00901ab0*>::iterator ItemIter_00901ab0;

// src: GUESS (confidence: low) [0x00901ab0]
ItemIter_00901ab0 FindById_00901ab0(ItemIter_00901ab0 first, ItemIter_00901ab0 last, HasId_00901ab0 pred)
{
    for (; first != last; ++first)
    {
        if (pred(*first))
            break;
    }
    return first;
}
