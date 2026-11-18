#pragma once

// Placeholder: a COM-style interface (stdcall methods) held in the global at
// 0x03010580; slot 10 takes two ints. Rename once the interface is known.

// src: GUESS (confidence: low) [0x03010580]
class UnkComObject_03010580
{
public:
    virtual long __stdcall Slot00() = 0;
    virtual long __stdcall Slot01() = 0;
    virtual long __stdcall Slot02() = 0;
    virtual long __stdcall Slot03() = 0;
    virtual long __stdcall Slot04() = 0;
    virtual long __stdcall Slot05() = 0;
    virtual long __stdcall Slot06() = 0;
    virtual long __stdcall Slot07() = 0;
    virtual long __stdcall Slot08() = 0;
    virtual long __stdcall Slot09() = 0;
    virtual long __stdcall Slot10(int first, int second) = 0;
};

// src: GUESS (confidence: low) [0x02f65e3e]
extern bool g_enabled_02f65e3e;
// src: GUESS (confidence: low) [0x03010580]
extern UnkComObject_03010580* g_comObject_03010580;
