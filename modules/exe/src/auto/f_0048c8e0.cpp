// Returns the 32-bit value stored at offset 0xc of an object. The owning
// class isn't known yet (the same body is shared by several classes' vtables), so
// this is a stand-in layout with the value at that offset.

struct Obj_0048c8e0
{
    char m_unknown[0xc];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x0048c8e0]
unsigned int Obj_0048c8e0::GetValue() const
{
    return m_value;
}
