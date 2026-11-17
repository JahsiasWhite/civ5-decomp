// c5d-model: Gemini 4 Hydrogen
struct DataBlock_00520520 {
    int data[33];
};

class Host_00520520 {
    char pad[300];
    DataBlock_00520520 m_data;
public:
    // src: GUESS (confidence: high) [0x00520520]
    void __thiscall CopyData(const DataBlock_00520520* src);
};

void Host_00520520::CopyData(const DataBlock_00520520* src) {
    m_data = *src;
}
