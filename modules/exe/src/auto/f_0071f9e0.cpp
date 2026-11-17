// Returns the dword at offset 0x14.

class FieldHolder_0071f9e0
{
public:
    int GetValue() const;

    char pad0[0x14];
    int m_value;
};

int FieldHolder_0071f9e0::GetValue() const
{
    return m_value;
}
