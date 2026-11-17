// c5d-model: Gemini 4 Hydrogen
struct DataBlock_0072d030 {
    int data[33];
};

class Host_0072d030 {
    char pad[416];
    DataBlock_0072d030 m_data;
public:
    // src: GUESS (confidence: high) [0x0072d030]
    void __thiscall CopyData(const DataBlock_0072d030* src);
};

void Host_0072d030::CopyData(const DataBlock_0072d030* src) {
    m_data = *src;
}
