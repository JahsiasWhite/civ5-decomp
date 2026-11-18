// Localization::String: a localized text key plus the arguments substituted into
// it. Only the exported PushArgument overloads are declared so far; the names
// and signatures come from the DLL's export table.
#pragma once
#include "LocalizationAPI.h"
#include <vector>

namespace Localization {

// src: EXE
enum Gender {
    GENDER_NONE = 0
};

class String {
public:
    // src: EXE [0x10008f60]
    CVLOCALIZATION_API unsigned int GetNumForms() const;
    // src: EXE [0x100095b0]
    CVLOCALIZATION_API bool SetGender(Gender eGender);
    // src: EXE [0x10009630]
    CVLOCALIZATION_API Gender GetGender(unsigned int uiForm) const;

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
        char m_pad00[0x30];            // +0x00
        // src: GUESS (confidence: medium)
        Gender m_eGender;              // +0x30
        char m_pad34[0x20];            // +0x34
        bool m_b54;                    // +0x54
        bool m_b55;                    // +0x55
        char m_pad56[0x02];            // +0x56
    };
    char m_pad00[0x3c];                // +0x00
    // src: GUESS (confidence: medium)
    std::vector<Form88> m_forms;       // +0x3c (_Myfirst at +0x40, _Mylast at +0x44)
};

}  // namespace Localization
