// Returns the 32-bit value stored at offset 0x4 of an object. The owning
// class isn't known yet (the same body is shared by several classes' vtables), so
// this is a stand-in layout with the value at that offset.

struct Obj_0048f080
{
    char m_unknown[0x4];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x0048f080]
unsigned int Obj_0048f080::GetValue() const
{
    return m_value;
}
