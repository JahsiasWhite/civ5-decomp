// Returns the index of the item with the given id; -1 for id 0 or when
// there's none.

// src: GUESS (confidence: low)
struct Item_008eb5c0
{
    // src: GUESS (confidence: low)
    int m_id;
    char m_pad4[0x88 - 4];
};

// src: GUESS (confidence: low)
class Items_008eb5c0
{
public:
    // src: GUESS (confidence: low) [0x008eb5c0]
    int IndexOf(int id) const;

    char m_pad0[0x290];
    // src: GUESS (confidence: low)
    Item_008eb5c0 m_items[0x20];
    // src: GUESS (confidence: low)
    int m_count;
};

int Items_008eb5c0::IndexOf(int id) const
{
    if (id)
    {
        for (int i = 0; i < m_count; ++i)
        {
            if (m_items[i].m_id == id)
                return i;
        }
    }
    return -1;
}
