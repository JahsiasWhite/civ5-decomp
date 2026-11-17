// Returns the dword at offset 0x1c.

class FieldHolder_0048f990
{
public:
    int GetValue() const;

    char pad0[0x1c];
    int m_value;
};

int FieldHolder_0048f990::GetValue() const
{
    return m_value;
}
