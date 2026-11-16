// c5d-model: Gemini 3.8 Flash
extern "C" __declspec(dllimport) unsigned long __stdcall TlsAlloc(void);

class TlsSlot_0082a420 {
public:
    unsigned long m_slot;
    // src: GUESS (confidence: high) [0x0082a420]
    TlsSlot_0082a420* __thiscall Init();
};

TlsSlot_0082a420* TlsSlot_0082a420::Init() {
    m_slot = 0xffffffff;
    m_slot = TlsAlloc();
    return this;
}
