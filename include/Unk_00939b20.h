#pragma once

// Placeholder: a counted pointer array (count at 0x00, items at 0x04).
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x00939b20]
struct UnkPtrArray_00939b20
{
    int m_count;
    void** m_items;
};

// src: GUESS (confidence: medium) [0x00939b20]
void* PtrArrayGet_00939b20(const UnkPtrArray_00939b20* array, int index);
