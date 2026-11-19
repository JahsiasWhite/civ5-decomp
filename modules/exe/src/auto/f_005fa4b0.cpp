// c5d-model: Gemini 4 Hydrogen
struct DataBlock_0061f7d0 {
    int data[83];
};

class Host_0061f7d0 {
    char pad[172];
    DataBlock_0061f7d0 m_data;
public:
    // src: GUESS (confidence: high) [0x0061f7d0]
    void __thiscall CopyData(const DataBlock_0061f7d0* src);
};

void Host_0061f7d0::CopyData(const DataBlock_0061f7d0* src) {
    m_data = *src;
}
