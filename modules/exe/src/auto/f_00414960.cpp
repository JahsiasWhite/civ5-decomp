// Returns the 32-bit value stored at the start of an object. The owning class
// isn't known yet, so this is a stand-in layout.

struct Obj_00414960
{
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x00414960]
unsigned int Obj_00414960::GetValue() const
{
    return m_value;
}
