// c5d-cflags: -/EHsc +/GS-
#include <cstdlib>
#include <cstring>
#include <vector>

namespace Localization {

class IPluralityRule {
public:
    virtual unsigned int GetCount() const = 0;
};

class ILogger {
public:
    virtual void V0() = 0;
    virtual void Log(const char* msg, int level) = 0;
};

// src: EXE
extern ILogger* g_pLogger_100c5b1c;

// src: GUESS (confidence: low) [0x10009900]
struct Language_10009900 {
    char pad0[0x28];
    IPluralityRule* m_pkPluralityRule;
    char pad2c[0x1d8 - 0x2c];
};

extern int g_CurrentLangIdx_10009900;
extern Language_10009900* g_Languages_10009900;

// src: GUESS (confidence: low) [0x10009900]
struct Form88_10009900 {
    char pad0[0x2c];
    unsigned int m_plurality;
    char pad30[0x24];
    bool m_b54;
    bool m_b55;
    char pad56[2];
};

// src: EXE [0x10009670]
class String {
public:
    __declspec(dllexport) bool SetPlurality(const char* szPlurality, unsigned int uiLen);
private:
    char m_pad00[0x3c];
    std::vector<Form88_10009900> m_forms;
    Language_10009900* m_pLanguage;
};

bool String::SetPlurality(const char* szPlurality, unsigned int uiLen) {
    Language_10009900* lang = m_pLanguage;
    if (!lang) {
        lang = &g_Languages_10009900[g_CurrentLangIdx_10009900];
    }
    IPluralityRule* rule = lang->m_pkPluralityRule;
    if (rule) {
        unsigned int uiMaxPlurality = rule->GetCount();
    unsigned int nForms = 1;
    for (unsigned int i = 0; i < uiLen; ++i) {
        if (szPlurality[i] == '|') {
            ++nForms;
        }
    }

    if (nForms == 1 && uiLen < 8) {
        char szBuf[8] = "";
        strncpy_s(szBuf, 8, szPlurality, uiLen);
        unsigned int uiVal = atoi(szBuf);
        if (uiVal == 0) {
            if (g_pLogger_100c5b1c) {
                g_pLogger_100c5b1c->Log("Plurality Starts at 1.", 2);
            }
            return false;
        }
        if (uiVal <= uiMaxPlurality) {
            for (std::vector<Form88_10009900>::iterator it = m_forms.begin(); it != m_forms.end(); ++it) {
                it->m_plurality = uiVal;
                it->m_b55 = false;
                it->m_b54 = false;
            }
            return true;
        }
    }

    if (nForms != m_forms.size()) {
        return false;
    }

    char szBuf[8] = { 0 };
    unsigned int uiStart = 0;
    unsigned int uiFormIdx = 0;
    for (unsigned int i = 0; i < uiLen; ++i) {
        if (szPlurality[i] == '|') {
            unsigned int segLen = i - uiStart;
            if (segLen >= 8) {
                return false;
            }
            memset(szBuf, 0, sizeof(szBuf));
            strncpy_s(szBuf, 8, szPlurality + uiStart, segLen);
            unsigned int uiVal = atoi(szBuf);
            if (uiVal == 0) {
                if (g_pLogger_100c5b1c) {
                    g_pLogger_100c5b1c->Log("Plurality Starts at 1.", 2);
                }
                return false;
            }
            if (uiVal > uiMaxPlurality) {
                return false;
            }
            Form88_10009900& form = m_forms[uiFormIdx];
            form.m_plurality = uiVal;
            form.m_b55 = false;
            form.m_b54 = false;
            uiStart = i + 1;
            ++uiFormIdx;
        }
    }

    unsigned int segLen = uiLen - uiStart;
    if (segLen >= 8) {
        return false;
    }
    memset(szBuf, 0, sizeof(szBuf));
    strncpy_s(szBuf, 8, szPlurality + uiStart, segLen);
    unsigned int uiVal = atoi(szBuf);
    if (uiVal == 0) {
        if (g_pLogger_100c5b1c) {
            g_pLogger_100c5b1c->Log("Plurality Starts at 1.", 2);
        }
        return false;
    }
    if (uiVal > uiMaxPlurality) {
        return false;
    }
    Form88_10009900& form = m_forms[uiFormIdx];
    form.m_plurality = uiVal;
    form.m_b55 = false;
    form.m_b54 = false;
    return true;
    }
    return false;
}

}  // namespace Localization
