// c5d-cflags: -/Ob1 +/Ob0
#include <string>
#include "Localization/String.h"

// src: GUESS (confidence: medium) [0x007d3a20]
Localization::String* PushStringArg_007d3a20(Localization::String* text, const std::string& val)
{
    text->PushArgument(val.c_str());
    return text;
}
