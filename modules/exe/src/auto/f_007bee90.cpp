// src: GUESS (confidence: low)
struct Item_007bee90
{
    char m_pad[0x338];
};

// src: GUESS (confidence: low) [0x02c63e80]
extern Item_007bee90 g_items_007bee90[64];

// src: GUESS (confidence: high) [0x007bee90]
Item_007bee90* GetItem_007bee90(unsigned int index)
{
    return &g_items_007bee90[(index <= 63) ? index : 0];
}
