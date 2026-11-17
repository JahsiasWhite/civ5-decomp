#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/Language.h"

namespace Localization {

const char* Language::GetType() const {
    return m_szType;
}

IPluralityRule* Language::GetPluralityRule() const {
    return m_pkPluralityRule;
}

const ParameterTransforms& Language::GetParameterTransforms() const {
    return *reinterpret_cast<const ParameterTransforms*>(m_transforms);
}

}  // namespace Localization
