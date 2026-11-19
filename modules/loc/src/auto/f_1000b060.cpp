// c5d-cflags: -/EHsc +/GS-
#include <windows.h>
#include <string>
#include <vector>

namespace Database {
class Results {
public:
    __declspec(dllimport) bool Bind(int idx, const char* val, int len, bool b);
    __declspec(dllimport) bool Step();
    __declspec(dllimport) bool Reset();
};
}

namespace Localization {
// src: EXE [0x1000b060]
class StringDictionary {
public:
    class Language {
    public:
        std::string m_strType;
        std::string m_strDisplayName;
        int m_ePluralityRule;
    };
    __declspec(dllexport) bool HasKey(const char* szKey, unsigned int uiLen, unsigned int uiLang) const;
private:
    char m_pad00[0x2c];
    std::vector<Language> m_languages;
    int m_pad3c;
    mutable CRITICAL_SECTION m_cs;
    mutable Database::Results m_results;
};

bool StringDictionary::HasKey(const char* szKey, unsigned int uiLen, unsigned int uiLang) const {
    if (!szKey) return false;
    EnterCriticalSection(&m_cs);
    bool bFound = false;
    if (uiLang < (unsigned int)m_languages.size()) {
        m_results.Bind(1, m_languages[uiLang].m_strType.c_str(), -1, false);
        m_results.Bind(2, szKey, uiLen, false);
        if (m_results.Step()) {
            bFound = true;
        }
        m_results.Reset();
    }
    LeaveCriticalSection(&m_cs);
    return bFound;
}
}
