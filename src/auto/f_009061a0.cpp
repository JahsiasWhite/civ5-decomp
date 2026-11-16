// Returns the float field at offset 0xc8.

class Fieldc8Holder_009061a0
{
public:
    float GetFieldc8() const;

    char pad0[0xc8];
    float m_fieldc8;
};

float Fieldc8Holder_009061a0::GetFieldc8() const
{
    return m_fieldc8;
}
