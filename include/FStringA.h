// FireWorks' narrow string: one pointer to its characters, with the block header
// (capacity, length, flags) just in front of them. Only the layout is declared so far.
#pragma once

// src: GUESS (confidence: high)
class FStringA
{
public:
    // src: GUESS (confidence: medium)
    struct Header
    {
        int m_iCapacity;
        int m_iLength;
        short m_sField08;
        short m_sNoFree;
    };

    // src: GUESS (confidence: medium) [0x008151a0]
    int Find(char ch, int iStart) const;

    // src: GUESS (confidence: high)
    char* m_pszData;
};
