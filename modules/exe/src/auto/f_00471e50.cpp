// src: GUESS (confidence: low)
struct Unk260_00471e50
{
    int m_d[65];
};

// src: GUESS (confidence: high) [0x00471e50]
Unk260_00471e50* CopyRange_00471e50(const Unk260_00471e50* first, const Unk260_00471e50* last, Unk260_00471e50* dst)
{
    while (first != last)
    {
        if (dst)
        {
            *dst = *first;
        }
        ++first;
        ++dst;
    }
    return dst;
}
