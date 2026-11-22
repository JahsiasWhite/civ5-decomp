// src: GUESS (confidence: high)
struct Unk_0075ab40 {
    // src: GUESS (confidence: low)
    char m_pad[0x27c];
    // src: GUESS (confidence: high)
    bool m_bFlag;

    // src: EXE [0x0075ab40]
    void SetFlag(bool bFlag);
};

void Unk_0075ab40::SetFlag(bool bFlag) {
    m_bFlag = bFlag;
}
