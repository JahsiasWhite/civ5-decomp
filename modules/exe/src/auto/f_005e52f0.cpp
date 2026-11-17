// Returns the address of the member at offset 0x08.

class MemberAddress_005e52f0
{
public:
    int* GetMember();

    char pad0[0x08];
    int m_member;
};

int* MemberAddress_005e52f0::GetMember()
{
    return &m_member;
}
