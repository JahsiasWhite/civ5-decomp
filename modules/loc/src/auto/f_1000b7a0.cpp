// src: EXE [0x1000b7a0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

const char* StringDictionary::Language::GetDisplayName() const {
    return m_strDisplayName.c_str();
}

}  // namespace Localization
