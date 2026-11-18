// src: EXE [0x1000b2c0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

const StringDictionary::Language& StringDictionary::GetLanguage(unsigned int uiIndex) const {
    return m_languages[uiIndex];
}

}  // namespace Localization
