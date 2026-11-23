// Function: 0x007bc2b0

class ModeProvider { // src: GUESS (confidence: low)
public:
    virtual void Vfn00() = 0; // src: GUESS (confidence: low)
    virtual void Vfn01() = 0; // src: GUESS (confidence: low)
    virtual void Vfn02() = 0; // src: GUESS (confidence: low)
    virtual void Vfn03() = 0; // src: GUESS (confidence: low)
    virtual void Vfn04() = 0; // src: GUESS (confidence: low)
    virtual void Vfn05() = 0; // src: GUESS (confidence: low)
    virtual void Vfn06() = 0; // src: GUESS (confidence: low)
    virtual void Vfn07() = 0; // src: GUESS (confidence: low)
    virtual void Vfn08() = 0; // src: GUESS (confidence: low)
    virtual void Vfn09() = 0; // src: GUESS (confidence: low)
    virtual int GetMode() = 0; // src: GUESS (confidence: medium)
};

class FlaggedControl { // src: GUESS (confidence: low)
public:
    virtual void Vfn00() {} // src: GUESS (confidence: low)
    virtual void Vfn01() {} // src: GUESS (confidence: low)
    virtual void Vfn02() {} // src: GUESS (confidence: low)
    virtual void Vfn03() {} // src: GUESS (confidence: low)
    virtual void Vfn04() {} // src: GUESS (confidence: low)
    virtual void Vfn05() {} // src: GUESS (confidence: low)
    virtual void Vfn06() {} // src: GUESS (confidence: low)
    virtual void Vfn07() {} // src: GUESS (confidence: low)
    virtual void Vfn08() {} // src: GUESS (confidence: low)
    virtual void Vfn09() {} // src: GUESS (confidence: low)
    virtual void Vfn10() {} // src: GUESS (confidence: low)
    virtual void Vfn11() {} // src: GUESS (confidence: low)
    virtual void Vfn12() {} // src: GUESS (confidence: low)
    virtual void Vfn13() {} // src: GUESS (confidence: low)
    virtual void Vfn14() {} // src: GUESS (confidence: low)
    virtual void Vfn15() {} // src: GUESS (confidence: low)
    virtual void Vfn16() {} // src: GUESS (confidence: low)
    virtual void Vfn17() {} // src: GUESS (confidence: low)
    virtual void Vfn18() {} // src: GUESS (confidence: low)
    virtual void Vfn19() {} // src: GUESS (confidence: low)
    virtual void Vfn20() {} // src: GUESS (confidence: low)
    virtual void Vfn21() {} // src: GUESS (confidence: low)
    virtual void Vfn22() {} // src: GUESS (confidence: low)
    virtual void Vfn23() {} // src: GUESS (confidence: low)
    virtual void Vfn24() {} // src: GUESS (confidence: low)
    virtual void Vfn25() {} // src: GUESS (confidence: low)
    virtual void Vfn26() {} // src: GUESS (confidence: low)
    virtual void Vfn27() {} // src: GUESS (confidence: low)
    virtual void Vfn28() {} // src: GUESS (confidence: low)
    virtual void Vfn29() {} // src: GUESS (confidence: low)
    virtual void Vfn30() {} // src: GUESS (confidence: low)
    virtual void OnFlagSet(unsigned int uiBit) {} // src: GUESS (confidence: medium)
    virtual void OnFlagCleared(unsigned int uiBit) {} // src: GUESS (confidence: medium)

    void UpdateFlags(unsigned int uiNewFlags); // src: GUESS (confidence: medium) [0x007bc2b0]

private:
    inline void DiffBit(unsigned int uiNewFlags, unsigned int uiBit) {
        if ((m_uiFlags & uiBit) && !(uiNewFlags & uiBit)) {
            OnFlagCleared(uiBit);
        }
        if (!(m_uiFlags & uiBit) && (uiNewFlags & uiBit)) {
            OnFlagSet(uiBit);
        }
    }

    unsigned char m_pad0[0x54]; // src: GUESS (confidence: low)
    ModeProvider* m_pModeProvider; // src: GUESS (confidence: low)
    unsigned int m_uiPad5c; // src: GUESS (confidence: low)
    unsigned int m_uiFlags; // src: GUESS (confidence: medium)
};

void FlaggedControl::UpdateFlags(unsigned int uiNewFlags) {
    if (m_pModeProvider->GetMode() == 0x20) {
        DiffBit(uiNewFlags, 0x100);
        DiffBit(uiNewFlags, 0x200);
        DiffBit(uiNewFlags, 0x400);
        DiffBit(uiNewFlags, 0x800);
        DiffBit(uiNewFlags, 0x1000);
        DiffBit(uiNewFlags, 0x2000);
        DiffBit(uiNewFlags, 0x4000);
        m_uiFlags = uiNewFlags;
        return;
    }

    DiffBit(uiNewFlags, 0x1);
    DiffBit(uiNewFlags, 0x2);
    DiffBit(uiNewFlags, 0x4);
    DiffBit(uiNewFlags, 0x8);
    m_uiFlags = uiNewFlags;
}
