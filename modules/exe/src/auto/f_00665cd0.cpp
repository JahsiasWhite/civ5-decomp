// src: GUESS (confidence: high)
struct Unk_00665cd0 {
    // src: GUESS (confidence: low)
    char m_pad[0x9c];
    // src: GUESS (confidence: high)
    int m_a;
    // src: GUESS (confidence: high)
    int m_b;

    // src: EXE [0x00665cd0]
    void Reset();
};

void Unk_00665cd0::Reset() {
    m_a = -1;
    m_b = -1;
}
