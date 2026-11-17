// c5d-model: Gemini 3.8 Flash
struct DataBlock_0050ee20 {
    int data[83];
};

class Host_0050ee20 {
    char pad[24];
    DataBlock_0050ee20 m_data;
public:
    // src: GUESS (confidence: high) [0x0050ee20]
    void __thiscall CopyData(const DataBlock_0050ee20* src);
};

void Host_0050ee20::CopyData(const DataBlock_0050ee20* src) {
    m_data = *src;
}
