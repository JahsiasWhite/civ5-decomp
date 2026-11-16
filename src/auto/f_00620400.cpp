// c5d-model: Gemini 3.8 Flash
class Host_00620400 {
public:
    char pad[0x0c];
    int* m_data;
    unsigned int m_size;
    // src: GUESS (confidence: high) [0x00620400]
    int __thiscall GetItem(unsigned int idx) const;
};

int Host_00620400::GetItem(unsigned int idx) const {
    if (idx < m_size) {
        return m_data[idx];
    }
    return 0;
}
