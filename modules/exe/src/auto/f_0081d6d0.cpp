// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);

class Event_0081d6d0 {
public:
    void* m_handle;
    // src: GUESS (confidence: high) [0x0081d6d0]
    Event_0081d6d0();
};

Event_0081d6d0::Event_0081d6d0() {
    m_handle = CreateEventA(0, 0, 0, 0);
}
