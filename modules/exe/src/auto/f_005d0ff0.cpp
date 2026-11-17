// c5d-model: Gemini 4 Hydrogen
struct DataBlock_005d0ff0 {
    int data[83];
};

class Host_005d0ff0 {
    char pad[2508];
    DataBlock_005d0ff0 m_data;
public:
    // src: GUESS (confidence: high) [0x005d0ff0]
    void __thiscall CopyData(const DataBlock_005d0ff0* src);
};

void Host_005d0ff0::CopyData(const DataBlock_005d0ff0* src) {
    m_data = *src;
}
