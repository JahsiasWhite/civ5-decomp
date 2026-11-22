// Returns the 32-bit value stored at offset 0x2c of an object. The owning
// class isn't known yet (the same body is shared by several classes' vtables), so
// this is a stand-in layout with the value at that offset.

struct Obj_00797260
{
    char m_unknown[0x2c];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x00797260]
unsigned int Obj_00797260::GetValue() const
{
    return m_value;
}
