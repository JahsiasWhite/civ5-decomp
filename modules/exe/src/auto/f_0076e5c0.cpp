// Returns the dword at offset 0x04.

class FieldHolder_0076e5c0
{
public:
    int GetValue() const;

    char pad0[0x04];
    int m_value;
};

int FieldHolder_0076e5c0::GetValue() const
{
    return m_value;
}
