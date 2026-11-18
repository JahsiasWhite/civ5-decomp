#include "Localization/String.h"

// src: GUESS (confidence: medium) [0x00513d90]
Localization::String* PushDoubleArg_00513d90(Localization::String* text, const double* value)
{
    text->PushArgument(*value);
    return text;
}
