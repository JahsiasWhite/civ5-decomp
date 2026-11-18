// src: EXE [0x10007160]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/SharedString.h"

namespace Localization {

bool SharedString::SetOffsetAndLength(unsigned int uiOffset, unsigned int uiLength) {
    if (uiOffset + uiLength <= m_BufferLength) {
        m_offset = uiOffset;
        m_length = uiLength;
        return true;
    }
    return false;
}

}  // namespace Localization
