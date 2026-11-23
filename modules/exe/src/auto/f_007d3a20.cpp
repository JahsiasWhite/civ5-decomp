// c5d-cflags: -/Ob1 +/Ob0
#include <string>

// src: EXE [0x007d3a20]
namespace Localization {
class String {
public:
    __declspec(dllimport) bool __thiscall PushArgument(const char* szArg);
};
} // namespace Localization

// src: GUESS (confidence: medium) [0x007d3a20]
Localization::String* __cdecl PushLocalizationStringArg(Localization::String* pStr, const std::string& sArg) {
    pStr->PushArgument(sArg.c_str());
    return pStr;
}
