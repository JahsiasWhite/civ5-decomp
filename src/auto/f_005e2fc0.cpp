// c5d-model: Gemini 4 Hydrogen
struct DataBlock_005e2fc0 {
    int data[33];
};

class Host_005e2fc0 {
    char pad[2224];
    DataBlock_005e2fc0 m_data;
public:
    // src: GUESS (confidence: high) [0x005e2fc0]
    void __thiscall CopyData(const DataBlock_005e2fc0* src);
};

void Host_005e2fc0::CopyData(const DataBlock_005e2fc0* src) {
    m_data = *src;
}
