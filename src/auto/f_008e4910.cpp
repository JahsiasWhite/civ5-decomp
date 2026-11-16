// Returns the address of the member at offset 0x30.

class MemberAddress_008e4910
{
public:
    int* GetMember();

    char pad0[0x30];
    int m_member;
};

int* MemberAddress_008e4910::GetMember()
{
    return &m_member;
}
