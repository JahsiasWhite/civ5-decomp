// c5d-model: Gemini 4 Hydrogen
struct DataBlock_00423750 {
    int data[0x53];
};

class Host_00423750 {
    char pad[0x11ac];
    DataBlock_00423750 m_data;
public:
    // src: GUESS (confidence: high) [0x00423750]
    void __thiscall CopyData(const DataBlock_00423750* src);
};

void Host_00423750::CopyData(const DataBlock_00423750* src) {
    m_data = *src;
}
