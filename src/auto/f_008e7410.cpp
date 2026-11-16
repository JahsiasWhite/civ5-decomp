// c5d-model: gemini-3.8-flash
// Returns a pointer to the field at offset 0x4.

#include "UnkRecord04.h"

void* UnkRecord04::GetBuffer04()
{
    return &m_data04;
}
