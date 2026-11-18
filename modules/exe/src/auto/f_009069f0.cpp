#include "Unk_009069f0.h"

bool UnkQueryOwner_009069f0::Query()
{
    if (!m_enabled)
        return false;
    return m_target->Query();
}
