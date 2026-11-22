// Returns the 32-bit value stored at offset 0x1c of an object. This body is
// virtual slot 2 of the TBB arena prefix class and is shared with other classes
// whose slot compiles to the same code, so the layout below is a stand-in.

struct Obj_00402930
{
    char m_unknown[0x1c];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x00402930]
unsigned int Obj_00402930::GetValue() const
{
    return m_value;
}
