// Localization::StringDictionary: holds loaded languages and localized strings.
#pragma once
#include "LocalizationAPI.h"
#include <string>
#include <vector>

namespace Localization {

// src: EXE
class StringDictionary {
public:
    // src: EXE
    class Language {
    public:
        // src: GUESS (confidence: medium)
        std::string m_strType;        // +0x00
        // src: GUESS (confidence: medium)
        std::string m_strDisplayName; // +0x1c
        // src: GUESS (confidence: medium)
        int m_ePluralityRule;         // +0x38
    };

    // src: EXE [0x1000b240]
    CVLOCALIZATION_API unsigned int GetLanguageCount() const;
    // src: EXE [0x1000b260]
    CVLOCALIZATION_API const char* GetLanguageType(unsigned int uiIndex) const;
    // src: EXE [0x1000b290]
    CVLOCALIZATION_API const char* GetLanguageDisplayName(unsigned int uiIndex) const;
    // src: EXE [0x1000b2c0]
    CVLOCALIZATION_API const Language& GetLanguage(unsigned int uiIndex) const;

private:
    char m_pad00[0x2c];                  // +0x00
    // src: GUESS (confidence: medium)
    std::vector<Language> m_languages;   // +0x2c (_Myfirst at +0x30)
};

}  // namespace Localization
