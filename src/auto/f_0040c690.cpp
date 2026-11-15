// c5d-model: claude-opus-5-5
// Returns the index of the lowest set bit of a one-byte bit set. The caller
// must make sure at least one bit is set.

class ByteBitSet
{
public:
    int LowestSetBit() const;

private:
    unsigned char m_bits;
};

int ByteBitSet::LowestSetBit() const
{
    unsigned char bits = m_bits;
    int index = 0;
    while (((unsigned char)(bits >> index) & 1) == 0)
        ++index;
    return index;
}
