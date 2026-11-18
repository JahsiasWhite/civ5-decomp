// src: EXE [0x1000b260]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

const char* StringDictionary::GetLanguageType(unsigned int uiIndex) const {
    return m_languages[uiIndex].m_strType.c_str();
}

}  // namespace Localization
