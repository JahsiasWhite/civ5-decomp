// On event 2, calls the current handler's callback with a pointer to the
// event code and the handler's user data.

// src: GUESS (confidence: low)
struct Handler_005850d0
{
    // src: GUESS (confidence: low)
    void (*m_callback)(int* event, void* userData);
    // src: GUESS (confidence: low)
    void* m_userData;
    char m_pad8[0x600 - 8];
};

// src: GUESS (confidence: low) [0x01a0e400]
extern int g_currentHandler_01a0e400;
// src: GUESS (confidence: low) [0x01a0e4c0]
extern Handler_005850d0 g_handlers_01a0e4c0[];

// src: GUESS (confidence: low) [0x005850d0]
void __stdcall OnEvent_005850d0(int event)
{
    switch (event)
    {
    case 2:
        {
            Handler_005850d0* handler = &g_handlers_01a0e4c0[g_currentHandler_01a0e400];
            handler->m_callback(&event, handler->m_userData);
        }
        break;
    }
}
