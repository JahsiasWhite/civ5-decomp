// Firaxis small-block allocator ("FSBA"). Layout reconstructed from
// CivilizationV_DX11.exe; only the fields we have evidence for are named.
#pragma once
#include <windows.h>

// One fixed-size block pool; FSmallObjectAllocator owns an array of these.
class FSmallBlockAllocator
{
public:
    void* Allocate();                       // 0x0081be80 (this in EAX under LTCG)

    char _unk000[0x40];
};

class FSmallObjectAllocator
{
public:
    // 0x0081c2a0. Internal; under LTCG it receives `this` in EDI and `p` in EAX.
    // If p lies in the small-block region, stores its size-table entry and returns true.
    bool IsSmallBlock(const void* p, unsigned int* pSize);

    // 0x0081c360. NULL if no pool handles this size.
    FSmallBlockAllocator* GetAllocatorForSize(unsigned int uiSize);

    // 0x0081c250. Caller must have checked GetAllocatorForSize first.
    void* Allocate(unsigned int uiSize);

    // Inline version of GetAllocatorForSize (FSBAHasAllocatorForSize inlines it).
    inline FSmallBlockAllocator* FindAllocatorForSize(unsigned int uiSize)
    {
        unsigned int uiIndex = AlignSize(uiSize) / m_uiGranularity - 1;
        if (uiIndex < m_uiNumAllocators)
            return &m_pAllocators[uiIndex];
        return NULL;
    }

    // Round up to the pool granularity (minimum 2 bytes).
    inline unsigned int AlignSize(unsigned int uiSize) const
    {
        if (uiSize == 0)
            uiSize = 1;
        if (uiSize & (m_uiGranularity - 1))
            uiSize = (uiSize & ~(m_uiGranularity - 1)) + m_uiGranularity;
        if (uiSize < 2)
            uiSize = 2;
        return uiSize;
    }

    FSmallBlockAllocator* m_pAllocators;    // +0x00  m_uiNumAllocators pools, 0x40 bytes each
    char*            m_pRegionBase;         // +0x04
    unsigned short*  m_pSizeTable;          // +0x08  one entry per (1 << m_iBlockShift) bytes
    char             _unk00c[0x28 - 0x0c];
    CRITICAL_SECTION m_cs;                  // +0x28
    unsigned int     m_uiRegionSize;        // +0x40
    char             _unk044[0x70 - 0x44];
    int              m_iBlockShift;         // +0x70
    char             _unk074[0x8c - 0x74];
    unsigned int     m_uiMaxAllocatorSize;  // +0x8c  (FSBAGetMaxAllocatorSize)
    unsigned int     m_uiGranularity;       // +0x90  power of two
    char             _unk094[0xb4 - 0x94];
    unsigned int     m_uiNumAllocators;     // +0xb4
    bool             m_bDisabled;           // +0xb8  (FSBADisable / FSBAIsDisabled)
};

// 0x00813750. Called as GetSmallObjectAllocator(1); the argument is most
// likely "create if missing". int vs bool is not yet confirmed.
extern "C" FSmallObjectAllocator* GetSmallObjectAllocator(int bCreate);
