// c5d-model: Gemini 3.8 Flash
struct DataBlock_004c2ca0 {
    int data[83];
};

class Host_004c2ca0 {
    char pad[8];
    DataBlock_004c2ca0 m_data;
public:
    // src: GUESS (confidence: high) [0x004c2ca0]
    void __thiscall CopyData(const DataBlock_004c2ca0* src);
};

void Host_004c2ca0::CopyData(const DataBlock_004c2ca0* src) {
    m_data = *src;
}
