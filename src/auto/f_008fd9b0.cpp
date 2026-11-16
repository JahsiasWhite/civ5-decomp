// c5d-model: Gemini 3.8 Flash
// Returns the 32-bit field at offset 0x21c.

// src: GUESS (confidence: medium)
class MemberGetter_008fd9b0
{
public:
    // src: GUESS (confidence: medium) [0x008fd9b0]
    int GetMember() const;

    // src: GUESS (confidence: high)
    char pad0[0x21c];
    // src: GUESS (confidence: medium)
    int m_member;
};

int MemberGetter_008fd9b0::GetMember() const
{
    return m_member;
}
