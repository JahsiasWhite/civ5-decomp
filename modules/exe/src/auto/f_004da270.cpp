#include "Unk_004572c0.h"

void UnkTrackedFloat_004572c0::SetValue(float value)
{
    m_previous = m_current;
    m_current = value;
}
