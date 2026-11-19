// src: GUESS (confidence: low) [0x00830fc0]
struct Class_00830fc0 {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual int V12();
    int pad4;
    int pad8;
    int fc;
    int f10;
    int pad14;
    int f18;
    int f1c;
    void Update();
};
void Class_00830fc0::Update() {
    this->fc = this->V12();
    this->f10 = this->V12();
    this->f18 = this->f1c;
}
