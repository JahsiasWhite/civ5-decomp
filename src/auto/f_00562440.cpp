// c5d-model: Gemini 4 Hydrogen
// Returns the byte field at offset 0x1be of CvUserInterfaceImpl.

#include "CvUserInterfaceImpl.h"

char CvUserInterfaceImpl::GetFlag1BE() const
{
    return m_flag1BE;
}
