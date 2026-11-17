// Returns the 32-bit field at offset 0x44.

class MemberGetter_00910050
{
public:
    int GetMember() const;

    char pad0[0x44];
    int m_member;
};

int MemberGetter_00910050::GetMember() const
{
    return m_member;
}
