// Returns the dword at offset 0x50.

class FieldHolder_00711e60
{
public:
    int GetValue() const;

    char pad0[0x50];
    int m_value;
};

int FieldHolder_00711e60::GetValue() const
{
    return m_value;
}
