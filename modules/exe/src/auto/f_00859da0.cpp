// c5d-model: Gemini 4 Hydrogen
class Host_008f42d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int __thiscall GetVal();
    virtual void __thiscall SetVal(int val);
    // src: GUESS (confidence: high) [0x008f42d0]
    void __thiscall Dispatch();
};

void Host_008f42d0::Dispatch() {
    SetVal(GetVal());
}
