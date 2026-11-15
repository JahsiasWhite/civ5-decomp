// c5d-model: claude-opus-5-5
// Records the current tick count as a start time, resets the elapsed counter
// and stores a duration value.

#include <windows.h>

class TickTimer
{
public:
    void Start(int duration);

private:
    char m_pad[0x4c];
    DWORD m_startTick;
    int m_elapsed;
    int m_duration;
};

void TickTimer::Start(int duration)
{
    m_startTick = GetTickCount();
    m_elapsed = 0;
    m_duration = duration;
}
