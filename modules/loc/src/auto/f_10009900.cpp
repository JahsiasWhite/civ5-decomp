// c5d-cflags: -/EHsc +/GS-
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

// src: EXE [0x10009900]
class String {
public:
    __declspec(dllexport) bool SetPlurality(unsigned int uiForm, unsigned int uiPlurality);
private:
    char m_pad00[0x3c];
    std::vector<Form88_10009900> m_forms;
    Language_10009900* m_pLanguage;
};

bool String::SetPlurality(unsigned int uiForm, unsigned int uiPlurality) {
    if (uiForm - 1 < (unsigned int)m_forms.size()) {
        Language_10009900* lang = m_pLanguage;
        if (!lang) {
            lang = &g_Languages_10009900[g_CurrentLangIdx_10009900];
        }
        IPluralityRule* rule = lang->m_pkPluralityRule;
        if (rule) {
            if (uiPlurality == 0) {
                if (g_pLogger_100c5b1c) {
                    g_pLogger_100c5b1c->Log("Plurality Starts at 1.", 2);
                }
            } else if (uiPlurality < rule->GetCount()) {
                Form88_10009900& form = m_forms[uiForm - 1];
                form.m_plurality = uiPlurality;
                form.m_b55 = false;
                form.m_b54 = false;
                return true;
            }
        }
    }
    return false;
}
}
