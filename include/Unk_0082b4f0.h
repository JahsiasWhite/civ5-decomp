#pragma once

// Placeholder interface for the four classes whose vtables share 0x0082b4f0:
// slot 12 and slot 8 return counts, and the shared body returns their difference.

// src: GUESS (confidence: low) [0x0082b4f0]
class UnkCounts_0082b4f0
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
    virtual int GetUsed() = 0;      // slot 8
    virtual int Slot09() = 0;
    virtual int Slot10() = 0;
    virtual int Slot11() = 0;
    virtual int GetTotal() = 0;     // slot 12
    // src: GUESS (confidence: low) [0x0082b4f0]
    int GetRemaining();
};
