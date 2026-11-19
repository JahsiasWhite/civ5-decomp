// Returns the dword at offset 0x4c.

class FieldHolder_005e59b0
{
public:
    int GetValue() const;

    char pad0[0x4c];
    int m_value;
};

int FieldHolder_005e59b0::GetValue() const
{
    return m_value;
}
