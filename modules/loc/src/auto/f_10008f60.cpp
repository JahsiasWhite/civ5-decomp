// src: EXE [0x10008f60]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/String.h"

namespace Localization {

unsigned int String::GetNumForms() const {
    return (unsigned int)m_forms.size();
}

}  // namespace Localization
