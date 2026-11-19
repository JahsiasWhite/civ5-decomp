// Queues an item, along with its base offset plus 128 bytes per row.

// src: GUESS (confidence: low)
struct Item_008bd0f0
{
    // src: GUESS (confidence: low)
    int m_base;
};

// src: GUESS (confidence: low)
class Queue_008bd0f0
{
public:
    // src: GUESS (confidence: low) [0x008bd0f0]
    void Add(Item_008bd0f0* item, int row);

    char m_pad0[0x46c];
    // src: GUESS (confidence: low)
    Item_008bd0f0* m_items[0x8001];
    // src: GUESS (confidence: low)
    int m_offsets[0x4001];
    // src: GUESS (confidence: low)
    int m_count;
};

void Queue_008bd0f0::Add(Item_008bd0f0* item, int row)
{
    m_items[m_count] = item;
    m_offsets[m_count] = item->m_base + row * 128;
    ++m_count;
}
