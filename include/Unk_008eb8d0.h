#pragma once
#include <vector>

// Placeholder: an object with a vector of pointers at 0x1394. Rename once the
// owning type is known.

// src: GUESS (confidence: low) [0x008eb8d0]
class Unk_008eb8d0
{
public:
    // src: GUESS (confidence: medium) [0x008eb8d0]
    void** GetItems();

    char m_unk0000[0x1394];
    std::vector<void*> m_items;     // 0x1394
};
