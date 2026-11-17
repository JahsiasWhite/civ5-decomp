// Returns the address of the member at offset 0x0c.

class MemberAddress_008fd2b0
{
public:
    int* GetMember();

    char pad0[0x0c];
    int m_member;
};

int* MemberAddress_008fd2b0::GetMember()
{
    return &m_member;
}
