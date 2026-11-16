// c5d-model: Gemini 3.8 Flash
class Host_0052e6b0 {
public:
    int* m_data;
    unsigned int m_size;
    // src: GUESS (confidence: high) [0x0052e6b0]
    int __thiscall GetElement(unsigned int idx) const;
};

int Host_0052e6b0::GetElement(unsigned int idx) const {
    if (idx < m_size) {
        return m_data[idx];
    }
    return 0;
}
