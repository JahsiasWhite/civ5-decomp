// src: EXE [0x1000b790]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

const char* StringDictionary::Language::GetType() const {
    return m_strType.c_str();
}

}  // namespace Localization
