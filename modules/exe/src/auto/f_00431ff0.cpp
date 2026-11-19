// True unless some listed child exists and isn't ready yet.

#include <list>
#include <utility>

// src: GUESS (confidence: low)
struct Child_007e9260
{
    char m_pad0[0x18];
    // src: GUESS (confidence: low)
    bool m_ready;
};

// src: GUESS (confidence: low)
class Parent_007e9260
{
public:
    // src: GUESS (confidence: low) [0x007e9260]
    bool AreChildrenReady() const;

    char m_pad0[0x1c];
    // src: GUESS (confidence: low)
    std::list<std::pair<int, Child_007e9260*> > m_children;
};

bool Parent_007e9260::AreChildrenReady() const
{
    for (std::list<std::pair<int, Child_007e9260*> >::const_iterator it = m_children.begin();
         it != m_children.end(); ++it)
    {
        if (it->second && !it->second->m_ready)
            return false;
    }
    return true;
}
