// src: GUESS (confidence: low)
struct Vec_10004d60 {
    // src: GUESS 0x10004d60 (confidence: medium)
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

void Vec_10004d60::Tidy() {
    if (m_first != 0) {
        ::operator delete(m_first);
    }
    m_first = 0;
    m_last = 0;
    m_end = 0;
}
