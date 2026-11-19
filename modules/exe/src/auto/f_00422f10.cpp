// src: GUESS (confidence: low) [0x007da6f0]
struct Class_007da6f0 {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(int arg);
    char pad[0x2c - 4];
    char flag;
    void Init(int arg);
};
void Class_007da6f0::Init(int arg) {
    if (arg != 0 && this->flag == 0) {
        this->V4(arg);
        this->flag = 1;
    }
}
