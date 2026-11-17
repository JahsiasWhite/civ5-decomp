// c5d-model: Gemini 4 Hydrogen
class Inner_00837770 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int __thiscall GetSize();
};

class Host_00837770 {
public:
    int f0, f4, f8;
    int m_fc;
    int m_f10;
    Inner_00837770* m_inner;
    // src: GUESS (confidence: high) [0x00837770]
    void __thiscall SyncSize();
};

void Host_00837770::SyncSize() {
    if (m_inner) {
        int sz = m_inner->GetSize();
        m_f10 = sz;
        m_fc = sz;
    }
}
