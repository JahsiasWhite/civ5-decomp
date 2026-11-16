// c5d-model: Gemini 3.8 Flash

class Class_008f41f0 {
public:
    char pad[8];
    void* m_ptr;

    // src: GUESS (confidence: high) [0x008f41f0]
    bool __thiscall SetPtr(void* p1, void* p2, void* p3);
};

bool Class_008f41f0::SetPtr(void* p1, void*, void*) {
    m_ptr = p1;
    return true;
}
