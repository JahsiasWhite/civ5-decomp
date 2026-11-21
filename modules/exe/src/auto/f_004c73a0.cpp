// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct UnkVecElem12_004c73a0
{
    int a;
    int b;
    int c;
};

// src: LIB [0x004c73a0]
struct UnkVec12_004c73a0
{
    int m_pad;
    UnkVecElem12_004c73a0* m_first;
    UnkVecElem12_004c73a0* m_last;

    UnkVecElem12_004c73a0** EraseRange_004c73a0(UnkVecElem12_004c73a0** out, UnkVecElem12_004c73a0* first, UnkVecElem12_004c73a0* last);
};

UnkVecElem12_004c73a0** UnkVec12_004c73a0::EraseRange_004c73a0(UnkVecElem12_004c73a0** out, UnkVecElem12_004c73a0* first, UnkVecElem12_004c73a0* last)
{
    *out = first;
    if (first != last)
    {
        UnkVecElem12_004c73a0* end = m_last;
        for (UnkVecElem12_004c73a0* p = last; p != end; ++p, ++first)
            *first = *p;
        m_last = first;
    }
    return out;
}
