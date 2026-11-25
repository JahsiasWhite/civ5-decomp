// src: EXE [0x10007130]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/SharedString.h"

namespace Localization {

const char* SharedString::GetBuffer(unsigned int& ruiBufferLength) const {
    ruiBufferLength = m_BufferLength;
    return m_spBuffer.get();
}

}  // namespace Localization
