// Returns the dword at offset 0x10; shared by getters in many classes.

class FieldHolder_00585400
{
public:
    int GetValue() const;

    char pad0[0x10];
    int m_value;
};

int FieldHolder_00585400::GetValue() const
{
    return m_value;
}
