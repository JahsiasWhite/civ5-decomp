// c5d-model: Gemini 3.8 Flash
struct DataBlock_008f5960 {
    int data[16];
};

class Host_008f5960 {
    char pad[68];
    DataBlock_008f5960 m_data;
public:
    // src: GUESS (confidence: high) [0x008f5960]
    void __thiscall CopyData(const DataBlock_008f5960* src);
};

void Host_008f5960::CopyData(const DataBlock_008f5960* src) {
    m_data = *src;
}
