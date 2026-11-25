// src: EXE [0x10001fc0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/Language.h"

namespace Localization {

// src: EXE
class IPluralityRule {
public:
    virtual ~IPluralityRule() {}
    virtual unsigned int GetPluralForm(int iNumber) const = 0;
};

unsigned int Language::GetPluralForm(int iNumber) const {
    IPluralityRule* pkRule = m_pkPluralityRule;
    if (pkRule != 0) {
        return pkRule->GetPluralForm(iNumber);
    }
    return 0;
}

}  // namespace Localization
