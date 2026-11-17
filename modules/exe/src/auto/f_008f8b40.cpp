// c5d-model: Gemini 3.8 Flash
class Class_008f8b40 {
public:
    char pad1[0xc];
    char* m_base;
    char pad2[0xbc];
    int m_index;
    // src: GUESS (confidence: high) [0x008f8b40]
    char* __thiscall GetCurrentItem();
};
char* Class_008f8b40::GetCurrentItem() {
    return m_base + (m_index << 6);
}
