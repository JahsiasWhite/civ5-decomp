// c5d-model: Gemini 4 Hydrogen
struct DataBlock_005fe3f0 {
    int data[33];
};

class Host_005fe3f0 {
    char pad[2924];
    DataBlock_005fe3f0 m_data;
public:
    // src: GUESS (confidence: high) [0x005fe3f0]
    void __thiscall CopyData(const DataBlock_005fe3f0* src);
};

void Host_005fe3f0::CopyData(const DataBlock_005fe3f0* src) {
    m_data = *src;
}
