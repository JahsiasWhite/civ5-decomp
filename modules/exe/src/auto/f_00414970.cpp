// Returns the 32-bit value stored four bytes into the object. The call takes
// one stack argument, which the body ignores; it is cleaned up by the callee.

struct ValueAt4_00414970
{
    unsigned int Get(int unused) const { return m_value; }

    int m_unknown0;
    unsigned int m_value;
};

// src: GUESS (confidence: low) [0x00414970]
typedef unsigned int (ValueAt4_00414970::*ValueAt4GetMethod)(int) const;
ValueAt4GetMethod g_ValueAt4_00414970_Get = &ValueAt4_00414970::Get;
