// Returns the address of the member at offset 0x40.

class MemberAddress_0047fc90
{
public:
    int* GetMember();

    char pad0[0x40];
    int m_member;
};

int* MemberAddress_0047fc90::GetMember()
{
    return &m_member;
}
