// c5d-model: Gemini 4 Hydrogen
extern void* const g_vtable_00aa2f30[];
class Unk_00aa2f30 {
public:
    void* const* m_vtable;
    char pad[0x10];
    int m_14;
    int m_18;
    // src: GUESS (confidence: high) [0x0091f770]
    Unk_00aa2f30* __thiscall Init();
};
Unk_00aa2f30* Unk_00aa2f30::Init() {
    m_vtable = g_vtable_00aa2f30;
    m_14 = 0;
    m_18 = 0;
    return this;
}
