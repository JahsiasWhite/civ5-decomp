// src: EXE [0x10008da0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

bool String::IsEmpty() const {
    return m_kBaseString.m_length == 0;
}

}  // namespace Localization
