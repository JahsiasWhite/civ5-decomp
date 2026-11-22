// c5d-cflags: -/arch:SSE2
#include <string.h>

// src: GUESS (confidence: low)
struct Sub_00650c60 {
    virtual void v00() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0c() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1c() {}
    virtual void v20() {}
    virtual void v24() {}
    virtual void v28() {}
    virtual int v2c() { return 0; }
};

// src: GUESS (confidence: low)
struct Obj_00650c60 {
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    char pad[0x28];
    Sub_00650c60* m_sub;

    virtual void v00() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0c() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1c() {}
    virtual void v20(int) {}
    virtual void v24() {}
    virtual void v28() {}
    virtual void v2c() {}
    virtual void v30() {}
    virtual void v34() {}
    virtual void v38() {}
    virtual void v3c() {}
    virtual void v40(int, float) {}

    void ResetAndApply(int a, float f);
};

// src: GUESS (confidence: medium) [0x00650c60]
void Obj_00650c60::ResetAndApply(int a, float f) {
    v20(m_sub->v2c());
    memset(&m_04, 0, 0x24);
    v40(a, f);
}
