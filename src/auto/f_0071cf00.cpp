// c5d-model: Gemini 3.8 Flash
struct DataBlock_0071cf00 {
    int data[531];
};

class Host_0071cf00 {
    char pad[96];
    DataBlock_0071cf00 m_data;
public:
    // src: GUESS (confidence: high) [0x0071cf00]
    void __thiscall CopyData(const DataBlock_0071cf00* src);
};

void Host_0071cf00::CopyData(const DataBlock_0071cf00* src) {
    m_data = *src;
}
