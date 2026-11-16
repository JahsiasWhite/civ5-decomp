// Returns the address of the member at offset 0x4c.

class MemberAddress_008e6f70
{
public:
    int* GetMember();

    char pad0[0x4c];
    int m_member;
};

int* MemberAddress_008e6f70::GetMember()
{
    return &m_member;
}
