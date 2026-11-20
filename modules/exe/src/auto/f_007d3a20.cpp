// c5d-cflags: -/Ob1 +/Ob0
#include "Localization/String.h"
#include <string>

// src: GUESS (confidence: high) [0x007d3a20]
Localization::String* PushStringArg_004c58f0(Localization::String* str, const std::string& arg)
{
    str->PushArgument(arg.c_str());
    return str;
}
