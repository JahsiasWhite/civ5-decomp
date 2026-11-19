// Returns the bool flag at offset 0x0c.

class FieldHolder_007d8970
{
public:
    bool GetFlag() const;

    char pad0[0x0c];
    bool m_value;
};

bool FieldHolder_007d8970::GetFlag() const
{
    return m_value;
}
