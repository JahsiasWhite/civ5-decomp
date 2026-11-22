#pragma once

// Base class of the UI controls that the game's Lua interface scripts drive.
// The class and method names come from the Lua registration strings that the
// game passes together with a virtual-call thunk: "ControlBase::SetHide"
// (0x00979ae4) with the thunk for vtable offset 0x50 (0x0075b600), and
// "ControlBase::SetColor" (0x00979d60) with the one for offset 0x58
// (0x0075b7f0). Parameter lists are guesses.
//
// The class has no RTTI and its vtable hasn't been located yet; add the vtable
// marker line here once it is. Slots without a known method are placeholders:
// rename them as their methods are identified, keeping the slot order.

// src: EXE [0x00979ae4]
class ControlBase
{
public:
    // src: GUESS (confidence: low)
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    // src: EXE [0x00979ae4]
    virtual void SetHide(bool hide);
    // src: GUESS (confidence: low)
    virtual void V21();
    // src: EXE [0x00979d60]
    virtual void SetColor(unsigned int color);
    // src: GUESS (confidence: low)
    virtual void V23(); virtual void V24(); virtual void V25(); virtual void V26();
    virtual void V27(); virtual void V28(); virtual void V29();
    virtual void V30();
};
