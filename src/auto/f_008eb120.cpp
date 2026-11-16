// c5d-model: Gemini 3.8 Flash
class Class_008eb120 {
public:
    char pad[0x30];
    char* m_base;
    // src: GUESS (confidence: high) [0x008eb120]
    char* __thiscall GetItem(int index);
};
char* Class_008eb120::GetItem(int index) {
    return m_base + (index << 6);
}
