// c5d-model: Gemini 4 Hydrogen
struct Pair_00632510 {
    int a, b;
};

class Host_00632510 {
public:
    char pad0[0x74];
    int m_idx;
    char pad1[0x14];
    Pair_00632510* m_items;
    // src: GUESS (confidence: high) [0x00632510]
    Pair_00632510* __thiscall GetEntry() const;
};

Pair_00632510* Host_00632510::GetEntry() const {
    if (m_idx == -1) {
        return m_items;
    }
    return &m_items[m_idx];
}
