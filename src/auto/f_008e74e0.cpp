// c5d-model: gemini-3.8-flash
// Returns a pointer to the field at offset 0x70.

#include "UnkRecord70.h"

void* UnkRecord70::GetBuffer70()
{
    return &m_data70;
}
