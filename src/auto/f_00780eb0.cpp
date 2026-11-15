// c5d-model: claude-opus-5-5
// Compiler-generated vcall thunk for virtual slot 21 (vtable offset 0x54).
// MSVC emits one when code takes the address of a virtual member function;
// calling through the pointer-to-member lands here and jumps through the
// object's vtable.

class VCallSlot54
{
public:
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20();
    virtual void Slot21();
};

typedef void (VCallSlot54::*VCallSlot54Method)();

VCallSlot54Method g_VCallSlot54_Thunk = &VCallSlot54::Slot21;
