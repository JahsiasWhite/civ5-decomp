// c5d-model: Gemini 4 Hydrogen
struct DataBlock_0054ca40 {
    int data[33];
};

class Host_0054ca40 {
    char pad[396276];
    DataBlock_0054ca40 m_data;
public:
    // src: GUESS (confidence: high) [0x0054ca40]
    void __thiscall CopyData(const DataBlock_0054ca40* src);
};

void Host_0054ca40::CopyData(const DataBlock_0054ca40* src) {
    m_data = *src;
}
