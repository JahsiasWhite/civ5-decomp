// Returns the float at offset 0x0c.

class FieldHolder_008e49a0
{
public:
    float GetFloat() const;

    char pad0[0x0c];
    float m_value;
};

float FieldHolder_008e49a0::GetFloat() const
{
    return m_value;
}
