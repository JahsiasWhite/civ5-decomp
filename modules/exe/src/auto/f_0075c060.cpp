// c5d-model: Gemini 4 Hydrogen
// Returns the address of the member at offset 0x448.

// src: GUESS (confidence: medium)
class MemberAddress_0075c060
{
public:
    // src: GUESS (confidence: medium) [0x0075c060]
    int* GetMember();

    // src: GUESS (confidence: high)
    char pad0[0x448];
    // src: GUESS (confidence: medium)
    int m_member;
};

int* MemberAddress_0075c060::GetMember()
{
    return &m_member;
}
