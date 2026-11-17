// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall TlsFree(unsigned long dwTlsIndex);

class TlsSlot_0082a440 {
public:
    unsigned long m_slot;
    // src: GUESS (confidence: high) [0x0082a440]
    void __thiscall Free();
};

void TlsSlot_0082a440::Free() {
    if (m_slot != 0xffffffff) {
        TlsFree(m_slot);
        m_slot = 0xffffffff;
    }
}
