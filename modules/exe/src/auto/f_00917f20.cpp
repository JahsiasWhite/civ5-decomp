// c5d-model: Gemini 4 Hydrogen
#pragma pack(push, 4)
struct Struct12_00917f20 {
    double a;
    int b;
};
#pragma pack(pop)

class Host_00917f20 {
public:
    Struct12_00917f20 m_val;
    // src: GUESS (confidence: high) [0x00917f20]
    void __thiscall CopyTo(Struct12_00917f20* dst) const;
};

void Host_00917f20::CopyTo(Struct12_00917f20* dst) const {
    *dst = m_val;
}
