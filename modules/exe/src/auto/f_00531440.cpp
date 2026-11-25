// src: GUESS (confidence: low)
struct F00531440 {
    unsigned char pad0[0x3d8];
    int m_a[5];
    int m_b[5];

    void __thiscall f_00531440(const int* a, const int* b);
};

void __thiscall F00531440::f_00531440(const int* a, const int* b) {
    for (int i = 0; i < 5; ++i) {
        m_a[i] = a[i];
        m_b[i] = b[i];
    }
}
