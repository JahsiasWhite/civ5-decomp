// c5d-model: Gemini 4 Hydrogen
class StringHost_00480a10 {
public:
    char* m_str;
    // src: GUESS (confidence: high) [0x00480a10]
    void __thiscall Clear();
};

void StringHost_00480a10::Clear() {
    if (*(int*)(m_str - 8) != 0) {
        *m_str = 0;
        *(int*)(m_str - 8) = 0;
    }
}
