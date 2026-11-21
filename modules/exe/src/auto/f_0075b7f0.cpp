// Compiler-generated vcall thunk for ControlBase::SetColor (virtual slot 22,
// vtable offset 0x58). MSVC emits one when code takes the address of a virtual
// member function; calling through the pointer-to-member lands here and jumps
// through the object's vtable. The Lua registrations at 0x00697ab0, 0x00698da0
// and 0x0069f460 pass this thunk with the names "ColorBoxButtonControl::SetColor",
// "ColorBoxControl::SetColor" and "ControlBase::SetColor".

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSetColorMethod)(unsigned int);

// src: GUESS (confidence: medium) [0x0075b7f0]
ControlBaseSetColorMethod g_ControlBase_SetColor_Thunk = &ControlBase::SetColor;
