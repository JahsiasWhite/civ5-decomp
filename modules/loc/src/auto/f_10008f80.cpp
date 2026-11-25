// src: EXE [0x10008f80]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

unsigned int String::GetFormByPlurality(int iPlurality, int iOccurrence) const {
    for (unsigned int i = 0; i < (unsigned int)m_forms.size(); ++i) {
        if (m_forms[i].m_uiPlurality == (unsigned int)iPlurality) {
            if (iOccurrence == 0) {
                return i + 1;
            }
            --iOccurrence;
        }
    }
    return 0;
}

}  // namespace Localization
