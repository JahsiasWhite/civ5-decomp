// Returns the bool flag at offset 0x08.

class FieldHolder_0073c070
{
public:
    bool GetFlag() const;

    char pad0[0x08];
    bool m_value;
};

bool FieldHolder_0073c070::GetFlag() const
{
    return m_value;
}
