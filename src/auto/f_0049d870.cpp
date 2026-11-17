// c5d-model: Gemini 4 Hydrogen
class Item_0049d870 {
public:
    virtual void v0();
    virtual void __thiscall OnUpdate();
};

class Host_0049d870 {
public:
    int pad0;
    Item_0049d870** m_items;
    unsigned int m_count;
    // src: GUESS (confidence: high) [0x0049d870]
    void __thiscall UpdateAt(unsigned int idx);
};

void Host_0049d870::UpdateAt(unsigned int idx) {
    if (m_count > idx) {
        m_items[idx]->OnUpdate();
    }
}
