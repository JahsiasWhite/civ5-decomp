#include "Unk_00a99d74.h"

bool Unk_00a99d74::ReleaseOwned()
{
    delete m_owned;
    m_owned = 0;
    return true;
}
