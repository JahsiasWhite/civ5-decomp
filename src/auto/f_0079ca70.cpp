// Returns the address of the member at offset 0x64.

class MemberAddress_0079ca70
{
public:
    int* GetMember();

    char pad0[0x64];
    int m_member;
};

int* MemberAddress_0079ca70::GetMember()
{
    return &m_member;
}
