// Compiler-generated vcall thunk for ControlBase virtual slot 7 (vtable
// offset 0x1c). MSVC emits one when code takes the address of a virtual member
// function; calling through the pointer-to-member lands here and jumps through
// the object's vtable. It sits in the same run of thunks as the ones for
// ControlBase::SetHide and SetColor; that the owning class is ControlBase is a guess.

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSlot07Method)();

// src: GUESS (confidence: medium) [0x0075b890]
ControlBaseSlot07Method g_ControlBase_Slot07_Thunk = &ControlBase::V07;
