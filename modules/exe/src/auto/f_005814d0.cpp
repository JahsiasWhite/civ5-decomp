// c5d-model: Gemini 3.8 Flash
struct DataBlock_005814d0 {
    int data[531];
};

class Host_005814d0 {
    char pad[100];
    DataBlock_005814d0 m_data;
public:
    // src: GUESS (confidence: high) [0x005814d0]
    void __thiscall CopyData(const DataBlock_005814d0* src);
};

void Host_005814d0::CopyData(const DataBlock_005814d0* src) {
    m_data = *src;
}
