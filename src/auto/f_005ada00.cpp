// c5d-model: Gemini 4 Hydrogen
struct DataBlock_005ada00 {
    int data[83];
};

class Host_005ada00 {
    char pad[432];
    DataBlock_005ada00 m_data;
public:
    // src: GUESS (confidence: high) [0x005ada00]
    void __thiscall CopyData(const DataBlock_005ada00* src);
};

void Host_005ada00::CopyData(const DataBlock_005ada00* src) {
    m_data = *src;
}
