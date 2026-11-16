// c5d-model: Gemini 4 Hydrogen
class Host_0091e7c0 {
public:
    char pad[0x8c];
    int m_count;
    // src: GUESS (confidence: high) [0x0091e7c0]
    bool __thiscall TryDecrement();
};

bool Host_0091e7c0::TryDecrement() {
    if (m_count <= 0) {
        return false;
    }
    --m_count;
    return true;
}
