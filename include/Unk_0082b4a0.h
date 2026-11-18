#pragma once

// Placeholder interface for the four classes whose vtables share 0x0082b4a0:
// slot 4 is called with no arguments, then slot 3 with one.

// src: GUESS (confidence: low) [0x0082b4a0]
class UnkResetApply_0082b4a0
{
public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Apply(int value) = 0;   // slot 3
    virtual void Reset() = 0;            // slot 4

    // src: GUESS (confidence: low) [0x0082b4a0]
    void ResetAndApply(int value);
};
