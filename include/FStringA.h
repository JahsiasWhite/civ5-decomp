// FireWorks' narrow string: one pointer to its characters, with the block header
// (capacity, length, flags) just in front of them. Only the layout is declared so far.
#pragma once

// src: GUESS (confidence: high)
class FStringA
{
public:
    // src: GUESS (confidence: high)
    char* m_pszData;
};
