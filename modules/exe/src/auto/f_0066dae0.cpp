// c5d-model: Gemini 3.8 Flash
extern void* vt_00b82570;

class SubClass_0066dae0 {
public:
    void* m_vtable;

    // src: GUESS (confidence: low) [0x0066dae0]
    SubClass_0066dae0* __thiscall Init();
};

SubClass_0066dae0* SubClass_0066dae0::Init() {
    *((char*)this - 7) = 1;
    m_vtable = &vt_00b82570;
    return this;
}
