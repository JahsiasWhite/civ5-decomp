#include "Unk_00905010.h"

void UnkPair_00905010::Swap(UnkPair_00905010& other)
{
    int first = m_first;
    int second = m_second;
    m_first = other.m_first;
    m_second = other.m_second;
    other.m_second = second;
    other.m_first = first;
}
