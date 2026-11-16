#pragma once

// Placeholder: an object holding (at +0xC4) a pointer to another object whose
// field at +0x4 0x004cc170 returns, or 0 when there is none. Rename once known.

struct UnkLinkedTarget
{
    int m_00;
    int m_04;
};

struct UnkLinkedHolder
{
    int GetTargetField4();

    char pad00[0xc4];
    UnkLinkedTarget* m_pTarget;
};
