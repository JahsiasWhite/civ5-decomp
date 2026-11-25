// src: EXE [0x1000b7b0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

PluralityRule* StringDictionary::Language::GetPluralityRule() const {
    return reinterpret_cast<PluralityRule*>(m_ePluralityRule);
}

}  // namespace Localization
