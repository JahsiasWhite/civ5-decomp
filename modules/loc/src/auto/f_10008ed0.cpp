// src: EXE [0x10008ed0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

const char* String::GetBaseString(unsigned int& ruiLength) const {
    ruiLength = m_kBaseString.m_length;
    return m_kBaseString.m_spBuffer.get() + m_kBaseString.m_offset;
}

}  // namespace Localization
