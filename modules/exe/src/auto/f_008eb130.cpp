// Returns the 32-bit field at offset 0x48.

class MemberGetter_008eb130
{
public:
    int GetMember() const;

    char pad0[0x48];
    int m_member;
};

int MemberGetter_008eb130::GetMember() const
{
    return m_member;
}
