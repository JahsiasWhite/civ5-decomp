// c5d-model: Gemini 3.8 Flash
struct DataBlock_004a3be0 {
    int data[83];
};

class Host_004a3be0 {
    char pad[20];
    DataBlock_004a3be0 m_data;
public:
    // src: GUESS (confidence: high) [0x004a3be0]
    void __thiscall CopyData(const DataBlock_004a3be0* src);
};

void Host_004a3be0::CopyData(const DataBlock_004a3be0* src) {
    m_data = *src;
}
