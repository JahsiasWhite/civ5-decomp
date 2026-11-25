// src: EXE [0x1000b110]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/StringDictionary.h"

namespace Localization {

unsigned int StringDictionary::GetCurrentLanguageIndex() const {
    return m_uiCurrentLanguageIndex;
}

}  // namespace Localization
