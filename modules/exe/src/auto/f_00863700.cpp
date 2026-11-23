// src: GUESS (confidence: low)
class Base_00863700 {
public:
    virtual ~Base_00863700() {}
};

// src: GUESS (confidence: low)
struct Inner_00863700 {
    int* f4;
    int f8;
    int fc;
    int buf[0x81];
    Inner_00863700() : f8(0), fc(0x20) {
        f4 = buf;
    }
};

// src: GUESS (confidence: low)
class Class_00863700 : public Base_00863700 {
public:
    Inner_00863700 inner;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    Class_00863700();
};

// src: GUESS (confidence: low)
Class_00863700::Class_00863700()
    : f214(0)
    , f218(0)
    , f21c(0)
    , f220(0)
    , f224(0)
{}
