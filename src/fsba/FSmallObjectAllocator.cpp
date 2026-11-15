// FSmallObjectAllocator members.
#include "FSmallObjectAllocator.h"

static bool s_bAllocationFailed;   // 0x06196fa4

// 0x0081c250, 72 bytes
void* FSmallObjectAllocator::Allocate(unsigned int uiSize)
{
    void* p = m_pAllocators[AlignSize(uiSize) / m_uiGranularity - 1].Allocate();
    if (!p)
        s_bAllocationFailed = true;
    return p;
}

// 0x0081c2a0, 71 bytes
bool FSmallObjectAllocator::IsSmallBlock(const void* p, unsigned int* pSize)
{
    if (p >= m_pRegionBase && p < m_pRegionBase + m_uiRegionSize)
    {
        EnterCriticalSection(&m_cs);
        *pSize = m_pSizeTable[((const char*)p - m_pRegionBase) >> m_iBlockShift];
        LeaveCriticalSection(&m_cs);
        return true;
    }
    return false;
}

// 0x0081c360, 64 bytes
FSmallBlockAllocator* FSmallObjectAllocator::GetAllocatorForSize(unsigned int uiSize)
{
    return FindAllocatorForSize(uiSize);
}
