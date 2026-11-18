// src: GUESS (confidence: medium) [0x100068e0]
// src: GUESS (confidence: low)
class ContextHelper_1008b310 {
public:
    virtual void Method0() {}
    virtual void Method1() {}

    // src: GUESS (confidence: low)
    int m_iField04;  // +0x04
    // src: GUESS (confidence: low)
    int m_iField08;  // +0x08
    // src: GUESS (confidence: low)
    int m_iField0c;  // +0x0c
    // src: GUESS (confidence: low)
    int m_iField10;  // +0x10
};

// src: GUESS (confidence: low)
class ContextHost_100068e0 {
public:
    virtual void Slot0() {}
    virtual void Slot1() {}
    virtual void Slot2() {}
    virtual void Slot3() {}
    virtual void Slot4() {}
    virtual void Slot5() {}
    virtual void Slot6() {}
    virtual void Slot7() {}
    virtual void Slot8() {}
    virtual void Slot9() {}
    virtual void Slot10() {}
    virtual void Slot11() {}
    virtual void Slot12() {}
    virtual void Slot13(int a, int b, ContextHelper_1008b310* pHelper) = 0;

    // src: GUESS (confidence: medium) [0x100068e0]
    void InvokeSlot13_100068e0(int a, int b);
};

void ContextHost_100068e0::InvokeSlot13_100068e0(int a, int b) {
    ContextHelper_1008b310 kHelper;
    kHelper.m_iField04 = 0;
    kHelper.m_iField08 = 0;
    kHelper.m_iField0c = 0;
    Slot13(a, b, &kHelper);
}
