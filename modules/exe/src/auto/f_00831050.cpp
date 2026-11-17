// Returns the dword at offset 0x14.

class FieldHolder_00831050
{
public:
    int GetValue() const;

    char pad0[0x14];
    int m_value;
};

int FieldHolder_00831050::GetValue() const
{
    return m_value;
}
