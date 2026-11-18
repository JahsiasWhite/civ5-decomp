// Localization::String: a localized text key plus the arguments substituted into
// it. Only the exported PushArgument overloads are declared so far; the names
// and signatures come from the DLL's export table.
#pragma once
#include "LocalizationAPI.h"

namespace Localization {

class CVLOCALIZATION_API String {
public:
    // src: EXE [0x10009c40]
    bool PushArgument(const char* text);
    // src: EXE [0x10009cc0]
    bool PushArgument(const char* text, unsigned int length);
    // src: EXE [0x10009d40]
    bool PushArgument(int value);
    // src: EXE [0x10009dc0]
    bool PushArgument(__int64 value);
    // src: EXE [0x10009e40]
    bool PushArgument(float value);
    // src: EXE [0x10009ec0]
    bool PushArgument(double value);
    // src: EXE [0x10009f40]
    bool PushArgument(const String& value);
};

}  // namespace Localization
