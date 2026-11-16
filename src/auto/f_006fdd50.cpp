// Returns the address of the member at offset 0x74.

class MemberAddress_006fdd50
{
public:
    int* GetMember();

    char pad0[0x74];
    int m_member;
};

int* MemberAddress_006fdd50::GetMember()
{
    return &m_member;
}
