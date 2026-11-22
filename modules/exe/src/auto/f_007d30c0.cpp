// src: GUESS (confidence: high)
struct IUnk_007d30c0 {
    // src: GUESS (confidence: high)
    virtual void V0() = 0;
    // src: GUESS (confidence: high)
    virtual void V1() = 0;
    // src: GUESS (confidence: high)
    virtual void V2() = 0;
    // src: GUESS (confidence: high)
    virtual void V3(int a) = 0;
};

// src: GUESS (confidence: high)
struct Unk_007d30c0 {
    // src: GUESS (confidence: high)
    IUnk_007d30c0* m_pInner;

    // src: EXE [0x007d30c0]
    void CallV3(int a);
};

void Unk_007d30c0::CallV3(int a) {
    if (m_pInner) {
        m_pInner->V3(a);
    }
}
