// c5d-model: Gemini 4 Hydrogen
class Host_0090eaa0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual int __thiscall Compare(int arg);
    // src: GUESS (confidence: high) [0x0090eaa0]
    bool __thiscall IsLess(int arg);
};

bool Host_0090eaa0::IsLess(int arg) {
    return Compare(arg) < 0;
}
