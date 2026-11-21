// src: GUESS (confidence: low)
struct UnkPair8_004b46a0
{
    int a;
    int b;

    bool Equals(const UnkPair8_004b46a0& other) const
    {
        return other.a == a && other.b == b;
    }

    bool NotEquals_004b46a0(const UnkPair8_004b46a0& other) const;
};

// src: GUESS (confidence: medium) [0x004b46a0]
bool UnkPair8_004b46a0::NotEquals_004b46a0(const UnkPair8_004b46a0& other) const
{
    return !Equals(other);
}
