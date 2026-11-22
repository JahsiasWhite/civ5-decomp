typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

// src: GUESS (confidence: low) [0x00484ee0]
struct Sub484EE0 {
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
    virtual void vf30(uint32_t a, int b) = 0;
    virtual void vf34() = 0;
    virtual uint32_t vf38() = 0;
    virtual uint32_t vf3c() = 0;
};

// src: GUESS (confidence: low) [0x00484ee0]
struct F484EE0 {
    uint8_t    m_pad00[0x14];
    Sub484EE0* m_sub;

    // src: GUESS (confidence: low) [0x00484ee0]
    uint32_t run();
};

uint32_t F484EE0::run() {
    if (!m_sub) {
        return 0;
    }
    uint32_t a = m_sub->vf3c();
    uint32_t b = m_sub->vf38();
    m_sub->vf30(a, 0);
    return b;
}
