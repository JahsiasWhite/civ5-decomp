// Returns the dword at offset 0x24.

class FieldHolder_005a5fc0
{
public:
    int GetValue() const;

    char pad0[0x24];
    int m_value;
};

int FieldHolder_005a5fc0::GetValue() const
{
    return m_value;
}
