// src: EXE [0x1000b240]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

unsigned int StringDictionary::GetLanguageCount() const {
    return (unsigned int)m_languages.size();
}

}  // namespace Localization
