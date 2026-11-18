#pragma once

// Placeholder interface for the 17 classes whose vtables share 0x007553a0:
// slot 0 returns the object's type id, and the shared body casts to that type.

// src: GUESS (confidence: low) [0x007553a0]
class UnkTyped_007553a0
{
public:
    virtual const int& GetTypeId() = 0;     // slot 0

    // src: GUESS (confidence: medium) [0x007553a0]
    void* CastTo(const int& typeId);
};
