// Engine allocation helpers. The inline small-object allocation path below is
// expanded at hundreds of call sites in the exe (GetSmallObjectAllocator has
// 329 call sites), which is what shapes the LTCG register conventions of
// FSmallObjectAllocator::GetAllocatorForSize / Allocate (`this` in EDI).
#pragma once
#include <stdlib.h>
#include <new>
#include "FSmallObjectAllocator.h"

// Try the small-block pools first, fall back to the CRT heap.
inline void* FMalloc(size_t uiSize)
{
    FSmallObjectAllocator* pAlloc = GetSmallObjectAllocator(1);
    if (pAlloc && !pAlloc->m_bDisabled && pAlloc->GetAllocatorForSize(uiSize))
    {
        void* p = pAlloc->Allocate(uiSize);
        if (p)
            return p;
    }
    return malloc(uiSize);
}

// `new T` through FMalloc. The exe's allocation sites have no exception
// cleanup, which rules out a class operator new and std placement new (both
// have a matching operator delete, so /EHsc adds an unwind frame). A tagged
// placement new with no matching delete produces no cleanup.
struct FNewTag {};
inline void* operator new(size_t, void* p, FNewTag) { return p; }
#define FNEW(T) new (FMalloc(sizeof(T)), FNewTag()) T
