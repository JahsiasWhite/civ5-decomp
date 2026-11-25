// src: EXE [0x10007140]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/SharedString.h"

namespace Localization {

const char* SharedString::GetString(unsigned int& ruiLength) const {
    ruiLength = m_length;
    return m_spBuffer.get() + m_offset;
}

}  // namespace Localization
