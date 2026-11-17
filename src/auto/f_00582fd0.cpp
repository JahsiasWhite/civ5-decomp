// c5d-model: Gemini 4 Hydrogen
struct DataBlock_00582fd0 {
    int data[83];
};

class Host_00582fd0 {
    char pad[1280];
    DataBlock_00582fd0 m_data;
public:
    // src: GUESS (confidence: high) [0x00582fd0]
    void __thiscall CopyData(const DataBlock_00582fd0* src);
};

void Host_00582fd0::CopyData(const DataBlock_00582fd0* src) {
    m_data = *src;
}
