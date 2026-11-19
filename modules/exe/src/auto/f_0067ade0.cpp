// c5d-model: Gemini 4 Hydrogen
struct Item_00662080 {
    int f0;
    int f4;
};

class Host_00662080 {
public:
    int pad0;
    Item_00662080** m_items;
    unsigned int m_count;
    // src: GUESS (confidence: high) [0x00662080]
    void __thiscall SetItemField(unsigned int idx, int val);
};

void Host_00662080::SetItemField(unsigned int idx, int val) {
    if (m_count > idx) {
        m_items[idx]->f4 = val;
    }
}
