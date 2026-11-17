// c5d-model: Gemini 4 Hydrogen
struct DataBlock_004bbdf0 {
    int data[0x20];
};

class Host_004bbdf0 {
    char pad[0x7a0];
    DataBlock_004bbdf0 m_data;
public:
    // src: GUESS (confidence: high) [0x004bbdf0]
    void __thiscall CopyData(const DataBlock_004bbdf0* src);
};

void Host_004bbdf0::CopyData(const DataBlock_004bbdf0* src) {
    m_data = *src;
}
