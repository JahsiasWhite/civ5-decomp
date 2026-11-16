// An abstract interface: most of its 47 virtual slots are pure, the rest are
// shared do-nothing stubs. Only the first slots are declared so far.
// c5d-vtable: 0x00a10ac8
#pragma once

// src: GUESS (confidence: low)
class Unk_00a10ac8
{
public:
    // src: GUESS (confidence: low) [0x008db570]
    Unk_00a10ac8();

    virtual void v00();
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
};
