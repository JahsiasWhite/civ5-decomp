typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

// src: GUESS (confidence: low) [0x006b4ce0]
struct F6B4CE0 {
    uint8_t  m_pad04[0x2c];
    float    m_f30;
    float    m_f34;
    uint8_t  m_pad38[0x08];
    uint32_t m_flags40;

    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0c() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1c() = 0;
    virtual void vf20() = 0;
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2c() = 0;
    virtual void vf30() = 0;
    virtual void vf34() = 0;
    virtual void vf38() = 0;
    virtual void vf3c() = 0;
    virtual void vf40() = 0;
    virtual void vf44() = 0;
    virtual void vf48() = 0;
    virtual void vf4c() = 0;
    virtual void vf50() = 0;
    virtual void vf54() = 0;
    virtual void vf58() = 0;
    virtual void vf5c() = 0;
    virtual void vf60() = 0;
    virtual void vf64() = 0;
    virtual void vf68() = 0;
    virtual void vf6c() = 0;
    virtual void vf70() = 0;
    virtual void vf74() = 0;
    virtual void vf78() = 0;
    virtual void vf7c() = 0;
    virtual void vf80() = 0;
    virtual void vf84() = 0;
    virtual void vf88() = 0;
    virtual void vf8c() = 0;
    virtual void vf90() = 0;
    virtual void vf94() = 0;
    virtual void vf98(float a, float b) = 0;

    // src: GUESS (confidence: low) [0x006b4ce0]
    void apply(float x);
};

void F6B4CE0::apply(float x) {
    if (m_flags40 & 0x10000000) {
        vf98(m_f30, x);
    } else {
        vf98(x, m_f34);
    }
}
