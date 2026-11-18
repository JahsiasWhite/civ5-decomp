// Sorts the array of 4-byte items with its comparison function, once.

extern "C" void __cdecl qsort(void* base, unsigned int count, unsigned int size,
    int (__cdecl* compare)(const void*, const void*));

// src: GUESS (confidence: low)
struct SortedArray_00939b70
{
    // src: GUESS (confidence: low)
    unsigned int m_count;
    // src: GUESS (confidence: low)
    void* m_items;
    // src: GUESS (confidence: low)
    int m_sorted;
    int m_0c;
    // src: GUESS (confidence: low)
    int (__cdecl* m_compare)(const void*, const void*);
};

// src: GUESS (confidence: low) [0x00939b70]
void EnsureSorted_00939b70(SortedArray_00939b70* array)
{
    if (array && !array->m_sorted)
    {
        qsort(array->m_items, array->m_count, 4, array->m_compare);
        array->m_sorted = 1;
    }
}
