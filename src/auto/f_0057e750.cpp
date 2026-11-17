// c5d-model: Gemini 4 Hydrogen
struct DataBlock_0057e750 {
    int data[531];
};

class Host_0057e750 {
    char pad[2400];
    DataBlock_0057e750 m_data;
public:
    // src: GUESS (confidence: high) [0x0057e750]
    void __thiscall CopyData(const DataBlock_0057e750* src);
};

void Host_0057e750::CopyData(const DataBlock_0057e750* src) {
    m_data = *src;
}
