// c5d-model: Gemini 4 Hydrogen
struct DataBlock_005f8990 {
    int data[83];
};

class Host_005f8990 {
    char pad[2160];
    DataBlock_005f8990 m_data;
public:
    // src: GUESS (confidence: high) [0x005f8990]
    void __thiscall CopyData(const DataBlock_005f8990* src);
};

void Host_005f8990::CopyData(const DataBlock_005f8990* src) {
    m_data = *src;
}
