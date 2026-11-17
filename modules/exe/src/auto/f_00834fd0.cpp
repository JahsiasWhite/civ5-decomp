// c5d-model: Gemini 4 Hydrogen
class Host_00834fd0 {
public:
    int pad0;
    int pad4;
    int m_f8;
    char padC[0x230];
    int m_f23c;
    // src: GUESS (confidence: high) [0x00834fd0]
    int __thiscall HasAny() const;
};

int Host_00834fd0::HasAny() const {
    if (m_f23c != 0 || m_f8 != 0) {
        return 1;
    }
    return 0;
}
