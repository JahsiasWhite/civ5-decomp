// c5d-cflags: -/EHsc
#include "Unk_0066a390.h"

// src: GUESS (confidence: low)
class Interface_0040c140 {
public:
    virtual void __stdcall v00();
    // src: GUESS (confidence: low)
    virtual void __stdcall Release();
    // src: GUESS (confidence: low)
    virtual int __stdcall CreateHandle(int key);
};

// src: GUESS (confidence: low)
class FactoryObject_0040c140 {
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
    virtual Interface_0040c140* __stdcall GetInterface();
};

// src: GUESS (confidence: low)
template<typename T>
struct AutoRelease_0040c140 {
    T* m_p;
    AutoRelease_0040c140(T* p) : m_p(p) {}
    ~AutoRelease_0040c140() { m_p->Release(); }
};

// src: GUESS (confidence: low)
struct Handle_0040c140 {
    Handle_0040c140(int value) : m_value(value) {}
    Handle_0040c140(const Handle_0040c140& other) : m_value(other.m_value) {}

    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x0040c140]
Handle_0040c140 CreateHandle_0040c140(int key) {
    if (key != -1) {
        Interface_0040c140* rawIface;
        {
            AutoRelease_0040c140<FactoryObject_0040c140> object(
                g_handleFactory_02dd201c ? (FactoryObject_0040c140*)g_handleFactory_02dd201c() : 0);
            rawIface = object.m_p->GetInterface();
        }
        AutoRelease_0040c140<Interface_0040c140> iface(rawIface);
        return Handle_0040c140(iface.m_p->CreateHandle(key));
    }
    return Handle_0040c140(0);
}
