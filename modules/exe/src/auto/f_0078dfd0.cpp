// Resolves a self-relative offset stored in the object: returns the address
// that lies m_selfOffset bytes past the start of the object.

// src: GUESS (confidence: low) [0x0078dfd0]
class SelfRelativeBlock
{
public:
    // src: GUESS (confidence: low) [0x0078dfd0]
    char* GetRelativePtr();

    char m_pad0[0x38c];
    // src: GUESS (confidence: low)
    int m_selfOffset;
};

char* SelfRelativeBlock::GetRelativePtr()
{
    return reinterpret_cast<char*>(this) + m_selfOffset;
}
