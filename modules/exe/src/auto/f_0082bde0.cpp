// src: GUESS (confidence: low) [0x00cb0ae4]
extern int g_byteOrder_00cb0ae4;

// src: GUESS (confidence: low)
struct Stream_0082bde0 {
    // src: GUESS (confidence: low)
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void ReadBytes(int size, void* dst);

    int m_04;
    // src: GUESS (confidence: medium)
    int m_expectedOrder;

    // src: GUESS (confidence: medium) [0x0082bde0]
    void ReadInt(int* out);
};

inline void SwapBytePair_0082bde0(char* a, char* b) {
    if (a != b) {
        char tb = *b;
        char ta = *a;
        *a = tb;
        *b = ta;
    }
}

inline int GetByteOrder_0082bde0() {
    if (g_byteOrder_00cb0ae4 == 0) {
        union {
            int val;
            unsigned char bytes[4];
        } probe;
        probe.bytes[1] = 0;
        probe.bytes[2] = 0;
        probe.bytes[3] = 0;
        unsigned char one = 1;
        probe.bytes[0] = one;
        g_byteOrder_00cb0ae4 = (probe.val == 1) ? 1 : 2;
    }
    return g_byteOrder_00cb0ae4;
}

// src: GUESS (confidence: medium) [0x0082bde0]
void Stream_0082bde0::ReadInt(int* out) {
    ReadBytes(4, out);
    int expected = m_expectedOrder;
    if (GetByteOrder_0082bde0() != expected) {
        char* p = (char*)out;
        SwapBytePair_0082bde0(p, p + 3);
        SwapBytePair_0082bde0(p + 1, p + 2);
    }
}
