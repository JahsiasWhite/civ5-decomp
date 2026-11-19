// src: SDK [0x009d6354]
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* event);

// src: GUESS (confidence: low) [0x0606c4a8]
void* g_event_0606c4a8;

// Signals the pending event, if any, and forgets it.
// src: GUESS (confidence: low) [0x00799cd0]
bool SignalPendingEvent_00799cd0()
{
    if (g_event_0606c4a8)
        SetEvent(g_event_0606c4a8);
    g_event_0606c4a8 = 0;
    return true;
}
