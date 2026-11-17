// c5d-model: Gemini 3.8 Flash
#include <windows.h>
class CritSec_00813d30 {
public:
    CRITICAL_SECTION m_cs;
    // src: GUESS (confidence: high) [0x00813d30]
    CritSec_00813d30* __thiscall Init();
};
CritSec_00813d30* CritSec_00813d30::Init() {
    InitializeCriticalSection(&m_cs);
    return this;
}
