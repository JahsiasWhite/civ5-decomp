// src: EXE [0x100099a0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

unsigned int String::GetPlurality(unsigned int uiForm) const {
    if (uiForm - 1 < (unsigned int)m_forms.size()) {
        return m_forms[uiForm - 1].m_uiPlurality;
    }
    return 0;
}

}  // namespace Localization
