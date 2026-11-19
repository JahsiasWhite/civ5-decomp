// Tells the first listed object to remove itself (virtual slot 4) until the
// list is empty.

#include <vector>

// src: GUESS (confidence: low)
class Member_0091c390
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    // src: GUESS (confidence: low)
    virtual void Remove();
};

// src: GUESS (confidence: low)
class Group_0091c390
{
public:
    // src: GUESS (confidence: low) [0x0091c390]
    void RemoveAll();

    // src: GUESS (confidence: low)
    std::vector<Member_0091c390*> m_members;
};

void Group_0091c390::RemoveAll()
{
    while (m_members.size() != 0)
        m_members.front()->Remove();
}
