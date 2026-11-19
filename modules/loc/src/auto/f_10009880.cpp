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
// src: GUESS (confidence: low) [0x10009880]
struct Language_10009880 {
    char pad0[0x28];
    IPluralityRule* m_pkPluralityRule;
    char pad2c[0x1d8 - 0x2c];
};
extern int g_CurrentLangIdx_10009880;
extern Language_10009880* g_Languages_10009880;

// src: GUESS (confidence: low) [0x10009880]
struct Form88_10009880 {
    char pad0[0x2c];
    unsigned int m_plurality;
    char pad30[0x24];
    bool m_b54;
    bool m_b55;
    char pad56[2];
};

// src: EXE [0x10009880]
class String {
public:
    __declspec(dllexport) bool SetPlurality(unsigned int uiPlurality);
private:
    char m_pad00[0x3c];
    std::vector<Form88_10009880> m_forms;
    Language_10009880* m_pLanguage;
};

bool String::SetPlurality(unsigned int uiPlurality) {
    Language_10009880* lang = m_pLanguage;
    if (!lang) {
        lang = &g_Languages_10009880[g_CurrentLangIdx_10009880];
    }
    IPluralityRule* rule = lang->m_pkPluralityRule;
    if (rule) {
        if (uiPlurality == 0) {
            if (g_pLogger_100c5b1c) {
                g_pLogger_100c5b1c->Log("Plurality Starts at 1.", 2);
            }
        } else if (uiPlurality < rule->GetCount()) {
            for (std::vector<Form88_10009880>::iterator it = m_forms.begin(); it != m_forms.end(); ++it) {
                it->m_plurality = uiPlurality;
                it->m_b55 = false;
                it->m_b54 = false;
            }
            return true;
        }
    }
    return false;
}
}
