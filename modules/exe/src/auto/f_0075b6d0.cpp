// Compiler-generated vcall thunk for ControlBase virtual slot 17 (vtable
// offset 0x44). MSVC emits one when code takes the address of a virtual member
// function; calling through the pointer-to-member lands here and jumps through
// the object's vtable. It sits in a run of such thunks next to the ones the
// game registers as "ControlBase::SetHide" (0x0075b600) and
// "ControlBase::SetColor" (0x0075b7f0); that this one belongs to ControlBase
// as well, and not to a class derived from it, is a guess.

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSlot17Method)();

// src: GUESS (confidence: medium) [0x0075b6d0]
ControlBaseSlot17Method g_ControlBase_Slot17_Thunk = &ControlBase::V17;
