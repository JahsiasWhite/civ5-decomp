// src: GUESS (confidence: low)
struct Sub_00445ac0 {
    char pad[0x24];
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
};

// src: GUESS (confidence: low)
struct Item_00445ac0 {
    char pad[0x20];
    int m_20;
    int m_24;
};

// src: GUESS (confidence: low)
struct Handler_00445ac0 {
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
    virtual void v2c() {}
    virtual void v30() {}
    virtual void v34() {}
    virtual void v38() {}
    virtual void v3c() {}
    virtual void v40() {}
    virtual void v44() {}
    virtual void v48(Item_00445ac0*, int, int) {}
    virtual void v4c() {}
    virtual void v50() {}
    virtual void v54() {}
    virtual void v58() {}
    virtual void v5c() {}
    virtual void v60() {}
    virtual void v64() {}
    virtual void v68() {}
    virtual void v6c() {}
    virtual void v70() {}
    virtual void v74() {}
    virtual void v78() {}
    virtual void v7c() {}
    virtual void v80() {}
    virtual void v84() {}
    virtual void v88() {}
    virtual void v8c() {}
    virtual void v90() {}
    virtual void v94() {}
    virtual void v98() {}
    virtual void v9c() {}
    virtual void va0() {}
    virtual void va4() {}
    virtual void va8() {}
    virtual void vac() {}
    virtual void vb0() {}
    virtual void vb4() {}
    virtual void vb8() {}
    virtual void vbc() {}
    virtual void vc0() {}
    virtual void vc4() {}
    virtual void vc8() {}
    virtual void vcc() {}
    virtual void vd0() {}
    virtual void vd4() {}
    virtual void vd8() {}
    virtual void vdc() {}
    virtual void ve0() {}
    virtual void ve4() {}
    virtual void ve8() {}
    virtual void vec() {}
    virtual void vf0() {}
    virtual void vf4() {}
    virtual void vf8() {}
    virtual void vfc() {}
    virtual void v100() {}
    virtual void v104() {}
    virtual void v108() {}
    virtual void v10c() {}
    virtual void v110() {}
    virtual void v114() {}
    virtual void v118() {}
    virtual void v11c() {}
    virtual void v120() {}
    virtual void v124() {}
    virtual void v128() {}
    virtual Sub_00445ac0* v12c() { return 0; }

    void Dispatch(Item_00445ac0* item, int a, int b);
};

// src: GUESS (confidence: medium) [0x00445ac0]
void Handler_00445ac0::Dispatch(Item_00445ac0* item, int a, int b) {
    if (v12c() != 0) {
        Sub_00445ac0* s = v12c();
        item->m_20 = s->m_2c + s->m_24;
        int cur = s->m_30;
        s->m_30 = cur + 1;
        item->m_24 = cur;
        v48(item, a, b);
    }
}
