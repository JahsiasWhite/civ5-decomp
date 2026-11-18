#pragma once
#include <vector>

// Placeholder: an object with a vector of pointers at 0x40, read by index with
// a bounds check. Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008ed270]
class Unk_008ed270
{
public:
    // src: GUESS (confidence: medium) [0x008ed270]
    void* GetAt(unsigned int index);

    char m_unk00[0x40];
    std::vector<void*> m_items;     // 0x40
};
