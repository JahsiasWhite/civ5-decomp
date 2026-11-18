// src: GUESS (confidence: low)
struct RefObj_008ee660
{
    int m_pad00;
    int m_refCount;
};

// src: GUESS (confidence: low)
struct UnkPair_008ee660
{
    RefObj_008ee660* m_ptr;
    int m_val;
};

// src: GUESS (confidence: high) [0x008ee660]
UnkPair_008ee660* CopyRange_008ee660(const UnkPair_008ee660* first, const UnkPair_008ee660* last, UnkPair_008ee660* dst)
{
    while (first != last)
    {
        if (dst)
        {
            RefObj_008ee660* p = first->m_ptr;
            dst->m_ptr = p;
            if (p)
            {
                ++p->m_refCount;
            }
            dst->m_val = first->m_val;
        }
        ++first;
        ++dst;
    }
    return dst;
}
