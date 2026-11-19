// Returns the byte field at offset 0x02.

class ByteGetter_0090e150
{
public:
    char GetByte() const;

    char pad0[0x02];
    char m_value;
};

char ByteGetter_0090e150::GetByte() const
{
    return m_value;
}
