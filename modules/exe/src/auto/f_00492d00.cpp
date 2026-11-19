// c5d-model: Gemini 4 Hydrogen
// Returns the 32-bit field at offset 0x6e4.

// src: GUESS (confidence: medium)
class MemberGetter_00433a70
{
public:
    // src: GUESS (confidence: medium) [0x00433a70]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0x6e4];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_00433a70::GetMember() const
{
    return m_member;
}
