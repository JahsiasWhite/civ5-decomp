// c5d-model: Gemini 4 Hydrogen
class Host_00502be0 {
public:
    char pad[0x2d38];
    int m_state;
    // src: GUESS (confidence: high) [0x00502be0]
    int __thiscall IsActive() const;
};

int Host_00502be0::IsActive() const {
    if (m_state == 1 || m_state == 2) {
        return 1;
    }
    return 0;
}
