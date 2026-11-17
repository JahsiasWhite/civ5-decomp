// c5d-model: Gemini 4 Hydrogen
struct DataBlock_006025f0 {
    int data[531];
};

class Host_006025f0 {
    char pad[252];
    DataBlock_006025f0 m_data;
public:
    // src: GUESS (confidence: high) [0x006025f0]
    void __thiscall CopyData(const DataBlock_006025f0* src);
};

void Host_006025f0::CopyData(const DataBlock_006025f0* src) {
    m_data = *src;
}
