// Asks the registered factory's object for a new handle (slot 10), then
// releases the object (slot 1).

#include "Unk_0066a390.h"

// src: GUESS (confidence: low)
class FactoryObject_005d1de0
{
public:
    virtual void __stdcall v00();
    // src: GUESS (confidence: low)
    virtual void __stdcall Release();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    virtual void __stdcall v07();
    virtual void __stdcall v08();
    virtual void __stdcall v09();
    // src: GUESS (confidence: low)
    virtual int __stdcall CreateHandle();
};

// src: GUESS (confidence: low)
struct Handle_005d1de0
{
    Handle_005d1de0(int value) : m_value(value) {}
    Handle_005d1de0(const Handle_005d1de0& other);

    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x005d1de0]
Handle_005d1de0 CreateHandle_005d1de0()
{
    FactoryObject_005d1de0* object = g_handleFactory_02dd201c
        ? (FactoryObject_005d1de0*)g_handleFactory_02dd201c()
        : 0;
    Handle_005d1de0 handle(object->CreateHandle());
    object->Release();
    return handle;
}
