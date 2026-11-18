// src: EXE [0x1000b290]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

const char* StringDictionary::GetLanguageDisplayName(unsigned int uiIndex) const {
    return m_languages[uiIndex].m_strDisplayName.c_str();
}

}  // namespace Localization
