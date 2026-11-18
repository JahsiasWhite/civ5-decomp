#pragma once

// Placeholder: the object at 0x9c of 0x009069f0's owner. Only slot 59 (0xec)
// is known: a bool query. Rename once the class is known.

// src: GUESS (confidence: low) [0x009069f0]
class UnkQueryTarget_009069f0
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
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual void Slot47() = 0;
    virtual void Slot48() = 0;
    virtual void Slot49() = 0;
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52() = 0;
    virtual void Slot53() = 0;
    virtual void Slot54() = 0;
    virtual void Slot55() = 0;
    virtual void Slot56() = 0;
    virtual void Slot57() = 0;
    virtual void Slot58() = 0;
    virtual bool Query() = 0;   // slot 59
};

// src: GUESS (confidence: low) [0x009069f0]
class UnkQueryOwner_009069f0
{
public:
    // src: GUESS (confidence: low) [0x009069f0]
    bool Query();

    char m_unk00[0x9c];
    UnkQueryTarget_009069f0* m_target;  // 0x9c
    char m_unka0[0x20];
    bool m_enabled;                     // 0xc0
};
