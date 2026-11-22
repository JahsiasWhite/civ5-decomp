// Returns the 32-bit value stored at offset 0x10 of an object. The owning
// class isn't known yet (the same body is shared by several classes' vtables), so
// this is a stand-in layout with the value at that offset.

struct Obj_0048bde0
{
    char m_unknown[0x10];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x0048bde0]
unsigned int Obj_0048bde0::GetValue() const
{
    return m_value;
}
