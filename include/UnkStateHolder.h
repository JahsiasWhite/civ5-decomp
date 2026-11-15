#pragma once

// Placeholder layouts for an object that points (at +0x104) to a state block
// whose fields are read by a set of small C-style getters near 0x00895000.
// Rename once the owning class is identified.

struct UnkStateBlock
{
    char pad0[0x120];
    int field_120;
    char pad124[0x12c - 0x124];
    int field_12c;
};

struct UnkStateHolder
{
    char pad0[0x104];
    UnkStateBlock* state;
};
