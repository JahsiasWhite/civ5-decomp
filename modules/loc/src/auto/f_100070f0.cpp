// src: EXE [0x100070f0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/SharedString.h"
#include <cstring>

namespace Localization {

bool SharedString::operator==(const SharedString& kOther) const {
    const char* szOther = kOther.m_spBuffer.get() + kOther.m_offset;
    unsigned int uiLength = m_length;
    if (uiLength == kOther.m_length) {
        const char* szBase = m_spBuffer.get();
        return std::strncmp(szBase + m_offset, szOther, uiLength) == 0;
    }
    return false;
}

}  // namespace Localization
