// A small class with a vtable; the field at offset 8 is set through virtual slot 2.
// Vtbl_00a41700 inherits that slot.
// c5d-vtable: 0x00a416ec
#pragma once

// src: GUESS (confidence: low)
class Unk_00a416ec
{
public:
    virtual void v00();
    virtual void v01();
    // src: GUESS (confidence: low) [0x0079aeb0]
    virtual void SetField08(int value);

    // src: GUESS (confidence: low)
    int m_field04;
    // src: GUESS (confidence: low)
    int m_field08;
};
