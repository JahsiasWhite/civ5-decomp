// Returns the dword at offset 0x18.

class FieldHolder_00717ec0
{
public:
    int GetValue() const;

    char pad0[0x18];
    int m_value;
};

int FieldHolder_00717ec0::GetValue() const
{
    return m_value;
}
