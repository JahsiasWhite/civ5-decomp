// src: EXE [0x10008f00]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

bool String::SetLanguage(Language* pkLanguage) {
    m_pkLanguage = pkLanguage;
    return true;
}

}  // namespace Localization
