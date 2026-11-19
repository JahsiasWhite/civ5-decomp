// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
class Target_00465e40 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17(int a, int b, int c);
};

// src: GUESS (confidence: high)
class Host_00465e40 {
public:
    void Dispatch(int a, int b);
    Target_00465e40* m_target;
};

// src: GUESS (confidence: high) [0x00465e40]
void Host_00465e40::Dispatch(int a, int b) {
    if (m_target) {
        m_target->V17(a, b, 1);
    }
}
