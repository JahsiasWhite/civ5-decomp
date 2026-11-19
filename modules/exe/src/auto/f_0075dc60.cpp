// Resets the level to zero and tells every child of the attached node to do the same.

#include <vector>

// src: GUESS (confidence: low)
class Child_0075dc60
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    // src: GUESS (confidence: low)
    virtual void SetValue(int kind, float value);
};

// src: GUESS (confidence: low)
struct Node_0075dc60
{
    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Child_0075dc60*> m_children;
};

// src: GUESS (confidence: low)
struct Owner_0075dc60
{
    // src: GUESS (confidence: low) [0x0075dc60]
    void ResetLevel();

    char m_pad0[0x84];
    // src: GUESS (confidence: low)
    Node_0075dc60* m_node;
    char m_pad88[0x4e8 - 0x88];
    // src: GUESS (confidence: low)
    float m_level;
};

void Owner_0075dc60::ResetLevel()
{
    Node_0075dc60* node = m_node;
    if (node)
    {
        m_level = 0.0f;
        for (std::vector<Child_0075dc60*>::iterator it = node->m_children.begin(); it != node->m_children.end(); ++it)
        {
            (*it)->SetValue(4, 0.0f);
        }
    }
}
