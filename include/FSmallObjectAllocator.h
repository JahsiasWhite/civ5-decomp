// Firaxis small-block allocator ("FSBA"). Layout reconstructed from
// CivilizationV_DX11.exe; only the fields we have evidence for are named.
#pragma once

struct FSmallObjectAllocator
{
    char          _unk000[0x8c];
    unsigned int  m_uiMaxAllocatorSize;   // +0x8c  (FSBAGetMaxAllocatorSize)
    char          _unk090[0xb8 - 0x90];
    bool          m_bDisabled;            // +0xb8  (FSBADisable / FSBAIsDisabled)
};

// 0x00813750. Called as GetSmallObjectAllocator(1); the argument is most
// likely "create if missing". int vs bool is not yet confirmed.
extern "C" FSmallObjectAllocator* GetSmallObjectAllocator(int bCreate);
