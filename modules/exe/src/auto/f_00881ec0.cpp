// c5d-cflags: -/arch:SSE2
// Passes the value to every listener (virtual slot 2).

#include <vector>

// src: GUESS (confidence: low)
class Listener_0091c3f0
{
public:
    virtual void v00();
    virtual void v01();
    // src: GUESS (confidence: low)
    virtual void OnValue(float value);
};

// src: GUESS (confidence: low)
class Broadcaster_0091c3f0
{
public:
    // src: GUESS (confidence: low) [0x0091c3f0]
    void Broadcast(float value);

    // src: GUESS (confidence: low)
    std::vector<Listener_0091c3f0*> m_listeners;
};

void Broadcaster_0091c3f0::Broadcast(float value)
{
    for (std::vector<Listener_0091c3f0*>::iterator it = m_listeners.begin(); it != m_listeners.end(); ++it)
        (*it)->OnValue(value);
}
