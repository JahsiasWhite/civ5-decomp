// Small functions that are nothing but an expansion of the inline FMalloc
// path. Real names unknown yet; named by address.
#include "FMemory.h"

class Unk_007e6480
{
public:
    Unk_007e6480();                         // 0x007e6480
    char _data[0x30];
};

static Unk_007e6480* s_pUnk_06196944;       // 0x06196944

// 0x007cccf0, 67 bytes
void* Unk_007cccf0()
{
    return FMalloc(4);
}

// 0x005c63f0, 92 bytes
void Unk_005c63f0()
{
    s_pUnk_06196944 = FNEW(Unk_007e6480);
}
