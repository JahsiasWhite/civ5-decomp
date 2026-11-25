// Localization::String: a localized text key plus the arguments substituted into
// it. Only the exported PushArgument overloads are declared so far; the names
// and signatures come from the DLL's export table.
#pragma once
#include "LocalizationAPI.h"
#include "SharedString.h"
#include <vector>

namespace Localization {

class Language;

// src: EXE
enum Gender {
    GENDER_NONE = 0
};

class String {
public:
    // src: EXE [0x10008da0]
    CVLOCALIZATION_API bool IsEmpty() const;
    // src: EXE [0x10008ed0]
    CVLOCALIZATION_API const char* GetBaseString(unsigned int& ruiLength) const;
    // src: EXE [0x10008ef0]
    CVLOCALIZATION_API Language* GetLanguage() const;
    // src: EXE [0x10008f00]
    CVLOCALIZATION_API bool SetLanguage(Language* pkLanguage);
    // src: EXE [0x10008f60]
    CVLOCALIZATION_API unsigned int GetNumForms() const;
    // src: EXE [0x10008f80]
    CVLOCALIZATION_API unsigned int GetFormByPlurality(int iPlurality, int iOccurrence) const;
    // src: EXE [0x100095b0]
    CVLOCALIZATION_API bool SetGender(Gender eGender);
    // src: EXE [0x100095e0]
    CVLOCALIZATION_API bool SetGender(unsigned int uiForm, Gender eGender);
    // src: EXE [0x10009630]
    CVLOCALIZATION_API Gender GetGender(unsigned int uiForm) const;
    // src: EXE [0x100099a0]
    CVLOCALIZATION_API unsigned int GetPlurality(unsigned int uiForm) const;

    // src: EXE [0x10009c40]
    CVLOCALIZATION_API bool PushArgument(const char* text);
    // src: EXE [0x10009cc0]
    CVLOCALIZATION_API bool PushArgument(const char* text, unsigned int length);
    // src: EXE [0x10009d40]
    CVLOCALIZATION_API bool PushArgument(int value);
    // src: EXE [0x10009dc0]
    CVLOCALIZATION_API bool PushArgument(__int64 value);
    // src: EXE [0x10009e40]
    CVLOCALIZATION_API bool PushArgument(float value);
    // src: EXE [0x10009ec0]
    CVLOCALIZATION_API bool PushArgument(double value);
    // src: EXE [0x10009f40]
    CVLOCALIZATION_API bool PushArgument(const String& value);

private:
    // src: GUESS (confidence: low)
    struct Form88 {
        char m_pad00[0x2c];            // +0x00
        // src: GUESS (confidence: medium)
        unsigned int m_uiPlurality;    // +0x2c
        // src: GUESS (confidence: medium)
        Gender m_eGender;              // +0x30
        char m_pad34[0x20];            // +0x34
        bool m_b54;                    // +0x54
        bool m_b55;                    // +0x55
        char m_pad56[0x02];            // +0x56
    };
    // src: GUESS (confidence: medium)
    void* m_vptr;                      // +0x00
    // src: GUESS (confidence: high)
    SharedString m_kBaseString;        // +0x04
    char m_pad18[0x24];                // +0x18
    // src: GUESS (confidence: medium)
    std::vector<Form88> m_forms;       // +0x3c (_Myfirst at +0x40, _Mylast at +0x44)
    // src: GUESS (confidence: high)
    Language* m_pkLanguage;            // +0x4c
};

}  // namespace Localization
