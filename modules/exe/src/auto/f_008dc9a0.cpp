// Returns the address of the member at offset 0x18.

class MemberAddress_008dc9a0
{
public:
    int* GetMember();

    char pad0[0x18];
    int m_member;
};

int* MemberAddress_008dc9a0::GetMember()
{
    return &m_member;
}
