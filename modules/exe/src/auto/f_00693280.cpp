// Returns the dword at offset 0x08.

class FieldHolder_00712c10
{
public:
    int GetValue() const;

    char pad0[0x08];
    int m_value;
};

int FieldHolder_00712c10::GetValue() const
{
    return m_value;
}
