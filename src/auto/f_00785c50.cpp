// c5d-model: Gemini 4 Hydrogen
struct DataBlock_00785c50 {
    int data[33];
};

class Host_00785c50 {
    char pad[1612];
    DataBlock_00785c50 m_data;
public:
    // src: GUESS (confidence: high) [0x00785c50]
    void __thiscall CopyData(const DataBlock_00785c50* src);
};

void Host_00785c50::CopyData(const DataBlock_00785c50* src) {
    m_data = *src;
}
