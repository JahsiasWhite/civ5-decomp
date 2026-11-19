// Constructs four empty arrays (begin/end/capacity pointers) and a count.

// src: GUESS (confidence: low)
struct PtrArray_0051b030
{
    PtrArray_0051b030()
    {
        m_end = 0;
        m_capacity = 0;
        m_begin = 0;
    }

    // src: GUESS (confidence: low)
    int* m_begin;
    // src: GUESS (confidence: low)
    int* m_end;
    // src: GUESS (confidence: low)
    int* m_capacity;
};

// src: GUESS (confidence: low)
struct ArraySet_0051b030
{
    // src: GUESS (confidence: low) [0x0051b030]
    ArraySet_0051b030();

    PtrArray_0051b030 m_a;
    PtrArray_0051b030 m_b;
    PtrArray_0051b030 m_c;
    PtrArray_0051b030 m_d;
    // src: GUESS (confidence: low)
    int m_count;
};

ArraySet_0051b030::ArraySet_0051b030()
{
    m_count = 0;
}
