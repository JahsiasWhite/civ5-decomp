// Returns the dword at offset 0x20.

class FieldHolder_00558220
{
public:
    int GetValue() const;

    char pad0[0x20];
    int m_value;
};

int FieldHolder_00558220::GetValue() const
{
    return m_value;
}
