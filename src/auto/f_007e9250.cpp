// Returns the dword at offset 0x24.

class FieldHolder_007e9250
{
public:
    int GetValue() const;

    char pad0[0x24];
    int m_value;
};

int FieldHolder_007e9250::GetValue() const
{
    return m_value;
}
