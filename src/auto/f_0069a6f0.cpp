// c5d-model: Gemini 4 Hydrogen
// Returns the 32-bit field at offset 0x934.

// src: GUESS (confidence: medium)
class MemberGetter_0069a6f0
{
public:
    // src: GUESS (confidence: medium) [0x0069a6f0]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0x934];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_0069a6f0::GetMember() const
{
    return m_member;
}
