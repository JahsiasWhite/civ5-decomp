// Constructs four empty arrays (begin/end/capacity) and clears three
// counters.

// src: GUESS (confidence: low)
struct PtrArray_00754d20
{
    PtrArray_00754d20()
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
struct Tables_00754d20
{
    // src: GUESS (confidence: low) [0x00754d20]
    Tables_00754d20();

    PtrArray_00754d20 m_first;
    int m_0c;
    int m_10;
    int m_14;
    char m_pad18[0x34 - 0x18];
    PtrArray_00754d20 m_second;
    PtrArray_00754d20 m_third;
    PtrArray_00754d20 m_fourth;
};

Tables_00754d20::Tables_00754d20()
    : m_0c(0)
    , m_10(0)
    , m_14(0)
{
}
