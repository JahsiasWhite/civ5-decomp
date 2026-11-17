// c5d-model: Gemini 4 Hydrogen
class Host_00519220 {
public:
    char pad[0x48];
    unsigned int m_mask;
    // src: GUESS (confidence: high) [0x00519220]
    bool __thiscall HasBit(unsigned int bit) const;
};

bool __thiscall Host_00519220::HasBit(unsigned int bit) const {
    return (m_mask & (1u << bit)) != 0;
}
