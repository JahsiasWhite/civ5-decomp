// c5d-model: Gemini 4 Hydrogen
// Returns the 32-bit field at offset 0x758.

// src: GUESS (confidence: medium)
class MemberGetter_006da960
{
public:
    // src: GUESS (confidence: medium) [0x006da960]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0x758];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_006da960::GetMember() const
{
    return m_member;
}
