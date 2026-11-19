// src: GUESS (confidence: medium) [0x00909770]
#include <vector>

// src: GUESS (confidence: low)
class Item_00909770 {
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14(int flag) = 0;  // +0x38
};

// src: GUESS (confidence: low)
class Host_00909770 {
public:
    std::vector<Item_00909770*> m_items;  // +0x00
    std::vector<void*> m_other;           // +0x10

    // src: GUESS (confidence: medium) [0x00909770]
    void ClearAll();
};

void Host_00909770::ClearAll() {
    for (unsigned int i = 0; i < m_items.size(); ++i) {
        Item_00909770* pItem = m_items[i];
        if (pItem != 0) {
            pItem->Slot14(1);
        }
    }
    m_items.clear();
    m_other.clear();
}
