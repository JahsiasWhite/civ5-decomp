// Finds the first item whose id (virtual slot 1) equals the predicate's id;
// this is std::find_if with a by-value predicate.

#include <vector>

// src: GUESS (confidence: low)
class Item_00901af0
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual int GetId();
};

// src: GUESS (confidence: low)
struct HasId_00901af0
{
    bool operator()(Item_00901af0* item) const { return item->GetId() == m_id; }

    // src: GUESS (confidence: low)
    int m_id;
};

typedef std::vector<Item_00901af0*>::iterator ItemIter_00901af0;

// src: GUESS (confidence: low) [0x00901af0]
ItemIter_00901af0 FindById_00901af0(ItemIter_00901af0 first, ItemIter_00901af0 last, HasId_00901af0 pred)
{
    for (; first != last; ++first)
    {
        if (pred(*first))
            break;
    }
    return first;
}
