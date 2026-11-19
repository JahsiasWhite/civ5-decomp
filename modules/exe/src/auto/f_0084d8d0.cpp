// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct Item52_008e7ad0 {
    char data[0x34];
};

class Host_008e7ad0 {
public:
    char pad0[0x30];
    Item52_008e7ad0* m_items;
    unsigned short m_count;
    // src: GUESS (confidence: high) [0x008e7ad0]
    Item52_008e7ad0* __thiscall GetItem(unsigned int idx);
};

Item52_008e7ad0* __thiscall Host_008e7ad0::GetItem(unsigned int idx) {
    if (idx < m_count) {
        return &m_items[idx];
    }
    return 0;
}
