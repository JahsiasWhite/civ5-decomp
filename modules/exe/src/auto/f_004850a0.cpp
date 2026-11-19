// src: GUESS (confidence: low) [0x00837810]
struct Class_00837810 {
    char f0;
    char f1;
    short f2;
    short f4;
    short pad6;
    int f8;
    int fc;
    int f10;
    short f14;
    char f16;
    char pad17;
    int f18;

    Class_00837810(char a, char b, int dummy);
};

Class_00837810::Class_00837810(char a, char b, int dummy)
    : f1(b), f0(a), f4(0), f2(0),
      f8(0), fc(0), f10(1),
      f14(0x400), f16(0), f18(0)
{
}
