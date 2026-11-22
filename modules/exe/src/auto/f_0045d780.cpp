// src: GUESS (confidence: low)
class Sub45d {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual int v8() { return 0; }
    virtual void v9() {}
    virtual bool v10() { return false; }
};

// src: GUESS (confidence: low)
class Host45d {
public:
    char pad[0x10010];
    int* arr;
    Sub45d sub;

    // src: GUESS (confidence: medium)
    int GetVal();
};

int Host45d::GetVal() {
    if (sub.v10()) {
        return sub.v8();
    }
    return arr ? arr[-1] : 0;
}
