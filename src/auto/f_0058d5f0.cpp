// c5d-model: Gemini 4 Hydrogen
// Returns the 32-bit field at offset 0x40c08.

// src: GUESS (confidence: medium)
class MemberGetter_0058d5f0
{
public:
    // src: GUESS (confidence: medium) [0x0058d5f0]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0x40c08];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_0058d5f0::GetMember() const
{
    return m_member;
}
