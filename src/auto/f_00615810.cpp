// c5d-model: Gemini 4 Hydrogen
class Class_00615810 {
public:
    char pad[0x6f4];
    void* m_ptr;
    // src: GUESS (confidence: high) [0x00615810]
    void __thiscall SetPtrIfNonNull(void* p);
};
void Class_00615810::SetPtrIfNonNull(void* p) {
    if (p) {
        m_ptr = p;
    }
}
