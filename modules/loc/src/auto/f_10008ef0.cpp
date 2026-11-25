// src: EXE [0x10008ef0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

Language* String::GetLanguage() const {
    return m_pkLanguage;
}

}  // namespace Localization
