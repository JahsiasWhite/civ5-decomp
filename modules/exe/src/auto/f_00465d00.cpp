// c5d-model: Gemini 4 Hydrogen
#include <windows.h>
class Event_0081abc0 {
public:
    HANDLE m_h;
    // src: GUESS (confidence: high) [0x0081abc0]
    int __thiscall IsSignaled();
};
int Event_0081abc0::IsSignaled() {
    return WaitForSingleObject(m_h, 0) == WAIT_OBJECT_0;
}
