#pragma once
// c5d-vtable: 0x00a99d74

// Placeholder: the class whose slot 2 (0x008e2910) deletes the object it owns
// at 0x18. Class_008f4220's Check (slot 9) declares part of the same layout
// locally. Rename once the class is known.

// src: GUESS (confidence: low) [0x008e2910]
class UnkOwned_008e2910
{
public:
    virtual ~UnkOwned_008e2910();
};

// src: GUESS (confidence: low) [0x00a99d74]
class Unk_00a99d74
{
public:
    // src: GUESS (confidence: medium) [0x008e2910]
    bool ReleaseOwned();

    int m_unk00[6];
    UnkOwned_008e2910* m_owned;     // 0x18
};
