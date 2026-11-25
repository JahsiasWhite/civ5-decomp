// src: EXE [0x1000ead0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/Language.h"

namespace Localization {

// src: GUESS (confidence: low)
extern int g_iCurrentLanguage_100c5148;
// src: GUESS (confidence: low)
extern Language* g_pkLanguages_100c5ba4;

const Language& GetCurrentLanguage() {
    return g_pkLanguages_100c5ba4[g_iCurrentLanguage_100c5148];
}

}  // namespace Localization
