// Returns the bool flag at offset 0x0f.

class FieldHolder_0047f5d0
{
public:
    bool GetFlag() const;

    char pad0[0x0f];
    bool m_value;
};

bool FieldHolder_0047f5d0::GetFlag() const
{
    return m_value;
}
