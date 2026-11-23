#include <algorithm>

// src: GUESS (confidence: low)
struct Struct_00833f30 {
    char pad0[8];
    int f8;
    char pad_c[4];
    int f10;
    int f14;
    int f18;
    char pad_1c[8];
    int f24;
    int f28;
    int f2c;
    int f30;
    void fn_00833f30();
};

// src: GUESS (confidence: low)
void Struct_00833f30::fn_00833f30() {
    f30 = f8;
    f2c = f18 - f14;
    std::swap(f10, f28);
    std::swap(f14, f24);
}
