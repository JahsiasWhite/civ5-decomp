#pragma once
// c5d-vtable: 0x00b89800

// Placeholder: the class whose slot 5 is 0x00837750 (0x00837770's SyncSize
// file declares the same layout locally). Its constructor (0x00837690) inlines
// the base Unk_00b88c18 constructor; the fields up to 0x14 repeat that base's
// layout here, and the vtable pointer is set through a declared array.

// src: GUESS (confidence: medium) [0x00b89800]
extern void* const g_vtable_00b89800[];

// src: GUESS (confidence: low) [0x00837750]
class UnkChild_00b89800
{
public:
    virtual int Slot00() = 0;
    virtual int Slot01() = 0;
    virtual int Slot02() = 0;
    virtual int Slot03() = 0;
    virtual int Slot04() = 0;
    virtual int Slot05() = 0;
    virtual int Slot06() = 0;
    virtual int Slot07() = 0;
    virtual int Slot08() = 0;
    virtual int Slot09() = 0;
    virtual int Slot10() = 0;
    virtual int Slot11() = 0;
    virtual int Slot12() = 0;
    virtual int Slot13() = 0;
    virtual int Slot14() = 0;
    virtual int Slot15() = 0;
    virtual int Slot16() = 0;
    virtual bool IsReady() = 0;     // slot 17
};

// src: GUESS (confidence: low) [0x00b89800]
class Unk_00b89800
{
public:
    // src: GUESS (confidence: medium) [0x00837690]
    Unk_00b89800();
    // src: GUESS (confidence: low) [0x00837750]
    int IsChildReady();

    const void* m_vftable;
    bool m_enabled;                 // 0x04
    int m_count;                    // 0x08
    int m_unk0c;
    int m_unk10;
    UnkChild_00b89800* m_child;     // 0x14
};
