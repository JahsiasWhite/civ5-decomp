#pragma once
#include <vector>

// Placeholder: a vector of pointers, read by index with a bounds check.
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x0091c050]
class Unk_0091c050
{
public:
    // src: GUESS (confidence: medium) [0x0091c050]
    void* GetAt(unsigned int index);

    std::vector<void*> m_items;     // 0x00
};
