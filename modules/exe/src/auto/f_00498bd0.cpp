// Constructs two counters and four empty arrays (begin/end/capacity).

// src: GUESS (confidence: low)
struct PtrArray_00498bd0
{
    PtrArray_00498bd0()
    {
        m_end = 0;
        m_capacity = 0;
        m_begin = 0;
    }

    int* m_begin;
    int* m_end;
    int* m_capacity;
};

// src: GUESS (confidence: low)
struct ArraySet_00498bd0
{
    // src: GUESS (confidence: low) [0x00498bd0]
    ArraySet_00498bd0();

    int m_a;
    int m_b;
    PtrArray_00498bd0 m_first;
    PtrArray_00498bd0 m_second;
    PtrArray_00498bd0 m_third;
    PtrArray_00498bd0 m_fourth;
};

ArraySet_00498bd0::ArraySet_00498bd0()
    : m_a(0)
    , m_b(0)
{
}
