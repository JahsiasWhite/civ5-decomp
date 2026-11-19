#include "Unk_008db640.h"

void Unk_008db640::SetTarget(int value)
{
    if (g_unk_05f54f34 && m_active && m_target)
        *m_target = value;
}
