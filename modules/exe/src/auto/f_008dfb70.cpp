// Returns the address of the member at offset 0x14.

class MemberAddress_008dfb70
{
public:
    int* GetMember();

    char pad0[0x14];
    int m_member;
};

int* MemberAddress_008dfb70::GetMember()
{
    return &m_member;
}
