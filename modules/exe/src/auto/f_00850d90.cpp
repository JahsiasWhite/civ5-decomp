// Returns the address of the member at offset 0x10.

class MemberAddress_00787b70
{
public:
    int* GetMember();

    char pad0[0x10];
    int m_member;
};

int* MemberAddress_00787b70::GetMember()
{
    return &m_member;
}
