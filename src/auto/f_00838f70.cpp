// c5d-model: Gemini 3.8 Flash
#include <windows.h>
class Sem_00838f70 {
public:
    HANDLE m_h;
    // src: GUESS (confidence: high) [0x00838f70]
    void __thiscall Release();
};
void Sem_00838f70::Release() {
    ReleaseSemaphore(m_h, 1, NULL);
}
