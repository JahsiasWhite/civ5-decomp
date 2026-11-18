// src: EXE [0x100095b0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

bool String::SetGender(Gender eGender) {
    for (std::vector<Form88>::iterator it = m_forms.begin(); it != m_forms.end(); ++it) {
        it->m_eGender = eGender;
        it->m_b55 = false;
        it->m_b54 = false;
    }
    return true;
}

}  // namespace Localization
