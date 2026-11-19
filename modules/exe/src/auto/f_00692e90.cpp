// src: GUESS (confidence: low) [0x00692e90]
struct IUnknown_00692e90 {
    virtual void V0();
    virtual void __stdcall Release();
};
// src: GUESS (confidence: low) [0x00692e90]
struct Ptr_00692e90 {
    IUnknown_00692e90* ptr;
    void Assign(IUnknown_00692e90* p);
};
void Ptr_00692e90::Assign(IUnknown_00692e90* p) {
    IUnknown_00692e90* old = this->ptr;
    if (p != old && old != 0) {
        old->Release();
    }
    this->ptr = p;
}
