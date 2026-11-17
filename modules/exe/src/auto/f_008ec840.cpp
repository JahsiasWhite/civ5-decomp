// c5d-model: Gemini 4 Hydrogen
class Host_008ec840 {
public:
    int m_type;
    char pad[0x70];
    unsigned short m_val;
    // src: GUESS (confidence: high) [0x008ec840]
    bool __thiscall IsValid() const;
};

bool Host_008ec840::IsValid() const {
    switch (m_type) {
    case 3:
        return !!m_val;
    case 4:
        return m_val != 0;
    default:
        return false;
    }
}
