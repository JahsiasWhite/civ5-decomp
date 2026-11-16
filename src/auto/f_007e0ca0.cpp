// Returns the bool flag at offset 0x4c.

class FieldHolder_007e0ca0
{
public:
    bool GetFlag() const;

    char pad0[0x4c];
    bool m_value;
};

bool FieldHolder_007e0ca0::GetFlag() const
{
    return m_value;
}
