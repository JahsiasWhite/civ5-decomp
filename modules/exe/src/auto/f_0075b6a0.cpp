// Compiler-generated vcall thunk for ControlBase virtual slot 09 (vtable
// offset 0x24). MSVC emits one when code takes the address of a virtual member
// function; calling through the pointer-to-member lands here and jumps through
// the object's vtable. It sits in a run of such thunks next to the ones the
// game registers as "ControlBase::SetHide" (0x0075b600) and
// "ControlBase::SetColor" (0x0075b7f0); that this one belongs to ControlBase
// as well, and not to a class derived from it, is a guess.

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSlot09Method)();

// src: GUESS (confidence: medium) [0x0075b6a0]
ControlBaseSlot09Method g_ControlBase_Slot09_Thunk = &ControlBase::V09;
