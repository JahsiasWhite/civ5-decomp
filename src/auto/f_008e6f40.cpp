// Returns the address of the member at offset 0x2c.

class MemberAddress_008e6f40
{
public:
    int* GetMember();

    char pad0[0x2c];
    int m_member;
};

int* MemberAddress_008e6f40::GetMember()
{
    return &m_member;
}
