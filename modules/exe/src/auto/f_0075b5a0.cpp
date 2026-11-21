// Compiler-generated vcall thunk for ControlBase virtual slot 08 (vtable
// offset 0x20). MSVC emits one when code takes the address of a virtual member
// function; calling through the pointer-to-member lands here and jumps through
// the object's vtable. It sits in a run of such thunks next to the one the
// game registers as "ControlBase::SetHide" (0x0075b600); that this one belongs
// to ControlBase as well, and not to a class derived from it, is a guess.

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSlot08Method)();

// src: GUESS (confidence: medium) [0x0075b5a0]
ControlBaseSlot08Method g_ControlBase_Slot08_Thunk = &ControlBase::V08;
