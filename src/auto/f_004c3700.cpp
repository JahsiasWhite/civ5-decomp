// c5d-model: Gemini 3.8 Flash
struct DataBlock_004c3700 {
    int data[83];
};

class Host_004c3700 {
    char pad[84];
    DataBlock_004c3700 m_data;
public:
    // src: GUESS (confidence: high) [0x004c3700]
    void __thiscall CopyData(const DataBlock_004c3700* src);
};

void Host_004c3700::CopyData(const DataBlock_004c3700* src) {
    m_data = *src;
}
