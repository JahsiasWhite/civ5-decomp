// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/Ob1 +/Ob0
#include <string>

namespace Localization {
// src: EXE
class __declspec(dllimport) String {
public:
    bool PushArgument(const char* arg);
};
}

// src: GUESS (confidence: high) [0x004c58f0]
Localization::String* PushStringArg_004c58f0(Localization::String* s, const std::string& arg) {
    s->PushArgument(arg.c_str());
    return s;
}
