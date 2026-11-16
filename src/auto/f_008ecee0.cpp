// c5d-model: Gemini 3.8 Flash
// Returns the address of the member at offset 0xa8.

// src: GUESS (confidence: medium)
class MemberAddress_008ecee0
{
public:
    // src: GUESS (confidence: medium) [0x008ecee0]
    int* GetMember();

    // src: GUESS (confidence: high)
    char pad0[0xa8];
    // src: GUESS (confidence: medium)
    int m_member;
};

int* MemberAddress_008ecee0::GetMember()
{
    return &m_member;
}
