// Asks the registered factory's object for a new handle (slot 9), then
// releases the object (slot 1).

#include "Unk_0066a390.h"

// src: GUESS (confidence: low)
class FactoryObject_00423c50
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
    // src: GUESS (confidence: low)
    virtual int __stdcall CreateHandle();
};

// src: GUESS (confidence: low)
struct Handle_00423c50
{
    Handle_00423c50(int value) : m_value(value) {}
    Handle_00423c50(const Handle_00423c50& other);

    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x00423c50]
Handle_00423c50 CreateHandle_00423c50()
{
    FactoryObject_00423c50* object = g_handleFactory_02dd201c
        ? (FactoryObject_00423c50*)g_handleFactory_02dd201c()
        : 0;
    Handle_00423c50 handle(object->CreateHandle());
    object->Release();
    return handle;
}
