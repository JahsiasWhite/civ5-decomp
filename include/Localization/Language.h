// Localization::Language: one language's type name, plural rule and number/text
// transforms. Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "LocalizationAPI.h"

namespace Localization {

class Language {
public:
    virtual ~Language();

    CVLOCALIZATION_API const char* GetType() const;
    CVLOCALIZATION_API IPluralityRule* GetPluralityRule() const;
    CVLOCALIZATION_API const ParameterTransforms& GetParameterTransforms() const;
    // src: EXE
    CVLOCALIZATION_API bool Compare(const char* szStr1, unsigned int uiLen1, const char* szStr2, unsigned int uiLen2, int& riResult) const;

private:
    char m_szType[0x24];               // +0x04
    IPluralityRule* m_pkPluralityRule; // +0x28
    int m_unknown2c;                   // +0x2c
    char m_transforms[1];              // +0x30 the ParameterTransforms object (not modelled yet)
};

// src: EXE
CVLOCALIZATION_API const Language& GetCurrentLanguage();

}  // namespace Localization
