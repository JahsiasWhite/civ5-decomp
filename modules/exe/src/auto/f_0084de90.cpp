// src: GUESS (confidence: low) [0x0084de90]
struct RefCounted84 {
    virtual ~RefCounted84() {}
    int refCount;
};

struct Holder84 {
    RefCounted84* ptr;
    int f4;
    float f8;
    float fc;
    int f10;
    unsigned short f14;
    unsigned short f16;
    unsigned short f18;
    unsigned short f1a;

    void __thiscall SetData(RefCounted84* p, int a2, unsigned short a3);
};

void __thiscall Holder84::SetData(RefCounted84* p, int a2, unsigned short a3) {
    if (ptr != p) {
        if (p) {
            ++p->refCount;
        }
        RefCounted84* old = ptr;
        if (old && --old->refCount <= 0) {
            delete old;
        }
        ptr = p;
    }
    f4 = a2;
    f14 = a3;
    f10 = 0xfffffff;
    f16 = 0;
    f18 = 0;
    f1a = 0;
    f8 = 0.0f;
    fc = 0.0f;
}
