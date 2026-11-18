#pragma once
// c5d-vtable: 0x00a91730
#include <vector>

// src: GUESS (confidence: low)
struct Elem28_00a91730 {
    char m_data[28];
};

// src: GUESS (confidence: low) [0x00a91730]
class Unk_00a91730 {
public:
    virtual void Slot00() {}
    virtual void Slot01() {}
    virtual void Slot02() {}
    virtual void Slot03() {}
    virtual void Slot04() {}
    virtual void Slot05() {}
    virtual void Slot06() {}
    virtual void Slot07() {}
    virtual void Slot08() {}
    virtual void Slot09() {}
    virtual void Slot10() {}
    virtual void Slot11() {}
    virtual void Slot12() {}
    virtual void Slot13() {}
    virtual void Slot14() {}
    virtual void Slot15() {}
    virtual void Slot16() {}
    virtual void Slot17() {}
    virtual void Slot18() {}
    virtual void Slot19() {}
    virtual void Slot20() {}
    virtual void Slot21() {}
    virtual void Slot22() {}
    virtual void Slot23() {}
    virtual void Slot24() {}
    virtual void Slot25() {}
    virtual void Slot26() {}
    virtual void Slot27() {}
    virtual void Slot28() {}
    virtual void Slot29() {}
    // src: GUESS (confidence: medium) [0x007eaa20]
    virtual int ValidateIndex_007eaa20(int iIndex) const;

    char m_pad04[0x14];                    // +0x04
    // src: GUESS (confidence: medium)
    std::vector<Elem28_00a91730> m_elems;  // +0x18 (_Myfirst at +0x1c, _Mylast at +0x20)
};
