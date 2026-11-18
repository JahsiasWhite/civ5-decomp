// src: EXE [0x10009630]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

Gender String::GetGender(unsigned int uiForm) const {
    if (uiForm - 1 < (unsigned int)m_forms.size()) {
        return m_forms[uiForm - 1].m_eGender;
    }
    return GENDER_NONE;
}

}  // namespace Localization
