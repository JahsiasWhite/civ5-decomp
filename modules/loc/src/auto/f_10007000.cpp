// src: EXE [0x10007000]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/SharedString.h"

namespace Localization {

SharedString::SharedString()
    : m_spBuffer()
    , m_BufferLength(0)
    , m_offset(0)
    , m_length(0) {
}

}  // namespace Localization
