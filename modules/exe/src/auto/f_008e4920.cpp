// c5d-model: Gemini 3.8 Flash
struct DataBlock_008e4920 {
    int data[16];
};

class Host_008e4920 {
    char pad[48];
    DataBlock_008e4920 m_data;
public:
    // src: GUESS (confidence: high) [0x008e4920]
    void __thiscall CopyData(const DataBlock_008e4920* src);
};

void Host_008e4920::CopyData(const DataBlock_008e4920* src) {
    m_data = *src;
}
