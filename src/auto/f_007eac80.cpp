// Returns the dword at offset 0x40.

class FieldHolder_007eac80
{
public:
    int GetValue() const;

    char pad0[0x40];
    int m_value;
};

int FieldHolder_007eac80::GetValue() const
{
    return m_value;
}
