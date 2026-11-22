// Compiler-generated vcall thunk for ControlBase virtual slot 16 (vtable
// offset 0x40). MSVC emits one when code takes the address of a virtual member
// function; calling through the pointer-to-member lands here and jumps through
// the object's vtable. It sits in a run of such thunks next to the one the
// game registers as "ControlBase::SetHide" (0x0075b600); that this one belongs
// to ControlBase as well, and not to a class derived from it, is a guess.

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSlot16Method)();

// src: GUESS (confidence: medium) [0x0075b5d0]
ControlBaseSlot16Method g_ControlBase_Slot16_Thunk = &ControlBase::V16;
