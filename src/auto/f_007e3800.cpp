// Returns the address of the member at offset 0x44.

class MemberAddress_007e3800
{
public:
    int* GetMember();

    char pad0[0x44];
    int m_member;
};

int* MemberAddress_007e3800::GetMember()
{
    return &m_member;
}
