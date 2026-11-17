// c5d-model: Gemini 4 Hydrogen
struct Inner_0091a960 {
    char pad[0x104];
    unsigned char m_flag;
};

class Host_0091a960 {
public:
    Inner_0091a960* m_inner;
    // src: GUESS (confidence: high) [0x0091a960]
    int __thiscall IsReady() const;
};

int Host_0091a960::IsReady() const {
    if (m_inner && m_inner->m_flag == 0) {
        return 1;
    }
    return 0;
}
