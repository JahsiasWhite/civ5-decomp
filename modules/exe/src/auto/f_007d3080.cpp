// c5d-model: Gemini 4 Hydrogen
class Callee_005e88c0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void __thiscall VirtualCall(int arg, int flag);
};

class Host_005e88c0 {
public:
    Callee_005e88c0* m_callee;
    // src: GUESS (confidence: high) [0x005e88c0]
    void __thiscall VirtualCall(int arg);
};

void Host_005e88c0::VirtualCall(int arg) {
    if (m_callee) {
        m_callee->VirtualCall(arg, 1);
    }
}
