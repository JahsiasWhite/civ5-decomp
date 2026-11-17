// c5d-model: Gemini 4 Hydrogen
struct Item12_008f94a0 {
    int a;
    unsigned int b;
    int c;
};

class Host_008f94a0 {
public:
    int pad0;
    int pad4;
    Item12_008f94a0* m_items;
    // src: GUESS (confidence: high) [0x008f94a0]
    bool __thiscall HasNonZero(int idx) const;
};

bool Host_008f94a0::HasNonZero(int idx) const {
    return m_items[idx].b > 0;
}
