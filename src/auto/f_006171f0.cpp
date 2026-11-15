// c5d-model: claude-opus-5-5
// Returns nonzero when the value at offset 0x20 exceeds the threshold at offset 0x28.

class FloatRangeObject
{
public:
    int IsAboveThreshold() const;

    char pad0[0x20];
    float m_fValue;
    float pad24;
    float m_fThreshold;
};

int FloatRangeObject::IsAboveThreshold() const
{
    if (m_fValue > m_fThreshold)
        return 1;
    return 0;
}
