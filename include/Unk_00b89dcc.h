#pragma once
// c5d-vtable: 0x00b89dcc

// src: EXE [0x00b898a0]
extern const void* const kVtable_00b898a0[];
// src: EXE [0x00b89890]
extern void* const g_vtable_00b89890[];

// src: GUESS (confidence: low)
class __declspec(novtable) Iface0_00b898c4 {
public:
    virtual void Slot0() {}
};

// src: GUESS (confidence: low)
class Iface4_00b898a0 {
public:
    Iface4_00b898a0() { m_vf4 = kVtable_00b898a0; }
    const void* m_vf4;
};

// src: GUESS (confidence: low)
class Iface8_00b89890 {
public:
    Iface8_00b89890() { m_vf8 = g_vtable_00b89890; }
    const void* m_vf8;
};

// src: GUESS (confidence: low) [0x00b898c4]
class Base_00b898c4 : public Iface0_00b898c4, public Iface4_00b898a0, public Iface8_00b89890 {
public:
    Base_00b898c4() {}
};

// src: GUESS (confidence: low) [0x00b89dcc]
class Unk_00b89dcc : public Base_00b898c4 {
public:
    // src: GUESS (confidence: medium) [0x0083f850]
    Unk_00b89dcc();

    int m_i0c;     // +0x0c
    float m_f10;   // +0x10
    int m_i14;     // +0x14
};
