// c5d-model: claude-opus-5-5
// Compiler-generated vcall thunk for virtual slot 29 (vtable offset 0x74).
// MSVC emits one when code takes the address of a virtual member function;
// calling through the pointer-to-member lands here and jumps through the
// object's vtable.

class VCallSlot74
{
public:
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28();
    virtual void Slot29();
};

typedef void (VCallSlot74::*VCallSlot74Method)();

VCallSlot74Method g_VCallSlot74_Thunk = &VCallSlot74::Slot29;
