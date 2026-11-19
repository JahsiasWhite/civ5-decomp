// c5d-model: Gemini 3.8 Flash
struct DataBlock_006561f0 {
    int data[33];
};

class Host_006561f0 {
    char pad[4];
    DataBlock_006561f0 m_data;
public:
    // src: GUESS (confidence: high) [0x006561f0]
    void __thiscall CopyData(const DataBlock_006561f0* src);
};

void Host_006561f0::CopyData(const DataBlock_006561f0* src) {
    m_data = *src;
}
