// Compiler-generated vcall thunk for ControlBase virtual slot 30 (vtable
// offset 0x78). MSVC emits one when code takes the address of a virtual member
// function; calling through the pointer-to-member lands here and jumps through
// the object's vtable. It sits in the same run of thunks as the ones for
// ControlBase::SetHide and SetColor; that the owning class is ControlBase is a guess.

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSlot30Method)();

// src: GUESS (confidence: medium) [0x0075b850]
ControlBaseSlot30Method g_ControlBase_Slot30_Thunk = &ControlBase::V30;
