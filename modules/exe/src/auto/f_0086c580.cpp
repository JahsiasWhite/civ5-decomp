// Returns the byte field at offset 0xe0.

class Fielde0Holder_009067b0
{
public:
    char GetFielde0() const;

    char pad0[0xe0];
    char m_fielde0;
};

char Fielde0Holder_009067b0::GetFielde0() const
{
    return m_fielde0;
}
