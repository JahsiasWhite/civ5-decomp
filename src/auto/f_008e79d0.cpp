// c5d-model: Gemini 4 Hydrogen
struct Item28_008e79d0 {
    int data[7];
};

class Host_008e79d0 {
public:
    char pad[0x80];
    Item28_008e79d0* m_items;
    // src: GUESS (confidence: high) [0x008e79d0]
    Item28_008e79d0* __thiscall GetItemPtr(int idx);
};

Item28_008e79d0* Host_008e79d0::GetItemPtr(int idx) {
    return &m_items[idx];
}
