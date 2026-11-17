// Returns the dword at offset 0x38.

class FieldHolder_005c3e30
{
public:
    int GetValue() const;

    char pad0[0x38];
    int m_value;
};

int FieldHolder_005c3e30::GetValue() const
{
    return m_value;
}
