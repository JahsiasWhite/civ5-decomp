#pragma once
// c5d-vtable: 0x00b89ec8

// Placeholder: slot 14 (0x00841450) passes slot 12's result for its argument
// on to slot 15. Rename once the class is known.

// src: GUESS (confidence: low) [0x00b89ec8]
class Unk_00b89ec8
{
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
    virtual int Lookup(int key) = 0;            // slot 12
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;                  // 0x00841450
    virtual void Apply(int value) = 0;          // slot 15

    // src: GUESS (confidence: low) [0x00841450]
    void LookupAndApply(int key);
};
