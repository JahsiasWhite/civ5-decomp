// c5d-model: Gemini 3.8 Flash
class Class_008f8b50 {
public:
    char pad[0xc];
    char* m_base;
    // src: GUESS (confidence: high) [0x008f8b50]
    char* __thiscall GetItem(int index);
};
char* Class_008f8b50::GetItem(int index) {
    return m_base + (index << 6);
}
