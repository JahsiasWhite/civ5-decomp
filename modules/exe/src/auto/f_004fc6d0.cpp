// c5d-model: Gemini 4 Hydrogen
// Returns the address of the member at offset 0xa0.

// src: GUESS (confidence: medium)
class MemberAddress_00529990
{
public:
    // src: GUESS (confidence: medium) [0x00529990]
    int* GetMember();

    // src: GUESS (confidence: high)
    char pad0[0xa0];
    // src: GUESS (confidence: medium)
    int m_member;
};

int* MemberAddress_00529990::GetMember()
{
    return &m_member;
}
