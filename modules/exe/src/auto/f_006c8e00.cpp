// Asks the registered factory's object for a handle with the given key
// (slot 11), then releases the object (slot 1).

#include "Unk_0066a390.h"

// src: GUESS (confidence: low)
class FactoryObject_006c8e00
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
    virtual void __stdcall v10();
    // src: GUESS (confidence: low)
    virtual int __stdcall CreateHandle(int key);
};

// src: GUESS (confidence: low)
struct Handle_006c8e00
{
    Handle_006c8e00(int value) : m_value(value) {}
    Handle_006c8e00(const Handle_006c8e00& other);

    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x006c8e00]
Handle_006c8e00 CreateHandle_006c8e00(int key)
{
    FactoryObject_006c8e00* object = g_handleFactory_02dd201c
        ? (FactoryObject_006c8e00*)g_handleFactory_02dd201c()
        : 0;
    Handle_006c8e00 handle(object->CreateHandle(key));
    object->Release();
    return handle;
}
