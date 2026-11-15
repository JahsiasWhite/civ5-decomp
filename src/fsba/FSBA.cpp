// Exported FSBA entry points (CivilizationV_DX11.exe 0x00813920..0x00813a2f)
// STATUS: FSBADisable, FSBAIsDisabled, FSBAGetMaxAllocatorSize and
// FSBAPreventCreation MATCH byte for byte (cl 15.00.30729.01, flags in config.json).
#include "FSmallObjectAllocator.h"

static bool s_bPreventCreation;   // 0x06196937

// 0x00813870, 57 bytes
extern "C" void* FSBAAllocate(unsigned int uiSize)
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc && !pAlloc->m_bDisabled && pAlloc->GetAllocatorForSize(uiSize))
        return pAlloc->Allocate(uiSize);
    return NULL;
}

// 0x00813990, 111 bytes
extern "C" bool FSBAHasAllocatorForSize(unsigned int uiSize)
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc)
        return pAlloc->FindAllocatorForSize(uiSize) != NULL;
    return false;
}

// 0x00813920, 25 bytes
extern "C" void FSBADisable(bool bDisable)
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc)
        pAlloc->m_bDisabled = bDisable;
}

// 0x00813940, 24 bytes
extern "C" bool FSBAIsDisabled()
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc)
        return pAlloc->m_bDisabled;
    return true;
}

// 0x00813a00, 24 bytes
extern "C" unsigned int FSBAGetMaxAllocatorSize()
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc)
        return pAlloc->m_uiMaxAllocatorSize;
    return 0;
}

// 0x00813a20, 16 bytes
extern "C" bool FSBAPreventCreation(bool bPrevent)
{
    bool bOld = s_bPreventCreation;
    s_bPreventCreation = bPrevent;
    return bOld;
}

// 0x00813960, 37 bytes. Calls IsSmallBlock with `this` in EDI and `p` in
// EAX: an LTCG custom calling convention, so this only matches in ltcg mode.
extern "C" bool FSBAIsSmallBlock(const void* p, unsigned int* pSize)
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc)
        return pAlloc->IsSmallBlock(p, pSize);
    return false;
}
