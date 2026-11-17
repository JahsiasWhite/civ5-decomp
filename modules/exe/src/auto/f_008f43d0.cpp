// c5d-model: Gemini 3.8 Flash
// Returns the 32-bit field at offset 0x84.

// src: GUESS (confidence: medium)
class MemberGetter_008f43d0
{
public:
    // src: GUESS (confidence: medium) [0x008f43d0]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0x84];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_008f43d0::GetMember() const
{
    return m_member;
}
