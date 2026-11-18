#pragma once
// c5d-vtable: 0x00b87e84

// Placeholder: a class with a second base at 0x30 whose slot 18 takes a
// buffer and a value. 0x007facb0 (slot 3 of the primary vtable) forwards to it
// with the buffer at 0x264. Rename once the hierarchy is known.

// src: GUESS (confidence: low) [0x00b87e84]
class UnkPrimary_00b87e84
{
public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    char m_unk04[0x2c];
};

// src: GUESS (confidence: low) [0x007facb0]
class UnkSink_007facb0
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
    virtual int Write(void* buffer, int value) = 0;     // slot 18
};

// src: GUESS (confidence: low) [0x00b87e84]
class Unk_00b87e84 : public UnkPrimary_00b87e84, public UnkSink_007facb0
{
public:
    // src: GUESS (confidence: low) [0x007facb0]
    int WriteToBuffer(int value);

    char m_unk034[0x230];
    char m_buffer[4];       // 0x264
};
