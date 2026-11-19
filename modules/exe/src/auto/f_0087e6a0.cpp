// Clears the first registration whose listener is `listener` (the entry
// stays in place with a null listener).

#include <vector>

// src: GUESS (confidence: low)
struct Registration_00918850
{
    int m_id;
    int m_flags;
    // src: GUESS (confidence: low)
    void* m_listener;
};

// src: GUESS (confidence: low)
class Registry_00918850
{
public:
    // src: GUESS (confidence: low) [0x00918850]
    void RemoveListenerB(void* listener);

    char m_pad0[0x10];
    // src: GUESS (confidence: low)
    std::vector<Registration_00918850> m_registrations;
};

void Registry_00918850::RemoveListenerB(void* listener)
{
    for (std::vector<Registration_00918850>::iterator it = m_registrations.begin();
         it != m_registrations.end(); ++it)
    {
        if (it->m_listener == listener)
        {
            it->m_listener = 0;
            return;
        }
    }
}
