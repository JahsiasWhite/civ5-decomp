// c5d-model: Gemini 3.8 Flash
struct DataBlock_006a4030 {
    int data[33];
};

class Host_006a4030 {
    char pad[80];
    DataBlock_006a4030 m_data;
public:
    // src: GUESS (confidence: high) [0x006a4030]
    void __thiscall CopyData(const DataBlock_006a4030* src);
};

void Host_006a4030::CopyData(const DataBlock_006a4030* src) {
    m_data = *src;
}
