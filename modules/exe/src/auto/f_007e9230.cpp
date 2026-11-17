// c5d-model: Gemini 4 Hydrogen
class Host_007e9230 {
public:
    char pad[0x20];
    int* m_head;
    // src: GUESS (confidence: high) [0x007e9230]
    void __thiscall GetHead(int* outVal, int** outPtr);
};

void Host_007e9230::GetHead(int* outVal, int** outPtr) {
    *outVal = *m_head;
    *outPtr = m_head;
}
