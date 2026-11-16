// c5d-model: Gemini 3.8 Flash
#include <windows.h>

class Event_0081abb0 {
public:
    HANDLE m_handle;
    // src: GUESS (confidence: high) [0x0081abb0]
    void __thiscall Wait();
};

void Event_0081abb0::Wait() {
    WaitForSingleObject(m_handle, INFINITE);
}
