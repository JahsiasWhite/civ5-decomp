// c5d-model: Gemini 3.8 Flash
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);

class Synch_00838f50 {
public:
    void* m_h;
    // src: GUESS (confidence: high) [0x00838f50]
    bool __thiscall Wait(unsigned long ms);
};

bool Synch_00838f50::Wait(unsigned long ms) {
    return WaitForSingleObject(m_h, ms) == 0;
}
