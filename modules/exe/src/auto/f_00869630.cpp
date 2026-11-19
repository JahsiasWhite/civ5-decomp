// c5d-model: Gemini 3.8 Flash

class RefCount_00903870 {
public:
    char pad[4];
    unsigned int m_count;

    // src: GUESS (confidence: high) [0x00903870]
    void __thiscall Decrement();
};

void RefCount_00903870::Decrement() {
    if (m_count > 0) {
        --m_count;
    }
}
