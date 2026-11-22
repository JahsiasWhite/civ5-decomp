// Returns the double stored at offset 0x108 of an object. The owning class isn't
// known yet, so this is a stand-in layout with the value at that offset.

struct Obj_004d6f20
{
    char m_unknown[0x108];
    double m_value;

    double GetValue() const;
};

// src: GUESS (confidence: low) [0x004d6f20]
double Obj_004d6f20::GetValue() const
{
    return m_value;
}
