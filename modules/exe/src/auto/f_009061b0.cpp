// Returns the byte field at offset 0xc0.

class Fieldc0Holder_009061b0
{
public:
    char GetFieldc0() const;

    char pad0[0xc0];
    char m_fieldc0;
};

char Fieldc0Holder_009061b0::GetFieldc0() const
{
    return m_fieldc0;
}
