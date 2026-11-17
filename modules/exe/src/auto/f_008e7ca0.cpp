// c5d-model: Gemini 4 Hydrogen
struct Item28_008e7ca0 {
    int val;
    int pad[6];
};

class Host_008e7ca0 {
public:
    char pad[0x80];
    Item28_008e7ca0* m_items;
    // src: GUESS (confidence: high) [0x008e7ca0]
    int __thiscall GetItemVal(int idx) const;
};

int Host_008e7ca0::GetItemVal(int idx) const {
    return m_items[idx].val;
}
