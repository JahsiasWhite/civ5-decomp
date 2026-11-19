#include "Unk_00939b20.h"

// The item at index, or null for a null array or an out-of-range index.
void* PtrArrayGet_00939b20(const UnkPtrArray_00939b20* array, int index)
{
    if (array && index >= 0 && index < array->m_count)
        return array->m_items[index];
    return 0;
}
