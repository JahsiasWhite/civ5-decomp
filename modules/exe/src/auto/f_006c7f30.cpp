// Asks the registered factory's object for a new handle (slot 8), then
// releases the object (slot 1).

#include "Unk_0066a390.h"

// src: GUESS (confidence: low)
class FactoryObject_0042c640
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
    // src: GUESS (confidence: low)
    virtual int __stdcall CreateHandle();
};

// src: GUESS (confidence: low)
struct Handle_0042c640
{
    Handle_0042c640(int value) : m_value(value) {}
    Handle_0042c640(const Handle_0042c640& other);

    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x0042c640]
Handle_0042c640 CreateHandle_0042c640()
{
    FactoryObject_0042c640* object = g_handleFactory_02dd201c
        ? (FactoryObject_0042c640*)g_handleFactory_02dd201c()
        : 0;
    Handle_0042c640 handle(object->CreateHandle());
    object->Release();
    return handle;
}
