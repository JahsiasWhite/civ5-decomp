// c5d-model: gemini-3.8-flash
// Returns the 32-bit field at offset 0x30.

#include "UnkRecord30.h"

int UnkRecord30::GetField30() const
{
    return m_data30;
}
