// c5d-model: Gemini 4 Hydrogen
// Returns the 32-bit field at offset 0xc8.

// src: GUESS (confidence: medium)
class MemberGetter_007a72b0
{
public:
    // src: GUESS (confidence: medium) [0x007a72b0]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0xc8];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_007a72b0::GetMember() const
{
    return m_member;
}
