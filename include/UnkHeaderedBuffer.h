#pragma once

// Placeholder layout for an object whose first member points to a buffer that
// starts with a 4-byte header; 0x008337b0 returns the address just past it.
// Rename once the owning class is identified.

class UnkHeaderedBuffer
{
public:
    char* GetDataAfterHeader();

    char* m_pBuffer;
};
