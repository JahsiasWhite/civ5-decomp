// c5d-model: Gemini 4 Hydrogen
// Returns the difference between the fields at offsets 0x1c and 0x14.

// src: GUESS (confidence: medium)
class Unk_00b89728
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;
    // src: GUESS (confidence: high)
    char m_pad04[0x10];
    // src: GUESS (confidence: medium)
    int m_start14;
    // src: GUESS (confidence: medium)
    int m_field18;
    // src: GUESS (confidence: medium)
    int m_end1C;

    // src: GUESS (confidence: medium) [0x00831020]
    int GetSpan() const;
};

int Unk_00b89728::GetSpan() const
{
    return m_end1C - m_start14;
}
