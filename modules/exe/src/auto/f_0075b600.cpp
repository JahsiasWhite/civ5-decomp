// Compiler-generated vcall thunk for ControlBase::SetHide (virtual slot 20,
// vtable offset 0x50). MSVC emits one when code takes the address of a virtual
// member function; calling through the pointer-to-member lands here and jumps
// through the object's vtable. The Lua registration at 0x0069c010 passes this
// thunk together with the name "ControlBase::SetHide".

#include "ControlBase.h"

typedef void (ControlBase::*ControlBaseSetHideMethod)(bool);

// src: GUESS (confidence: medium) [0x0075b600]
ControlBaseSetHideMethod g_ControlBase_SetHide_Thunk = &ControlBase::SetHide;
