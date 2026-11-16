#pragma once

// Placeholder: an object whose Reset(int) (0x004a1300) clears the ints at +0x0,
// +0x4 and +0xC and the flag at +0x2C; the argument is unused. Rename once the
// owning type is known.

struct UnkResetRecord
{
    void Reset(int unused);

    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    char pad10[0x2c - 0x10];
    bool m_2c;
};
