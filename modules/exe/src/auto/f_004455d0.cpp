// c5d-cflags: -/EHsc
#include "Unk_0066a390.h"

// src: GUESS (confidence: low)
class FactoryObject_004455d0 {
public:
    virtual void __stdcall v00();
    // src: GUESS (confidence: low)
    virtual void __stdcall Release();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    // src: GUESS (confidence: low)
    virtual int __stdcall CreateHandle();
};

// src: GUESS (confidence: low)
struct AutoRelease_004455d0 {
    FactoryObject_004455d0* m_p;
    AutoRelease_004455d0(FactoryObject_004455d0* p) : m_p(p) {}
    ~AutoRelease_004455d0() { m_p->Release(); }
};

// src: GUESS (confidence: low)
struct Handle_004455d0 {
    Handle_004455d0(int value) : m_value(value) {}
    Handle_004455d0(const Handle_004455d0& other) : m_value(other.m_value) {}

    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x004455d0]
Handle_004455d0 CreateHandle_004455d0() {
    if (g_handleFactory_02dd201c) {
        AutoRelease_004455d0 object((FactoryObject_004455d0*)g_handleFactory_02dd201c());
        return Handle_004455d0(object.m_p->CreateHandle());
    }
    return Handle_004455d0(0);
}
