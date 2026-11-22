// Returns the one-byte value stored at offset 0x3c of an object. The owning class
// isn't known yet, so this is a stand-in layout.

struct Obj_0040f7e0
{
    char m_unknown[0x3c];
    unsigned char m_value;

    unsigned char GetValue() const;
};

// src: GUESS (confidence: low) [0x0040f7e0]
unsigned char Obj_0040f7e0::GetValue() const
{
    return m_value;
}
