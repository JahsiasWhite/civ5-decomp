// Returns the 32-bit value stored at offset 0x22c of an object. This is virtual
// slot 8 of the file I/O class's vtable and is shared with another class, so the
// layout below is a stand-in with the value at that offset.

struct Obj_004442a0
{
    char m_unknown[0x22c];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x004442a0]
unsigned int Obj_004442a0::GetValue() const
{
    return m_value;
}
