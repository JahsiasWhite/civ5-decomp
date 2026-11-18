// src: GUESS (confidence: low)
struct Vec_1000d410 {
    // src: GUESS 0x1000d410 (confidence: medium)
    void Tidy();

    // src: GUESS (confidence: low)
    int m_alloc;
    // src: GUESS (confidence: low)
    int* m_first;
    // src: GUESS (confidence: low)
    int* m_last;
    // src: GUESS (confidence: low)
    int* m_end;
};

void Vec_1000d410::Tidy() {
    if (m_first != 0) {
        ::operator delete(m_first);
    }
    m_first = 0;
    m_last = 0;
    m_end = 0;
}
