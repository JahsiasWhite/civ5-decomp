// Returns the address of the member at offset 0x3c.

class MemberAddress_0062e8a0
{
public:
    int* GetMember();

    char pad0[0x3c];
    int m_member;
};

int* MemberAddress_0062e8a0::GetMember()
{
    return &m_member;
}
