// c5d-model: Gemini 3.8 Flash
class Host_0090e560 {
public:
    int pad;
    int m_val;
    // src: GUESS (confidence: high) [0x0090e560]
    int __thiscall IsOneOrThree() const;
};

int Host_0090e560::IsOneOrThree() const {
    if (m_val == 3 || m_val == 1) {
        return 1;
    }
    return 0;
}
