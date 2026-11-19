// c5d-cflags: -/EHsc +/GS-
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

// src: EXE [0x100095e0]
bool String::SetGender(unsigned int uiForm, Gender eGender) {
    if (uiForm - 1 < (unsigned int)m_forms.size() && eGender != (Gender)-1) {
        Form88& form = m_forms[uiForm - 1];
        form.m_eGender = eGender;
        form.m_b55 = false;
        form.m_b54 = false;
    }
    return false;
}

}  // namespace Localization
