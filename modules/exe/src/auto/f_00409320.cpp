// Returns the 32-bit value stored at offset 0x138 of an object. The owning class
// isn't known yet, so this is a stand-in layout with the value at that offset.

struct Obj_00409320
{
    char m_unknown[0x138];
    unsigned int m_value;

    unsigned int GetValue() const;
};

// src: GUESS (confidence: low) [0x00409320]
unsigned int Obj_00409320::GetValue() const
{
    return m_value;
}
