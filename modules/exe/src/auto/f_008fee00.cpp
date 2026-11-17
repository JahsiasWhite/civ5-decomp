// Returns the 32-bit field at offset 0x40.

class MemberGetter_008fee00
{
public:
    int GetMember() const;

    char pad0[0x40];
    int m_member;
};

int MemberGetter_008fee00::GetMember() const
{
    return m_member;
}
