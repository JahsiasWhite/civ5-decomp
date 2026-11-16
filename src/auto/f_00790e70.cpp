// c5d-model: Gemini 4 Hydrogen
// Returns the address of the member at offset 0x948.

// src: GUESS (confidence: medium)
class MemberAddress_00790e70
{
public:
    // src: GUESS (confidence: medium) [0x00790e70]
    int* GetMember();

    // src: GUESS (confidence: high)
    char pad0[0x948];
    // src: GUESS (confidence: medium)
    int m_member;
};

int* MemberAddress_00790e70::GetMember()
{
    return &m_member;
}
