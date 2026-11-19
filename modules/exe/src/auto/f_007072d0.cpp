// src: GUESS (confidence: low) [0x007072d0]
struct Interface_007072d0 {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24();
    virtual void V25(int arg);
};
// src: GUESS (confidence: low) [0x007072d0]
int __stdcall CallV25_007072d0(Interface_007072d0* obj, int arg) {
    if (obj) {
        obj->V25(arg);
        return 0;
    }
    return 0x80004005;
}
