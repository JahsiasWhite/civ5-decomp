typedef unsigned int uint32_t;

// src: GUESS (confidence: low) [0x005aefc0]
struct Sub5AEFC0 {
    float x, y, z;
    // src: GUESS (confidence: low) [0x005aefc0]
    Sub5AEFC0() : x(0.0f), y(0.0f), z(0.0f) {}
};

// src: GUESS (confidence: low) [0x005aefc0]
struct Base5AEFC0 {
    uint32_t  m_unk04;
    uint32_t  m_unk08;
    uint32_t  m_unk0C;
    uint32_t  m_arg10;
    Sub5AEFC0 m_sub;

    // src: GUESS (confidence: low) [0x005aefc0]
    Base5AEFC0() {
        m_unk04 = 0;
    }
    // src: GUESS (confidence: low) [0x005aefc0]
    virtual ~Base5AEFC0() {}
};

// src: GUESS (confidence: low) [0x005aefc0]
struct F5AEFC0 : Base5AEFC0 {
    float     m_f20;
    float     m_f24;
    float     m_f28;

    // src: GUESS (confidence: low) [0x005aefc0]
    F5AEFC0(uint32_t arg);
    // src: GUESS (confidence: low) [0x005aefc0]
    virtual ~F5AEFC0() {}
};

F5AEFC0::F5AEFC0(uint32_t arg) {
    m_f20 = 0.0f;
    m_f24 = 0.0f;
    m_f28 = 0.0f;
    m_arg10 = arg;
}
